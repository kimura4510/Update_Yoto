#include <d3dx9.h>
#include <stdlib.h>
#include <stdio.h>
#include "Texture.hpp"

cTexture::cTexture()
{
	m_ppTextureList = nullptr;
	m_pTextureCategorySize = nullptr;
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
	m_pTextureCategorySize = new int[MAX_TEXTURE_CATEGORY];
	
	m_pTextureCategorySize =
	{
		(int)TitleCategoryTextureList::Max,
		(int)GameCategoryTextureList::Max,
		(int)HelpCategoryTextureList::Max,
		(int)ClearCategoryTextureList::Max,
		(int)GameoverCategoryTextureList::Max
	};

	m_ppTextureList = new Texture **[MAX_TEXTURE_CATEGORY];
	
	for (int i = 0; i < MAX_TEXTURE_CATEGORY; i++)
	{
		m_ppTextureList[i] = new Texture *[(int)]
	}
}

void cTexture::ReleaseCategoryTexture(int release_category)
{
	if (m_ppTextureList[release_category] == nullptr)
	{
		return;
	}

	for (int i = 0; i < m_pTextureCategorySize[release_category]; i++)
	{
		if (m_ppTextureList[release_category][i]->m_TextureData == nullptr)
		{
			continue;
		}

		m_ppTextureList[release_category][i]->m_TextureData->Release();
		m_ppTextureList[release_category][i]->m_TextureData = nullptr;
	}
}

void cTexture::AllReleaseTexture()
{
	for (int i = 0; i < MAX_TEXTURE_CATEGORY; i++)
	{
		ReleaseCategoryTexture(i);

		free(m_ppTextureList[i]);
		m_ppTextureList[i] = nullptr;
	}
}

bool cTexture::LoadTexture(const char* file_name, int id, int texture_id)
{
	if (IsCategoryIDCheck(id, texture_id) == false)
	{
		return false;
	}

	return Graphics::GetGraphicInstance()->CreateTexture(file_name, m_ppTextureList[id][texture_id]);
}

Texture* cTexture::GetTexture(int category_id, int texture_id)
{
	if (IsCategoryIDCheck(category_id, texture_id) == false)
	{
		return nullptr;
	}
	return m_ppTextureList[category_id][texture_id];
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