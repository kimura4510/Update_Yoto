/**
* @file Texture.h
* @brief �e�N�X�`���̓ǂݍ��݁A�J���ȂǁA�e�N�X�`���Ɋ֌W����֐��A�萔�̐錾
*/
#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "../Engine/Graphics.hpp"
#include "Scene.hpp"

// @brief �^�C�g���p�̃e�N�X�`�����X�g
enum TitleCategoryTextureList
{
	TitleBgTex,				//!< �w�i
	TitleObject,			//!< �I���A�C�R��
	TitleTextureMax,		//!< ���X�g�ő吔
};

// @brief �Q�[���{�җp�e�N�X�`�����X�g
enum GameCategoryTextureList
{
	GameBgTex,			//!< �w�i
	GameTextureMax,		//!< ���X�g�ő吔
};

// @brief �w���v�p�e�X�N�`�����X�g
enum HelpCategoryTextureList
{
	Help1,				//!< �w�i
	HelpTextureMax,			//!< ���X�g�ő吔
};

#define TEXTURE_CATEGORY_TITLE (SceneID::TitleScene)			//!< �^�C�g���J�e�S���[
#define TEXTURE_CATEGORY_HELP (SceneID::HelpScene)				//!< �w���v�J�e�S���[
#define TEXTURE_CATEGORY_GAME (SceneID::GameScene)				//!< �Q�[���{�҃J�e�S���[
#define TEXTURE_CATEGORY_GAMECLEAR (SceneID::GameClearScene)	//!< �Q�[���N���A�\�J�e�S���[
#define TEXTURE_CATEGORY_GAMEOVER (SceneID::GameOverScene)		//!< �Q�[���I�[�o�[�J�e�S���[
#define MAX_TEXTURE_CATEGORY (SceneID::SceneIDMax)				//!< �J�e�S���[�ő�

class TEXTURE
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
	bool LoadTexture(const char* file_name, int category_id, int texture_id);

	/**
	* @brief �e�N�X�`���f�[�^�̎擾�֐�@n
	* �w�肳�ꂽ�J�e�S���[�̃e�N�X�`���f�[�^���擾���܂�
	* @return �e�N�X�`���f�[�^�A���s�����ꍇ��nullptr
	* @param[in] category_id �擾�������e�N�X�`���̃J�e�S��
	* @param[in] texture_id �擾�������e�N�X�`����ID
	*/
	Texture* GetTexture(int category_id, int texture_id);

private:
	//�J�e�S�����Ƃ̃e�N�X�`���ۑ��p�z��
	Texture** g_TextureList[6] = { nullptr };

	//�J�e�S���̃e�N�X�`���ő�T�C�Y�̔z��
	int TextureCategorySize[3] = {
		TitleCategoryTextureList::TitleTextureMax,
		HelpCategoryTextureList::HelpTextureMax,
		GameCategoryTextureList::GameTextureMax,
	};

	bool IsCategoryIDCheck(int category_id, int texture_id);

};

#endif