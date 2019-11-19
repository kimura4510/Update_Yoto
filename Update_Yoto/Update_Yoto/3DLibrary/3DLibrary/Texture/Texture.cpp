#include <map>
#include "Texture.hpp"

cTexture* cTexture::p_TextureInstance = NULL;

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
	m_TextureList.clear();
}

bool cTexture::LoadTexture(const char* file_name)
{
	m_TextureList.insert(std::make_pair(file_name, new Texture));
	
	return Graphics::GetGraphicInstance()->CreateTexture(file_name, m_TextureList.end()->second);
}

Texture* cTexture::GetTexture(const char* file_name)
{
	return m_TextureList.at(file_name);
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
		return NULL;
	}
	return p_TextureInstance;
}

cTexture::~cTexture()
{

}