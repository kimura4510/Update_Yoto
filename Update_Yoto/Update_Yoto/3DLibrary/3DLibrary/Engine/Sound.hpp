#ifndef SOUND_H_
#define SOUND_H_

class Sound
{
public:
	/**
	* @brief �T�E���h�������֐�
	* DirectSound���g�p�\�ɂ��邽�ߏ��������s���܂�
	* @return �����̏ꍇ��true�A���s�����ꍇ��false
	*/
	bool InitSound(HWND hw);

	/**
	* @brief �v���C�}���E�o�b�t�@�̍쐬�֐�
	* @return �쐬�ł����ꍇ��true�A���s�����ꍇ��false
	*/
	bool CreatePrimaryBuffer();

	/**
	* @brief wave�f�[�^�̓ǂݍ��݊֐�
	* �w�肵���p�X��wave�f�[�^���Z�J���_���E�o�b�t�@�ɓǂݍ��݂܂�
	* @return ���������ꍇ��true�A�����łȂ��Ȃ�false
	* @param[in] file_name �ǂݍ��ރp�X���܂ރt�@�C����
	*/
	bool LoadSound(const char* file_name);

public:
	//�V���O���g��
	/**
	* @biref �C���X�^���X�쐬�֐�
	*/
	static void CreateInstance()
	{
		if (IsInstanceNULL() == true)
		{
			p_SoundInstance = new Sound;
		}
	}

	/**
	* @brief �C���X�^���X�j���֐�
	*/
	static void DestroyInstance()
	{
		if (IsInstanceNULL() == false)
		{
			delete p_SoundInstance;
			p_SoundInstance = NULL;
		}
	}

	/**
	* @brief �C���X�^���XNULL�m�F�֐�
	* �C���X�^���X��null���m�F����֐��ł�
	* @return null�̏ꍇtrue�A�����łȂ��Ȃ�false
	*/
	static bool IsInstanceNULL()
	{
		return p_SoundInstance == NULL;
	}

	/**
	* @biref �C���X�^���X�擾�֐�
	*/
	static Sound* GetInstance()
	{
		return p_SoundInstance;
	}

private:
	/**
	* @brief �Z�J���_���E�o�b�t�@�̍쐬�֐�
	* @return �쐬�ł����ꍇ��true�A���s�����ꍇ��false
	* ���̊֐���LoadSound���ŏ�������Ă��邽�߁A�g�p����K�v�͂���܂���
	*/
	bool CreateSecondaryBuffer(MMCKINFO sound_data);

private:
	Sound() { }
	~Sound() { }
	LPDIRECTSOUND8 m_pSound;
	LPDIRECTSOUNDBUFFER m_pPrimary;
	LPDIRECTSOUNDBUFFER8 m_pSoundData;

	static Sound* p_SoundInstance;
};


#endif