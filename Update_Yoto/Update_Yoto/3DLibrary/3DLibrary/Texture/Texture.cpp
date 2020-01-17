#include "Texture.hpp"
#include<unordered_map>

cTexture* cTexture::p_TextureInstance = NULL;

cTexture::cTexture()
{
}


void cTexture::InitTexture()
{
}

void cTexture::ReleaseAllTexture()
{
	for (auto& texture : m_pTextureList)
	{
		delete texture.second;
	}
	
	m_pTextureList.clear();
}

bool cTexture::ReleaseTexture(std::string key_name)
{
	if (HasKeyName(key_name) == false)
	{
		return false;
	}
	delete m_pTextureList[key_name];
	m_pTextureList.erase(key_name);
	return true;
}

bool cTexture::LoadTexture(const char* file_name, std::string key_name)
{
	if (HasKeyName(key_name) == true)
	{
		return false;
	}
	m_pTextureList[key_name.c_str()] = new Texture;
	return Graphics::GetGraphicInstance()->CreateTexture(file_name, m_pTextureList[key_name]);
}

Texture* cTexture::GetTexture(std::string key_name)
{
	if (HasKeyName(key_name) == false)
	{
		return nullptr;
	}
	return m_pTextureList[key_name];
}

bool cTexture::HasKeyName(std::string key_name)
{
	auto it = m_pTextureList.find(key_name);

	if (it == m_pTextureList.end())
	{
		return false;
	}
	return true;
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