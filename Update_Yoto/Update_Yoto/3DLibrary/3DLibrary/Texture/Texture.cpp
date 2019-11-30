#include "Texture.hpp"

cTexture* cTexture::p_TextureInstance = NULL;

cTexture::cTexture()
{
	for (int i = 0; i < (int)TextureCategory::MaxTextureCategory; i++)
	{
		m_ppTextureList[i] = nullptr;
	}
}

bool cTexture::IsCategoryIDCheck(TextureCategory category_id, int texture_id)
{
	if ((int)category_id <= -1 || (int)category_id >= (int)TextureCategory::MaxTextureCategory)
	{
		return false;
	}

	if (texture_id <= -1 || texture_id >= TextureCategorySize[(int)category_id])
	{
		return false;
	}

	return true;
}


void cTexture::InitTexture()
{
	for (int i = 0; i < (int)TextureCategory::MaxTextureCategory; i++)
	{
		m_ppTextureList[i] = new Texture* [TextureCategorySize[i]];
		
		for (int j = 0; j < TextureCategorySize[i]; j++)
		{
			m_ppTextureList[i][j] = new Texture;
			m_ppTextureList[i][j]->m_TextureData = nullptr;
		}
	}
}

void cTexture::ReleaseCategoryTexture(int release_category)
{
	if (m_ppTextureList[release_category] == nullptr)
	{
		return;
	}

	for (int i = 0; i < TextureCategorySize[release_category]; i++)
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
	for (int i = 0; i < (int)TextureCategory::MaxTextureCategory; i++)
	{
		ReleaseCategoryTexture(i);

		for (int j = 0; j < TextureCategorySize[i]; j++)
		{
			delete m_ppTextureList[i][j];
		}
		delete[] m_ppTextureList[i];
	}
}

bool cTexture::LoadTexture(const char* file_name, TextureCategory id,  int textureID)
{
	if (IsCategoryIDCheck(id, textureID) == false)
	{
		return false;
	}
	return Graphics::GetGraphicInstance()->CreateTexture(file_name, m_ppTextureList[(int)id][textureID]);
}

Texture* cTexture::GetTexture(TextureCategory category_, int textureID_)
{
	if (IsCategoryIDCheck(category_, textureID_) == false)
	{
		return nullptr;
	}
	return m_ppTextureList[(int)category_][textureID_];
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
	return p_TextureInstance;
}

cTexture::~cTexture()
{

}