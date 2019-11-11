#include <d3dx9.h>
#include <stdlib.h>
#include <stdio.h>
#include "Texture.hpp"

//IDチェック
bool TEXTURE::IsCategoryIDCheck(int category_id, int texture_id)
{
	if (category_id <= -1 || category_id >= MAX_TEXTURE_CATEGORY)
	{
		return false;
	}

	if (texture_id <= -1 || texture_id >= TextureCategorySize[category_id])
	{
		return false;
	}

	return true;
}

void TEXTURE::InitTexture()
{
	AllReleaseTexture();

	for (int i = 0; i < MAX_TEXTURE_CATEGORY; i++)
	{
		g_TextureList[i] = (Texture**)malloc(sizeof(Texture*) * TextureCategorySize[i]);

		for (int j = 0; j < TextureCategorySize[i]; j++)
		{
			g_TextureList[i][j] = (Texture*)malloc(sizeof(Texture));
			g_TextureList[i][j]->m_TextureData = nullptr;
		}
	}
}

void TEXTURE::ReleaseCategoryTexture(int release_category)
{
	if (g_TextureList[release_category] == nullptr)
	{
		return;
	}

	for (int i = 0; i < TextureCategorySize[release_category]; i++)
	{
		if (g_TextureList[release_category][i]->m_TextureData == nullptr)
		{
			continue;
		}

		g_TextureList[release_category][i]->m_TextureData->Release();
		g_TextureList[release_category][i]->m_TextureData = nullptr;
	}
}

void TEXTURE::AllReleaseTexture()
{
	for (int i = 0; i < MAX_TEXTURE_CATEGORY; i++)
	{
		ReleaseCategoryTexture(i);

		free(g_TextureList[i]);
		g_TextureList[i] = nullptr;
	}
}

bool TEXTURE::LoadTexture(const char* file_name, int id, int texture_id)
{
	if (IsCategoryIDCheck(id, texture_id) == false)
	{
		return false;
	}

	return Graphics::GetGraphicInstance()->CreateTexture(file_name, g_TextureList[id][texture_id]);
}

Texture* TEXTURE::GetTexture(int category_id, int texture_id)
{
	if (IsCategoryIDCheck(category_id, texture_id) == false)
	{
		return nullptr;
	}
	return g_TextureList[category_id][texture_id];
}