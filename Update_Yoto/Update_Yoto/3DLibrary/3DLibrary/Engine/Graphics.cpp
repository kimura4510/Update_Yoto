#include "Graphics.hpp"
#include <d3d9.h>
#include <d3dx9.h>
#include "Camera.h"
#include "../Size.hpp"

// 静的ライブラリ
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
	g_D3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 255, 0), 0.0f, 0);

	g_D3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	g_D3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_D3DDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

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
		{x, y, 0.0f, 1.0f, D3DCOLOR_RGBA(255, 255, 255, 255), 0.0f, 0.0f}, //left-top
		{x + texture_data->m_Width, y, 0.0f, 1.0f, D3DCOLOR_RGBA(255, 255, 255, 255), 1.0f, 0.0f}, //right-top
		{x, y + texture_data->m_Height, 0.0f, 1.0f, D3DCOLOR_RGBA(255, 255, 255, 255), 0.0f, 1.0f},//left-bottom
		{x + texture_data->m_Width, y + texture_data->m_Height, 0.0f, 1.0f, D3DCOLOR_RGBA(255, 255, 255, 255), 1.0f, 1.0f},//right-bottom
	};

	//頂点構造の指定
	g_D3DDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	g_D3DDevice->SetTexture(0, texture_data->m_TextureData);
	g_D3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,
		2,
		TriStr,
		sizeof(CustomVertex));
}

void Graphics::DrawIntegratedImage(float x, float y, Texture* texture_data, float tu, float tv, float spriteX, float spriteY, int spriteNumX, int spriteNumY, int color)
{
	int tmpX = spriteNumX - 1;
	int tmpY = spriteNumY - 1;
	CustomVertex TriStr[] =
	{
		{x, y, 0.0f, 1.0f, D3DCOLOR_RGBA(255, 255, 255, color), tu * tmpX, tv * tmpY},
		{x + spriteX, y, 0.0f, 1.0f, D3DCOLOR_RGBA(255, 255, 255, color), tu * spriteNumX, tv * tmpY},
		{x, y + spriteY, 0.0f, 1.0f, D3DCOLOR_RGBA(255, 255, 255, color), tu * tmpX, tv * spriteNumY},
		{x + spriteX, y + spriteY, 0.0f, 1.0f, D3DCOLOR_RGBA(255, 255, 255, color), tu * spriteNumX, tv * spriteNumY}
	};

	//頂点構造の指定
	g_D3DDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	g_D3DDevice->SetTexture(0, texture_data->m_TextureData);
	g_D3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,
		2,
		TriStr,
		sizeof(CustomVertex));
}

void Graphics::Draw3D(const DrawingData3D& v3d, Texture* texture_data)
{
	// ポリゴンのローカル座標の位置を指定 start
	CustomVertex3D v[4];
	for (int i = 0; i < 4; i++)
	{
		v[i].color = D3DCOLOR_ARGB(255, 255, 255, 255);
	}
	v[0].m_x = v3d.m_x;					v[0].m_y = v3d.m_y + v3d.m_height;	v[0].m_z = v3d.m_z;
	v[0].tu = 0.0f;						v[0].tv = 0.0f;
	v[1].m_x = v3d.m_x + v3d.m_width;	v[1].m_y = v3d.m_y + v3d.m_height;	v[1].m_z = v3d.m_z;
	v[1].tu = 1.0f;						v[1].tv = 0.0f;
	v[2].m_x = v3d.m_x;					v[2].m_y = v3d.m_y;					v[2].m_z = v3d.m_z;
	v[2].tu = 0.0f;	v[2].tv = 1.0f;
	v[3].m_x = v3d.m_x + v3d.m_width;	v[3].m_y = v3d.m_y;					v[3].m_z = v3d.m_z;	
	v[3].tu = 1.0f;						v[3].tv = 1.0;
	// ポリゴンのローカル座標の位置を指定 end

	//ワールド座標変換用の行列の算出 start
	D3DXMATRIX mat_world, mat_trans, mat_rot, mat_rotx, mat_roty, mat_rotz, mat_scale;
	D3DXMatrixIdentity(&mat_world);
	D3DXMatrixIdentity(&mat_rot);
	D3DXMatrixIdentity(&mat_trans);
	D3DXMatrixIdentity(&mat_scale);

	// 移動
	D3DXMatrixTranslation(&mat_trans, 0.0f, 0.0f, 10.0f);

	// 回転
	D3DXMatrixRotationX(&mat_rotx, D3DXToRadian(v3d.m_rotx));
	D3DXMatrixRotationY(&mat_roty, D3DXToRadian(v3d.m_roty));
	D3DXMatrixRotationZ(&mat_rotz, D3DXToRadian(v3d.m_rotz));

	D3DXMatrixMultiply(&mat_rot, &mat_rot, &mat_roty);
	D3DXMatrixMultiply(&mat_rot, &mat_rot, &mat_rotx);
	D3DXMatrixMultiply(&mat_rot, &mat_rot, &mat_rotz);

	// 拡大
	D3DXMatrixScaling(&mat_scale, v3d.m_scalex, v3d.m_scaley, 1.0f);

	// 掛け合わせ(拡縮 * 回転 * 移動)
	mat_world *= mat_scale * mat_rot * mat_trans;

	g_D3DDevice->SetTransform(D3DTS_WORLD, &mat_world);
	//ワールド座標変換用の行列の算出 end

	g_D3DDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	g_D3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	g_D3DDevice->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	g_D3DDevice->SetTexture(0, texture_data->m_TextureData);

	g_D3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, v, sizeof(CustomVertex3D));

}

void Graphics::DrawIntegratedImage3D(const DrawingData3D& v3d, Texture* texture_data, float tu, float tv, float spriteX, float spriteY, int spriteNumX, int spriteNumY)
{
	int tmpX = spriteNumX - 1;
	int tmpY = spriteNumY - 1;

	// ポリゴンのローカル座標の位置を指定 start
	CustomVertex3D v[4];
	for (int i = 0; i < 4; i++)
	{
		v[i].color = D3DCOLOR_ARGB(255, 255, 255, 255);
	}
	v[0].m_x = v3d.m_x;				v[0].m_y = v3d.m_y + spriteY;	v[0].m_z = v3d.m_z;
	v[0].tu = tu * tmpX;			v[0].tv = tv * tmpY;
	v[1].m_x = v3d.m_x + spriteX;	v[1].m_y = v3d.m_y + spriteY;	v[1].m_z = v3d.m_z;
	v[1].tu = tu * spriteNumX;		v[1].tv = tv * tmpY;
	v[2].m_x = v3d.m_x;				v[2].m_y = v3d.m_y;				v[2].m_z = v3d.m_z;
	v[2].tu = tu * tmpX;			v[2].tv = tv * spriteNumY;
	v[3].m_x = v3d.m_x + spriteX;	v[3].m_y = v3d.m_y;	v[3].m_z = v3d.m_z;
	v[3].tu = tu * spriteNumX;		v[3].tv = tv * spriteNumY;
	// ポリゴンのローカル座標の位置を指定 end
	
		//ワールド座標変換用の行列の算出 start
	D3DXMATRIX mat_world, mat_trans, mat_rot, mat_rotx, mat_roty, mat_rotz, mat_scale;
	D3DXMatrixIdentity(&mat_world);
	D3DXMatrixIdentity(&mat_rot);
	D3DXMatrixIdentity(&mat_trans);
	D3DXMatrixIdentity(&mat_scale);

	// 移動
	D3DXMatrixTranslation(&mat_trans, 0.0f, 0.0f, 10.0f);

	// 回転
	D3DXMatrixRotationX(&mat_rotx, D3DXToRadian(v3d.m_rotx));
	D3DXMatrixRotationY(&mat_roty, D3DXToRadian(v3d.m_roty));
	D3DXMatrixRotationZ(&mat_rotz, D3DXToRadian(v3d.m_rotz));

	D3DXMatrixMultiply(&mat_rot, &mat_rot, &mat_roty);
	D3DXMatrixMultiply(&mat_rot, &mat_rot, &mat_rotx);
	D3DXMatrixMultiply(&mat_rot, &mat_rot, &mat_rotz);

	// 拡大
	D3DXMatrixScaling(&mat_scale, v3d.m_scalex, v3d.m_scaley, 1.0f);

	// 掛け合わせ(拡縮 * 回転 * 移動)
	mat_world *= mat_scale * mat_rot * mat_trans;

	g_D3DDevice->SetTransform(D3DTS_WORLD, &mat_world);
	//ワールド座標変換用の行列の算出 end

	g_D3DDevice->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	g_D3DDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	g_D3DDevice->SetTexture(0, texture_data->m_TextureData);

	g_D3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, v, sizeof(CustomVertex3D));
}

void Graphics::Animation2D(
	float x,
	float y,
	Texture* p_texture,
	float set_tu,
	float set_tv,
	float graph_size_x,
	float graph_size_y,
	int split_x,
	int split_y,
	int animation_graph_num
) {


	// アニメーション番号取り出し
	int animation_x = (animation_graph_num % split_x) + 1;
	int animation_y = (animation_graph_num / split_x) + 1;

	// 3D統合画像関数を扱う
	DrawIntegratedImage(
		x,
		y,
		p_texture,
		set_tu,
		set_tv,
		graph_size_x,
		graph_size_y,
		animation_x,
		animation_y
	);
}

void Graphics::Animation3D(
	const DrawingData3D&drawing_data_3d,
	Texture* p_texture,
	float set_tu,
	float set_tv,
	float graph_size_x,
	float graph_size_y,
	int split_x,
	int animation_graph_num
) {

	// アニメーション番号取り出し
	int animation_x = (animation_graph_num % split_x) + 1;
	int animation_y = (animation_graph_num / split_x) + 1;


	// 3D統合画像関数を扱う
	DrawBillboard(
		drawing_data_3d,
		p_texture,
		set_tu,
		set_tv,
		graph_size_x,
		graph_size_y,
		animation_x,
		animation_y
	);
}

void Graphics::DrawBillboard(const DrawingData3D& v3d, Texture* texture_data, float tu, float tv, float spriteX, float spriteY, int spriteNumX, int spriteNumY)
{
	int tmpX = spriteNumX - 1;
	int tmpY = spriteNumY - 1;

	// ポリゴンのローカル座標の位置を指定 start
	CustomVertex3D v[4];
	for (int i = 0; i < 4; i++)
	{
		v[i].color = D3DCOLOR_ARGB(255, 255, 255, 255);
	}
	v[0].m_x = 0.0f;				v[0].m_y = 0.0f + spriteY;	v[0].m_z = 0.0f;
	v[0].tu = tu * tmpX;			v[0].tv = tv * tmpY;
	v[1].m_x = 0.0f + spriteX;		v[1].m_y = 0.0f + spriteY;	v[1].m_z = 0.0f;
	v[1].tu = tu * spriteNumX;		v[1].tv = tv * tmpY;
	v[2].m_x = 0.0f;				v[2].m_y = 0.0f;			v[2].m_z = 0.0f;
	v[2].tu = tu * tmpX;			v[2].tv = tv * spriteNumY;
	v[3].m_x = 0.0f + spriteX;		v[3].m_y = 0.0f;			v[3].m_z = 0.0f;
	v[3].tu = tu * spriteNumX;		v[3].tv = tv * spriteNumY;
	// ポリゴンのローカル座標の位置を指定 end

		//ワールド座標変換用の行列の算出 start
	D3DXMATRIX mat_world, mat_trans, mat_scale, view_mat, inv_mat;
	D3DXMatrixIdentity(&mat_world);
	D3DXMatrixIdentity(&mat_trans);
	D3DXMatrixIdentity(&mat_scale);
	D3DXMatrixIdentity(&view_mat);
	D3DXMatrixIdentity(&inv_mat);

	// 移動
	D3DXMatrixTranslation(&mat_trans, v3d.m_x, v3d.m_y, v3d.m_z);

	// カメラビュー行列の逆行列を作成
	g_D3DDevice->GetTransform(D3DTS_VIEW, &view_mat);
	D3DXMatrixInverse(&inv_mat, NULL, &view_mat);
	
	// 移動情報の打ち消し
	inv_mat._41 = 0.0f;
	inv_mat._42 = 0.0f;
	inv_mat._43 = 0.0f;

	// 拡大
	D3DXMatrixScaling(&mat_scale, v3d.m_scalex, v3d.m_scaley, 1.0f);

	// 掛け合わせ(拡縮 * 回転 * 移動)
	mat_world *= mat_scale * inv_mat * mat_trans;

	g_D3DDevice->SetTransform(D3DTS_WORLD, &mat_world);
	//ワールド座標変換用の行列の算出 end

	g_D3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	g_D3DDevice->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	g_D3DDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
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
	if (FAILED(g_D3DDevice->SetTransform(D3DTS_VIEW, &matView)))
	{
		return false;
	}
	return true;
}

void Graphics::GetViewport_Camera(D3DVIEWPORT9* vp)
{
	g_D3DDevice->GetViewport(vp);
}

bool Graphics::SetMatProj(const D3DMATRIX& matProj) const
{
	if (FAILED(g_D3DDevice->SetTransform(D3DTS_PROJECTION, &matProj)))
	{
		return false;
	}
	return true;
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



