#include <dsound.h>
#include "Sound.hpp"
#include <mmsystem.h>

#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "dsound.lib")
#pragma comment (lib, "winmm.lib")

Sound* Sound::p_SoundInstance = NULL;

bool Sound::InitSound(HWND hw)
{
	HRESULT hr = DirectSoundCreate8(NULL, &m_pSound, NULL);
	if (FAILED(hr))
	{
		return false;
	}

	hr = m_pSound->SetCooperativeLevel(hw, DSSCL_PRIORITY);
	if (FAILED(hr))
	{
		return false;
	}
}

bool Sound::CreatePrimaryBuffer()
{
	HRESULT hr;

	// DSBUFFERDESC�\���̂�ݒ�
	DSBUFFERDESC dsdesc;
	ZeroMemory(&dsdesc, sizeof(DSBUFFERDESC));
	dsdesc.dwSize = sizeof(DSBUFFERDESC);

	// PrimaryBuffer���w��
	dsdesc.dwFlags = DSBCAPS_CTRLVOLUME | DSBCAPS_PRIMARYBUFFER;
	dsdesc.dwBufferBytes = 0;
	dsdesc.lpwfxFormat = NULL;

	//Buffer�̍쐬
	hr = m_pSound->CreateSoundBuffer(&dsdesc, &m_pPrimary, NULL);
	if (FAILED(hr))
	{
		return false;
	}

	//PrimaryBuffer�̃t�H�[�}�b�g�̐ݒ�
	WAVEFORMATEX wf;
	ZeroMemory(&wf, sizeof(PCMWAVEFORMAT));
	wf.wFormatTag = WAVE_FORMAT_PCM;
	wf.nChannels = 2;
	wf.nSamplesPerSec = 44100;
	wf.wBitsPerSample = 16;
	wf.nBlockAlign = wf.nChannels * wf.wBitsPerSample / 8;
	wf.nAvgBytesPerSec = wf.nSamplesPerSec * wf.nBlockAlign;
	hr = m_pPrimary->SetFormat(&wf);
	if (FAILED(hr))
	{
		return false;
	}

	return true;
}

bool Sound::CreateSecondaryBuffer(MMCKINFO sound_data)
{
	WAVEFORMATEX wf;
	DSBUFFERDESC dsdesc;
	HRESULT hr;

	// WAVEFORMATEX�̐ݒ�
	ZeroMemory(&wf, sizeof(WAVEFORMATEX));
	wf.wFormatTag = WAVE_FORMAT_PCM;
	wf.nChannels = 2;
	wf.nSamplesPerSec = 44100;
	wf.wBitsPerSample = 16;
	wf.nBlockAlign = wf.nChannels * wf.wBitsPerSample / 8;
	wf.nAvgBytesPerSec = wf.nSamplesPerSec * wf.nBlockAlign;

	// DSBUFFERDESC�\���̂�ݒ�
	ZeroMemory(&dsdesc, sizeof(DSBUFFERDESC));
	dsdesc.dwSize = sizeof(DSBUFFERDESC);
	
	//�T�E���h�E�o�b�t�@�̍쐬
	dsdesc.dwFlags = 0;
	dsdesc.dwBufferBytes = sound_data.cksize;
	dsdesc.lpwfxFormat = &wf;
	dsdesc.guid3DAlgorithm = DS3DALG_DEFAULT;
	LPDIRECTSOUNDBUFFER pDSB;
	hr = m_pSound->CreateSoundBuffer(&dsdesc, &pDSB, NULL);
	if (FAILED(hr))
	{
		return false;
	}
	hr = pDSB->QueryInterface(IID_IDirectSoundBuffer8, (LPVOID*)m_pSoundData);
	pDSB->Release();
	if (FAILED(hr))
	{
		return false;
	}
	return true;
}

bool Sound::LoadSound(const char* file_name)
{
	LPSTR file = const_cast<char*>(file_name);
	HMMIO hmmio = NULL;
	MMIOINFO mmioInfo;

	// wavefile�̃I�[�v��
	memset(&mmioInfo, 0, sizeof(MMIOINFO));
	hmmio = mmioOpen(file, &mmioInfo, MMIO_READ);
	if (!hmmio)
	{
		return false;
	}

	// RIFF�`�����N����
	MMRESULT mmRes;
	MMCKINFO riffChunk;
	riffChunk.fccType = mmioFOURCC('W', 'A', 'V', 'E');
	mmRes = mmioDescend(hmmio, &riffChunk, NULL, MMIO_FINDRIFF);
	if (mmRes != MMSYSERR_NOERROR)
	{
		mmioClose(hmmio, 0);
		return false;
	}

	// FORMAT�`�����N����
	MMCKINFO formatChunk;
	formatChunk.ckid = mmioFOURCC('f', 'm', 't', ' ');
	mmRes = mmioDescend(hmmio, &formatChunk, &riffChunk, MMIO_FINDCHUNK);
	if (mmRes != MMSYSERR_NOERROR)
	{
		mmioClose(hmmio, 0);
		return false;
	}

	// WAVEFORMATEX�\���̊i�[
	LPWAVEFORMATEX wf;
	DWORD fmsize = formatChunk.cksize;
	DWORD size = mmioRead(hmmio, (HPSTR)&wf, fmsize);
	if (size != fmsize)
	{
		mmioClose(hmmio, 0);
		return false;
	}
	mmioAscend(hmmio, &formatChunk, 0);

	// DATA�`�����N����
	MMCKINFO dataChunk;
	dataChunk.ckid = mmioFOURCC('d', 'a', 't', 'a');
	mmRes = mmioDescend(hmmio, &dataChunk, &riffChunk, MMIO_FINDCHUNK);
	if (mmRes != MMSYSERR_NOERROR)
	{
		mmioClose(hmmio, 0);
		return false;
	}

	const DWORD readsize = 1024;
	char* pData = new char[(int)dataChunk.cksize];
	size = mmioRead(hmmio, (HPSTR)pData, dataChunk.cksize);
	if (size != dataChunk.cksize)
	{
		delete[] pData;
		return false;
	}

	mmioClose(hmmio, 0);

}