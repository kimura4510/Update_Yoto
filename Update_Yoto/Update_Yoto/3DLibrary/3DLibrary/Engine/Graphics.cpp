#include "Graphics.hpp"
#include <d3d9.h>
#include <d3dx9.h>
#include "../Size.hpp"

// �ÓI���C�u����
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

Graphics* Graphics::p_GraphicInstance = NULL;

bool Graphics::InitGraphics(HWND hwindow)
{
	D3DPRESENT_PARAMETERS pres_param;

	g_D3DInterface = Direct3DCreate9(D3D_SDK_VERSION);
	if (g_D3DInterface == NULL)
	{
		return false;
	}

	ZeroMemory(&pres_param, sizeof(D3DPRESENT_PARAMETERS));

	pres_param.BackBufferCount = 1;
	pres_param.BackBufferFormat = D3DFMT_UNKNOWN;
	pres_param.Windowed = true;
	pres_param.SwapEffect = D3DSWAPEFFECT_DISCARD;
	pres_param.BackBufferHeight = 1080;
	pres_param.BackBufferWidth = 1920;

	if (FAILED(g_D3DInterface->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hwindow,
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
		&pres_param,
		&g_D3DDevice)))
	{
		return false;
	}

	D3DVIEWPORT9 ViewPort;

	ViewPort.X = 0;
	ViewPort.Y = 0;
	ViewPort.Width = pres_param.BackBufferWidth;
	ViewPort.Height = pres_param.BackBufferHeight;
	ViewPort.MinZ = 0.0f;
	ViewPort.MaxZ = 1.0f;

	if (FAILED(g_D3DDevice->SetViewport(&ViewPort)))
	{
		return false;
	}

	return true;
}

void Graphics::ReleaseGraphics()
{
	g_D3DDevice->Release();
	g_D3DInterface->Release();
}

bool Graphics::DrawStart()
{
	g_D3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 0.0f, 0);

	g_D3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_D3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_D3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	if (D3D_OK == g_D3DDevice->BeginScene())
	{
		return true;
	}

	return false;
}

void Graphics::DrawEnd()
{
	g_D3DDevice->EndScene();
	g_D3DDevice->Present(NULL, NULL, NULL, NULL);
}

void Graphics::DrawTexture(float x, float y, Texture* texture_data)
{
	CustomVertex TriStr[] =
	{
		{x, y, 0.0f, 1.0f, 0.0f, 0.0f}, //left-top
		{x + texture_data->m_Width, y, 0.0f, 1.0f, 1.0f, 0.0f}, //right-top
		{x, y + texture_data->m_Height, 0.0f, 1.0f, 0.0f, 1.0f},//left-bottom
		{x + texture_data->m_Width, y + texture_data->m_Height, 0.0f, 1.0f, 1.0f, 1.0f},//right-bottom
	};

	//���_�\���̎w��
	g_D3DDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_TEX1);
	g_D3DDevice->SetTexture(0, texture_data->m_TextureData);
	g_D3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,
		2,
		TriStr,
		sizeof(CustomVertex));
}

void Graphics::DrawIntegratedImage(float x, float y, Texture* texture_data, float tu, float tv, float spriteX, float spriteY, int spriteNumX, int spriteNumY)
{
	int tmpX = spriteNumX - 1;
	int tmpY = spriteNumY - 1;
	CustomVertex TriStr[] =
	{
		{x, y, 0.0f, 1.0f, tu * tmpX, tv * tmpY},
		{x + spriteX, y, 0.0f, 1.0f, tu * spriteNumX, tv * tmpY},
		{x, y + spriteY, 0.0f, 1.0f, tu * tmpX, tv * spriteNumY},
		{x + spriteX, y + spriteNumY, 0.0f, 1.0f, tu * spriteNumX, tv * spriteNumY}
	};

	//���_�\���̎w��
	g_D3DDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_TEX1);
	g_D3DDevice->SetTexture(0, texture_data->m_TextureData);
	g_D3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,
		2,
		TriStr,
		sizeof(CustomVertex));
}

void Graphics::Draw3D(const Vertex3D& v3d, Texture* texture_data)
{
	// �|���S���̃��[�J�����W�̈ʒu���w�� start
	CustomVertex3D v[4];
	v[0].color = D3DCOLOR_ARGB(255, 255, 255, 255);
	v[1].color = D3DCOLOR_ARGB(255, 255, 255, 255);
	v[2].color = D3DCOLOR_ARGB(255, 255, 255, 255);
	v[3].color = D3DCOLOR_ARGB(255, 255, 255, 255);
	v[0].m_x = v3d.m_x; v[0].m_y = v3d.m_y; v[0].m_z = v3d.m_z;
	v[0].tu = 0.0f;	v[0].tv = 0.0f;
	v[1].m_x = v3d.m_x + v3d.m_width; v[1].m_y = v3d.m_y; v[1].m_z = v3d.m_z;
	v[1].tu = 1.0f;	v[1].tv = 0.0f;
	v[2].m_x = v3d.m_x; v[2].m_y = v3d.m_y + v3d.m_height; v[2].m_z = v3d.m_z;
	v[2].tu = 0.0f;	v[2].tv = 1.0f;
	v[3].m_x = v3d.m_x + v3d.m_width; v[3].m_y = v3d.m_y + v3d.m_height; v[3].m_z = v3d.m_z;	
	v[3].tu = 1.0f;	v[3].tv = 1.0;
	// �|���S���̃��[�J�����W�̈ʒu���w�� end

	//���[���h���W�ϊ��p�̍s��̎Z�o start
	D3DXMATRIX mat_world, mat_trans, mat_rot, mat_rotx, mat_roty, mat_rotz, mat_scale;
	D3DXMatrixIdentity(&mat_world);
	D3DXMatrixIdentity(&mat_rot);
	D3DXMatrixIdentity(&mat_trans);
	D3DXMatrixIdentity(&mat_scale);

	// �ړ�
	D3DXMatrixTranslation(&mat_trans, 0.0f, 0.0f, 10.0f);

	// ��]
	D3DXMatrixRotationX(&mat_rotx, D3DXToRadian(v3d.m_rotx));
	D3DXMatrixRotationY(&mat_roty, D3DXToRadian(v3d.m_roty));
	D3DXMatrixRotationZ(&mat_rotz, D3DXToRadian(v3d.m_rotz));

	D3DXMatrixMultiply(&mat_rot, &mat_rot, &mat_roty);
	D3DXMatrixMultiply(&mat_rot, &mat_rot, &mat_rotx);
	D3DXMatrixMultiply(&mat_rot, &mat_rot, &mat_rotz);

	// �g��
	D3DXMatrixScaling(&mat_scale, v3d.m_scalex, v3d.m_scaley, 1.0f);

	// �|�����킹(�g�k * ��] * �ړ�)
	mat_world *= mat_scale * mat_rot * mat_trans;

	g_D3DDevice->SetTransform(D3DTS_WORLD, &mat_world);
	//���[���h���W�ϊ��p�̍s��̎Z�o end

	g_D3DDevice->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	g_D3DDevice->SetTexture(0, texture_data->m_TextureData);

	g_D3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, v, sizeof(CustomVertex3D));

}

bool Graphics::CreateTexture(const char* file_name, Texture* texture_data)
{
	Size size;
	D3DXIMAGE_INFO info;

	D3DXGetImageInfoFromFileA(file_name, &info);

	if (FAILED(D3DXCreateTextureFromFileExA(g_D3DDevice,
		file_name,
		info.Width,
		info.Height,
		1,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0x0000ff00,
		nullptr,
		nullptr,
		&texture_data->m_TextureData)))
	{
		return false;
	}
	else
	{
		D3DSURFACE_DESC desc;

		if (FAILED(texture_data->m_TextureData->GetLevelDesc(0, &desc)))
		{
			texture_data->m_TextureData->Release();
			texture_data->m_TextureData = NULL;
			return false;
		}
		texture_data->m_Width = (float)desc.Width;
		texture_data->m_Height = (float)desc.Height;
	}
	return true;
}


bool Graphics::SetView(const D3DMATRIX& matView) const
{
	return g_D3DDevice->SetTransform(D3DTS_VIEW, &matView);
}

void Graphics::GetViewport_Camera(D3DVIEWPORT9* vp)
{
	g_D3DDevice->GetViewport(vp);
}

bool Graphics::SetMatProj(const D3DMATRIX& matProj) const
{
	return g_D3DDevice->SetTransform(D3DTS_PROJECTION, &matProj);
}


void Graphics::CreateGraphicInstance()
{
	if (IsGraphicInstance_NULL() == true)
	{
		p_GraphicInstance = new Graphics;
	}
}

void Graphics::DestroyGraphicInstance()
{
	if (IsGraphicInstance_NULL() == false)
	{
		delete p_GraphicInstance;
		p_GraphicInstance = NULL;
	}
}
 
bool Graphics::IsGraphicInstance_NULL()
{
	return p_GraphicInstance == NULL;
}

Graphics* Graphics::GetGraphicInstance()
{
	return p_GraphicInstance;
}

Graphics::Graphics()
{
	g_D3DDevice = nullptr;
	g_D3DInterface = nullptr;
}

Graphics::~Graphics()
{

}



