#ifndef SOUND_H_
#define SOUND_H_

#include <dsound.h>
#include <unordered_map>
#include <string>

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
	* @brief wave�f�[�^�̓ǂݍ��݊֐�
	* �w�肵���p�X��wave�f�[�^���Z�J���_���E�o�b�t�@�ɓǂݍ��݂܂�
	* @return ���������ꍇ��true�A�����łȂ��Ȃ�false
	* @param[in] file_name �ǂݍ��ރp�X���܂ރt�@�C����
	* @param[in] key_name �ǂݍ��ރf�[�^���Ǘ�����L�[
	*/
	bool LoadSound(std::string file_name, std::string key_name);

	/**
	* @brief �T�E���h�J���֐�
	* �ǂݍ��񂾃f�[�^��DirectSound�̉�����s���܂�
	*/
	void ReleaseSound();

	/**
	* @brief �T�E���h�Đ��֐�
	* �w�肵���Z�J���_���E�o�b�t�@�̃T�E���h���Đ����܂�
	* @param[in] key_ �Đ��������T�E���h�̃L�[
	*/
	void Play(std::string key_);

	/**
	* @brief �T�E���h��~�֐�
	* �w�肵���Z�J���_���E�o�b�t�@�̃T�E���h���~���܂�
	* @param[in] key_ ��~�������T�E���h�̃L�[
	*/
	void Stop(std::string key_);

	//�V���O���g��
	/**
	* @brief �C���X�^���X�����֐�@n
	* �C���X�^���X�𐶐�����֐��ł�@n
	*/
	static void CreateInputInstance()
	{
		if (IsInputInstance_NULL() == true)
		{
			p_Instance = new Sound;
		}
	}

	/**
	* @brief �C���X�^���X�j���֐�@n
	* �C���X�^���X��j������֐��ł�@n
	*/
	static void DestroyInputInstance()
	{
		if (IsInputInstance_NULL() == false)
		{
			delete p_Instance;
			p_Instance = nullptr;
		}
	}

	/**
	* @brief �C���X�^���X�m�F�֐�@n
	* �C���X�^���X�̗L�����m�F����֐��ł�@n
	*/
	static bool IsInputInstance_NULL()
	{
		return p_Instance == nullptr;
	}

	/**
	* @brief �C���X�^���X�擾�֐�@n
	* �C���X�^���X���擾����֐��ł�@n
	*/
	static Sound* GetInputInstance()
	{
		return p_Instance;
	}
private:
	Sound() : m_pSound(nullptr) { }		//!< �R���X�g���N�^
	~Sound() { }						//!< �f�X�g���N�^

private:
	LPDIRECTSOUND8 m_pSound;
	std::unordered_map <std::string, LPDIRECTSOUNDBUFFER8> m_pSoundData;

	static Sound* p_Instance;
};



#endif