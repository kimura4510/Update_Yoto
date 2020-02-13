#include "Sound.hpp"
#include <mmsystem.h>

#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "dsound.lib")
#pragma comment (lib, "winmm.lib")

bool Sound::InitSound(HWND hw)
{
	//!< DirectSound�̐���
	if (FAILED(DirectSoundCreate8(NULL, &m_pSound, NULL)))
	{
		return false;
	}

	//!< �������x���̐ݒ�
	if (FAILED(m_pSound->SetCooperativeLevel(hw, DSSCL_NORMAL)))
	{
		return false;
		m_pSound->Release();
		m_pSound = nullptr;
	}

	return true;
}


void Sound::ReleaseSound()
{
	for (auto& sound : m_pSoundData)
	{
		sound.second->Stop();
		sound.second->Release();
	}

	m_pSoundData.clear();

	m_pSound->Release();
	m_pSound = nullptr;
}

bool Sound::LoadSound(std::string file_name, std::string key_name)
{
	//!< Windows�}���`���f�B�AAPI�̃n���h��
	HMMIO hmmio = nullptr;

	//!< wave�t�@�C�����̃w�b�_���̓ǂݍ��݂Ɗm�F
	hmmio = mmioOpenA((LPSTR)file_name.c_str(), nullptr, MMIO_ALLOCBUF | MMIO_READ);

	//!< RIFF�`�����N������
	MMCKINFO riffInfo;
	riffInfo.fccType = mmioFOURCC('W', 'A', 'V', 'E');
	if (MMSYSERR_NOERROR != mmioDescend(hmmio, &riffInfo, nullptr, MMIO_FINDRIFF))
	{
		mmioClose(hmmio, 0);
		return false;
	}

	//!< �t�H�[�}�b�g�`�����N�̌����Ɠǂݍ���
	MMCKINFO fmtInfo;
	fmtInfo.ckid = mmioFOURCC('f', 'm', 't', ' ');
	if (MMSYSERR_NOERROR != mmioDescend(hmmio, &fmtInfo, &riffInfo, MMIO_FINDCHUNK))
	{
		mmioClose(hmmio, 0);
		return false;
	}

	WAVEFORMATEX wavfmt;
	if (mmioRead(hmmio, reinterpret_cast<HPSTR>(&wavfmt), fmtInfo.cksize) != fmtInfo.cksize)
	{
		mmioClose(hmmio, 0);
		return false;
	}

	//!< �}���`�`�����l���̊m�F
	if (wavfmt.wFormatTag != WAVE_FORMAT_PCM)
	{
		mmioClose(hmmio, 0);
		return false;
	}

	//!< �f�[�^�`�����N�̌����Ɠǂݍ���
	mmioAscend(hmmio, &fmtInfo, 0);
	MMCKINFO dataCK;
	dataCK.ckid = mmioFOURCC('d', 'a', 't', 'a');
	if (MMSYSERR_NOERROR != mmioDescend(hmmio, &dataCK, &riffInfo, MMIO_FINDCHUNK))
	{
		mmioClose(hmmio, 0);
		return false;
	}

	//!< �Z�J���_���E�o�b�t�@�̍쐬
	DSBUFFERDESC DSBufDesc;
	ZeroMemory(&DSBufDesc, sizeof(DSBUFFERDESC));
	DSBufDesc.dwSize = sizeof(DSBUFFERDESC);
	DSBufDesc.dwFlags = DSBCAPS_CTRLPAN | DSBCAPS_CTRLFREQUENCY;
	DSBufDesc.dwBufferBytes = dataCK.cksize;
	DSBufDesc.guid3DAlgorithm = DS3DALG_DEFAULT;
	DSBufDesc.lpwfxFormat = &wavfmt;

	LPDIRECTSOUNDBUFFER pDSBuf;
	if (FAILED(m_pSound->CreateSoundBuffer(&DSBufDesc, &pDSBuf, NULL)))
	{
		return false;
	}
	m_pSoundData.emplace(key_name, nullptr);
	if (FAILED(pDSBuf->QueryInterface(IID_IDirectSoundBuffer8, (LPVOID*)&m_pSoundData.at(key_name))))
	{
		return false;
	}

	//!< wave�f�[�^�̏�������
	LPVOID pBuf[2] = { nullptr };
	DWORD Bufsize[2] = { 0 };
	if (FAILED(m_pSoundData[key_name]->Lock(0, dataCK.cksize, &pBuf[0], &Bufsize[0], &pBuf[1], &Bufsize[1], 0)))
	{
		m_pSoundData.erase(key_name);
		return false;
	}

	for (int i = 0; i < 2; i++)
	{
		if (pBuf[i] == nullptr)
		{
			continue;
		}
		mmioRead(hmmio, reinterpret_cast<HPSTR>(pBuf[i]), Bufsize[i]);
	}

	m_pSoundData[key_name]->Unlock(&pBuf[0], Bufsize[0], &pBuf[1], Bufsize[1]);

	mmioClose(hmmio, 0);

	return true;
}

void Sound::Play(std::string key_)
{
	auto it = m_pSoundData.find(key_);

	if (it == m_pSoundData.end())
	{
		return;
	}

	bool is_loop = true;
	int loop_bit = is_loop == true ? 1 : 0;
	m_pSoundData[key_]->Play(NULL, 0, DSBPLAY_LOOPING & loop_bit);
}

void Sound::Stop(std::string key_)
{
	m_pSoundData[key_]->Stop();
}