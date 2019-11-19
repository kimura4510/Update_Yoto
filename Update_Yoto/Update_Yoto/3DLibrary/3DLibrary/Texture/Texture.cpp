#include <d3dx9.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include "Texture.hpp"

cTexture::cTexture()
{
	InitTexture();
}

void cTexture::InitTexture()
{

}

void cTexture::ReleaseCategoryTexture(int release_category)
{

}

void cTexture::AllReleaseTexture()
{
	for (int i = 0; i < (int)m_TextureData.size; i++)
	{
		delete m_TextureData[i];
	}

	m_TextureData.clear();
	m_TextureList.clear();
}

bool cTexture::LoadTexture(const char* file_name)
{
	m_TextureData.push_back(new Texture);

	m_TextureList.insert(std::make_pair(file_name, m_TextureData.size()));
		
	return Graphics::GetGraphicInstance()->CreateTexture(file_name, m_TextureData.back);
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

cTexture::~cTexture()
{

}