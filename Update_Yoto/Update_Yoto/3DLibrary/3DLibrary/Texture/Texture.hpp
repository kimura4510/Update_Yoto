/**
* @file Texture.h
* @brief �e�N�X�`���̓ǂݍ��݁A�J���ȂǁA�e�N�X�`���Ɋ֌W����֐��A�萔�̐錾
*/
#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "../Engine/Graphics.hpp"
#include "../Scene/I_SceneChanger.hpp"
#include <vector>
#include <map>

class cTexture
{
public:
	/**
	* @brief �e�N�X�`���f�[�^�̏������֐�@n
	* �Q�[���Ŏg�p����e�N�X�`���f�[�^��ۑ��ł���悤�ɂ��܂�
	*/
	void InitTexture();

	/**
	* @brief �J�e�S���[�P�ʂ̃e�N�X�`������֐�@n
	* �����Ŏw�肳�ꂽ�J�e�S���[�̃e�N�X�`����S�ĉ�����܂�
	* @param[in] category_id �������J�e�S���[
	*/
	void ReleaseCategoryTexture(int category_id);

	/**
	* @brief �S�Ẵe�N�X�`���̉���֐�@n
	* �ǂݍ���ł���S�Ẵe�N�X�`����������܂�
	* ���̊֐���EndEngine�Ŏ��s���Ă�̂ŁA�J���������s����K�v�͂���܂���
	*/
	void AllReleaseTexture();

	/**
	* @brief �e�N�X�`���̓ǂݍ��݊֐�@n
	* �w�肵���p�X�̃e�N�X�`����ǂݍ��݁A�J�e�S���ɓo�^���܂�
	* return �ǂݍ��݌��ʁA�����̏ꍇ��true
	* @param[in] file_name �ǂݍ��ރe�N�X�`���̖��O(�p�X���܂�)
	* @param[in] category_id �o�^����J�e�S���[
	* @param[in] texture_id �J�e�S���[���̃e�N�X�`��ID
	*/
	bool LoadTexture(const char* file_name);

	/**
	* @brief �e�N�X�`���f�[�^�̎擾�֐�@n
	* �w�肳�ꂽ�J�e�S���[�̃e�N�X�`���f�[�^���擾���܂�
	* @return �e�N�X�`���f�[�^�A���s�����ꍇ��nullptr
	* @param[in] category_id �擾�������e�N�X�`���̃J�e�S��
	* @param[in] texture_id �擾�������e�N�X�`����ID
	*/
	Texture* GetTexture(const char* file_name);

	//�V���O���g���f�U�C���p�^�[��
public:
	/**
	* @brief �C���X�^���X�����֐�@n
	* Texture�N���X�̃C���X�^���X�𐶐�����֐��ł�@n
	*/
	static void CreateTextureInstance();

	/**
	* @brief �C���X�^���X�j���֐�@n
	* Texture�N���X�̃C���X�^���X��j������֐��ł�@n
	*/
	static void DestroyTextureInstance();

	/**
	* @brief �C���X�^���X�m�F�֐�@n
	* Texture�N���X�̃C���X�^���X�̗L�����m�F����֐��ł�@n
	*/
	static bool IsTextureInstance_NULL();

	/**
	* @brief �C���X�^���X�擾�֐�@n
	* Texture�N���X�̃C���X�^���X���擾����֐��ł�@n
	*/
	static cTexture* GetTextureInstance();


private:
	//�V���O���g��
//�R���X�g���N�^
	cTexture();
	//�f�X�g���N�^
	~cTexture();
	//Texture�̃C���X�^���X
	static cTexture* p_TextureInstance;

	//�J�e�S�����Ƃ̃e�N�X�`���ۑ��p�z��
	std::vector<Texture> m_TextureData;

	//�J�e�S���̃e�N�X�`���ő�T�C�Y�̔z��
	std::map<char, int> m_TextureList;
};

#endif