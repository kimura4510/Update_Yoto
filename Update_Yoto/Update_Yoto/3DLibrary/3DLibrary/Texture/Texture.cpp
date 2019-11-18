#include <d3dx9.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include "Texture.hpp"

cTexture::cTexture()
{
}

//IDチェック
bool cTexture::IsCategoryIDCheck(int category_id, int texture_id)
{
	if (category_id <= -1 || category_id >= MAX_TEXTURE_CATEGORY)
	{
		return false;
	}

	if (texture_id <= -1 || texture_id >= m_pTextureCategorySize[category_id])
	{
		return false;
	}

	return true;
}

void cTexture::InitTexture()
{
	m_TextureData = NULL;
	m_TextureList = NULL;
}

void cTexture::ReleaseCategoryTexture(int release_category)
{
	for (int i = 1; i < m_TextureData.size; i++)
	{
		m_TextureData.erase(i);
	}

	for (int i = 1; i < m_TextureList.size; i++)
	{
		m_TextureList.erase(i);
	}
}

void cTexture::AllReleaseTexture()
{
	m_TextureData.clear();
	m_TextureList.clear();
}

bool cTexture::LoadTexture(const char* file_name)
{
	m_TextureData.push_back();
	m_TextureList.insert(std::make_pair(file_name, (int)m_TextureData.size() - 1));
	Texture* p_tex = &m_TextureData.emplace_back();
	
	return Graphics::GetGraphicInstance()->CreateTexture(file_name, p_tex);
}

Texture* cTexture::GetTexture(const char* file_name)
{
	int num = m_TextureList.at(file_name);
	return m_TextureData[num];
}

void cTexture::CreateTextureInstance()
{
	if (IsTextureInstance_NULL() == true)
	{
		p_TextureInstance = new cTexture;
	}
}

void cTexture::DestroyTextureInstance()
{
	if (IsTextureInstance_NULL() == false)
	{
		delete p_TextureInstance;
		p_TextureInstance = NULL;
	}
}

bool cTexture::IsTextureInstance_NULL()
{
	return p_TextureInstance == NULL;
}

cTexture* cTexture::GetTextureInstance()
{
	if (cTexture::IsTextureInstance_NULL() == false)
	{
		return;
	}
	return p_TextureInstance;
}

cTexture::cTexture()
{

}

cTexture::~cTexture()
{

}