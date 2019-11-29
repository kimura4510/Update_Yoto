/**
* @file Graphics.h
* @bief �`��Ɋ֌W����֐��A�萔�̐錾
*/

#ifndef DIRECT_GRAPHICS_H_
#define DIRECT_GRAPHICS_H_

#include <Windows.h>
#include <d3d9.h>

//!< @brief �e�N�X�`���f�[�^��T�C�Y��ێ�����\����
struct Texture
{
	LPDIRECT3DTEXTURE9 m_TextureData;	//!< �e�N�X�`���f�[�^
	float m_Width;						//!< ����
	float m_Height;						//!< �c��
};

//!< @biref 3D�`��p���_���W�ۑ��\����
struct CustomVertex3D
{
	float m_x;
	float m_y;
	float m_z;
	D3DCOLOR color;
	float tu, tv;
};

//!< @brief 2D�`��p���_���W�ۑ��\����
struct CustomVertex
{
	float x;	//x���W
	float y;	//y���W
	float z;	//z���W
	float rhw;	//���Z��

	float tu;	//�e�N�X�`�����Wx
	float tv;	//�e�N�X�`�����Wy
};

//!< @brief 3D�`��̂��߂ɕK�v�ȃp�����[�^��ݒ肷��f�[�^�\����
struct DrawingData3D
{
	float m_x;	//x���W
	float m_y;	//y���W
	float m_z;	//z���W

	float m_tu;	//u�e�N�X�`�����W
	float m_tv;	//v�e�N�X�`�����W

	float m_width;	//��
	float m_height;	//����

	DWORD m_color;	//color

	float m_rotx;	//x��]
	float m_roty;	//y��]
	float m_rotz;	//z��]

	float m_scalex;	//�g�kx
	float m_scaley;	//�g�ky
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

	/**
	* @brief �����摜�`��֐�
	* texture_data��Texture.h��GetTextureData���g�p���Ă�������
	* @param[in] x X���`����W
	* @param[in] y Y���`����W
	* @param[in] texture_data �`��Ŏg�p����e�N�X�`���̃f�[�^
	* @param[in] tu �e�N�X�`��U���W�̕�
	* @param[in] tv �e�N�X�`��V���W�̍���
	* @param[in] spriteX �`�悵�����X�v���C�g�̕�
	* @param[in] spriteY �`�悵�����X�v���C�g�̍���
	* @param[in] spriteNumX �`�悵�����X�v���C�g�������牽�Ԗڂ�
	* @param[in] spriteNumY �`�悵�����X�v���C�g���ォ�牽�Ԗڂ�
	*/
	void DrawIntegratedImage(float x, float y, Texture* texture_data, float tu, float tv, float spriteX, float spriteY, int spriteNumX, int spriteNumY);

	/**
	* @biref 3D�`��֐�
	* �w�肳�ꂽ�ʒu��3D�|���S����`�悵�܂�@n
	* texture_data��File.h��GetTextureData���g�p���Ă�������
	* @param[in] v3D ���W�Ȃǂ̏��Q
	* @param[in] texture_data �`��Ŏg�p����e�N�X�`���̃f�[�^
	*/
	void Draw3D(const DrawingData3D& v3D, Texture* texture_data);

	/**
	* @biref �����摜�`��֐�3Dversion
	* texture_data��Texture.h��GetTextureData���g�p���Ă�������
	* @param[in] x X���`����W
	* @param[in] y Y���`����W
	* @param[in] texture_data �`��Ŏg�p����e�N�X�`���̃f�[�^
	* @param[in] tu �e�N�X�`��U���W�̕�
	* @param[in] tv �e�N�X�`��V���W�̍���
	* @param[in] spriteX �`�悵�����X�v���C�g�̕�
	* @param[in] spriteY �`�悵�����X�v���C�g�̍���
	* @param[in] spriteNumX �`�悵�����X�v���C�g�������牽�Ԗڂ�
	* @param[in] spriteNumY �`�悵�����X�v���C�g���ォ�牽�Ԗڂ�
	*/
	void DrawIntegratedImage3D(const DrawingData3D& drawdata, Texture* texture_data, float tu, float tv, float spriteX, float spriteY, int spriteNumX, int spriteNumY);

	/**
	* @biref �����摜�`��֐�3Dversion
	* texture_data��Texture.h��GetTextureData���g�p���Ă�������
	* @param[in] x X���`����W
	* @param[in] y Y���`����W
	* @param[in] texture_data �`��Ŏg�p����e�N�X�`���̃f�[�^
	* @param[in] tu �e�N�X�`��U���W�̕�
	* @param[in] tv �e�N�X�`��V���W�̍���
	* @param[in] spriteX �`�悵�����X�v���C�g�̕�
	* @param[in] spriteY �`�悵�����X�v���C�g�̍���
	* @param[in] spriteNumX �`�悵�����X�v���C�g�������牽�Ԗڂ�
	* @param[in] spriteNumY �`�悵�����X�v���C�g���ォ�牽�Ԗڂ�
	*/
	void DrawBillboard(const DrawingData3D& drawdata, Texture* texture_data, float tu, float tv, float spriteX, float spriteY, int spriteNumX, int spriteNumY);

	//�J�����p�̊֐�
	bool SetView(const D3DMATRIX& matView) const;
	void GetViewport_Camera(D3DVIEWPORT9* vp);
	bool SetMatProj(const D3DMATRIX& matProj) const;

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

	//�V���O���g��
//�R���X�g���N�^
	Graphics();
//�f�X�g���N�^
	~Graphics();

private:
	//�O���[�o���ϐ�
	LPDIRECT3D9 g_D3DInterface;		//DirectGraphics�C���^�[�t�F�[�X
	LPDIRECT3DDEVICE9 g_D3DDevice;		//DirectGraphics�f�o�C�X


	static Graphics* p_GraphicInstance;		//Graphics�̃C���X�^���X
};

#endif