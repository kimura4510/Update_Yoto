/**
* @file Graphics.h
* @bief �`��Ɋ֌W����֐��A�萔�̐錾
*/

#ifndef DIRECT_GRAPHICS_H_
#define DIRECT_GRAPHICS_H_

#include <Windows.h>
#include <d3d9.h>

// @brief �e�N�X�`���f�[�^��T�C�Y��ێ�����\����
struct Texture
{
	LPDIRECT3DTEXTURE9 m_TextureData;	//!< �e�N�X�`���f�[�^
	float m_Width;						//!< ����
	float m_Height;						//!< �c��
};

struct CustomVertex
{
	float x;	//x���W
	float y;	//y���W
	float z;	//z���W
	float rhw;	//���Z��

	float tu;	//�e�N�X�`�����Wx
	float tv;	//�e�N�X�`�����Wy
};

class Graphics
{
public:
	/**
	* @brief Graphics�@�\�̏������֐�@n
	* �`��֘A���g�p�\�ɂ��邽�߂̏��������s���܂�@n
	* Engine.cpp��InitEngine�Ŏ��s���Ă���̂Ŏg�p�҂������Ŏg���K�v�͂���܂���
	* @param[in] window_handle �C���X�^���X�n���h��
	* @return ���������ʁA�����̏ꍇ��true
	*/
	bool InitGraphics(HWND window_handle);

	/**
	* @brief Graphics�@�\�̏I���֐�@n
	* �`��֘A�̏������I��������֐�@n
	* Engine.cpp��EndEngine�Ŏ��s���Ă���̂Ŏg�p�҂������Ŏg���K�v�͂���܂���
	*/
	void ReleaseGraphics();

	/**
	* @brief �`��J�n�֐�@n
	* �`��J�n��錾���A�o�b�N�o�b�t�@�̃N���A���s���܂�
	* @return �`��J�n�̐��ہA�����̏ꍇ��true
	*/
	bool DrawStart();

	/**
	* @brief �`��I���֐�@n
	* �`��̏I����錾���A�o�b�N�o�b�t�@�ƃt�����g�o�b�t�@�����ւ��܂�@n
	* ���̊֐��͕K��DrawStart�̌�Ɏ��s����悤�ɂ��Ă�������
	*/
	void DrawEnd();

	/**
	* @brief �e�N�X�`���쐬�֐�@n
	* �w�肳�ꂽ��񂩂�ǂݍ��݁A�e�N�X�`�����쐬���܂�
	* �J������Texture.h��LoadTexture���g�p���Ă�������
	* @return �쐬���ʁA�����̏ꍇ��true
	* @param[in] file_name �ǂݍ��ރe�N�X�`���̖��O(�p�X���܂�)
	* @param[out] texture_data �ǂݍ��܂ꂽ�e�N�X�`���𔽉f����f�[�^
	*/
	bool CreateTexture(const char* file_name, Texture* texture_data);

	/**
	* @brief �e�N�X�`���`��֐�@n
	* �w�肳�ꂽ�ʒu�Ƀe�N�X�`����`�悵�܂�@n
	* texture_data��Texture.h��GetTextureData���g�p���Ă�������
	* @param[in] x X���`����W
	* @param[in] y Y���`����W
	* @param[in] texture_data �`��Ŏg�p����e�N�X�`���̃f�[�^
	*/
	void DrawTexture(float x, float y, Texture* texture_data);

	//�V���O���g���f�U�C���p�^�[��
public:
	/**
	* @brief �C���X�^���X�����֐�@n
	* Graphics�N���X�̃C���X�^���X�𐶐�����֐��ł�@n
	*/
	static void CreateGraphicInstance();

	/**
	* @brief �C���X�^���X�j���֐�@n
	* Graphics�N���X�̃C���X�^���X��j������֐��ł�@n
	*/
	static void DestroyGraphicInstance();

	/**
	* @brief �C���X�^���X�m�F�֐�@n
	* Graphics�N���X�̃C���X�^���X�̗L�����m�F����֐��ł�@n
	*/
	static bool IsGraphicInstance_NULL();
	
	/**
	* @brief �C���X�^���X�擾�֐�@n
	* Graphics�N���X�̃C���X�^���X���擾����֐��ł�@n
	*/
	static Graphics* GetGraphicInstance();

private:
	//�O���[�o���ϐ�
	LPDIRECT3D9 g_D3DInterface;		//DirectGraphics�C���^�[�t�F�[�X
	LPDIRECT3DDEVICE9 g_D3DDevice;		//DirectGraphics�f�o�C�X

	//�V���O���g��
	//�R���X�g���N�^
	Graphics();
	~Graphics();		//�f�X�g���N�^
	static Graphics* p_GraphicInstance;		//Graphics�̃C���X�^���X
};



#endif