#include "Perry.h"
#include "../../../3DLibrary/3DLibrary/Texture/Texture.hpp"

Perry::Perry() : Enemy()
{
	m_isdeth = false;
	m_x = 512.0f;
	m_y = 0.0f;
	m_z = 512.0f;
	m_width = 256.0f;
	m_height = 256.0f;

	m_hp = 3;
	m_quick_press_flame = 42;
}

void Perry::Draw()
{
	DrawingData3D perry{
			this->m_x, this->m_y, this->m_z,
			0.0f,0.0f,
			this->m_width, this->m_height,
			0xffff,
			0.0f, 0.0f,0.0f,
			1.0f, 1.0f,
	};
	cTexture* ctex = cTexture::GetTextureInstance();
	if (m_isdeth == false)
	{
		if (GetHp() >= 1)
		{
			if (m_character_state[static_cast<int>(CHARACTER_STATE::WAIT)] == true) {
				Texture* tex = ctex->GetTexture(perry_wait_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.0625f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::WAIT)] % ((4 * 8) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::ATTACK_01)] == true) {
				Texture* tex = ctex->GetTexture(perry_attack_01_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::ATTACK_01)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_ATTACK_02)] == true) {
				Texture* tex = ctex->GetTexture(perry_r_attack_02_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_ATTACK_02)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_ATTACK_02)] == true) {
				Texture* tex = ctex->GetTexture(perry_l_attack_02_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_ATTACK_02)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::DEFENCE_01)] == true) {
				Texture* tex = ctex->GetTexture(perry_defence_01_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::DEFENCE_01)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_DEFENCE_02)] == true) {
				Texture* tex = ctex->GetTexture(perry_r_defence_02_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_DEFENCE_02)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_DEFENCE_02)] == true) {
				Texture* tex = ctex->GetTexture(perry_l_defence_02_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_DEFENCE_02)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_ATTACK_CROSS)] == true) {
				Texture* tex = ctex->GetTexture(perry_r_attack_cross_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_ATTACK_CROSS)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_ATTACK_CROSS)] == true) {
				Texture* tex = ctex->GetTexture(perry_l_attack_cross_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_ATTACK_CROSS)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_DEFENCE_CROSS)] == true) {
				Texture* tex = ctex->GetTexture(perry_l_defence_cross_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_DEFENCE_CROSS)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_DEFENCE_CROSS)] == true) {
				Texture* tex = ctex->GetTexture(perry_l_defence_cross_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_DEFENCE_CROSS)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_FRICK)] == true) {
				Texture* tex = ctex->GetTexture(perry_r_frick_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_FRICK)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_FRICK)] == true) {
				Texture* tex = ctex->GetTexture(perry_l_frick_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_FRICK)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_KILL)] == true) {
				Texture* tex = ctex->GetTexture(perry_r_kill_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_KILL)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_KILL)] == true) {
				Texture* tex = ctex->GetTexture(perry_l_kill_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_KILL)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_KILL_WALK)] == true) {
				Texture* tex = ctex->GetTexture(perry_r_kill_stand_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_KILL_WALK)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_KILL_WALK)] == true) {
				Texture* tex = ctex->GetTexture(perry_l_kill_stand_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_KILL_WALK)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_BACK)] == true) {
				Texture* tex = ctex->GetTexture(perry_r_back_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_BACK)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_BACK)] == true) {
				Texture* tex = ctex->GetTexture(perry_l_back_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_BACK)] % ((4 * 2) + 2)
				);
			}
		}
		else
		{
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_DEATH)] == true) {
				Texture* tex = ctex->GetTexture(perry_r_death_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.0625f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_DEATH)] % ((4 * 13) + 3)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_DEATH)] == true) {
				Texture* tex = ctex->GetTexture(perry_l_death_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.0625f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_DEATH)] % ((4 * 13) + 3)
				);
			}
		}
	}
	else
	{
		if (m_character_state[static_cast<int>(CHARACTER_STATE::DETH)] == true)
		{
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_DEATH)] == true) {
				Texture* tex = ctex->GetTexture(perry_r_death_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.0625f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_DEATH)] % ((4 * 13) + 3)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_DEATH)] == true) {
				Texture* tex = ctex->GetTexture(perry_l_death_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.0625f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_DEATH)] % ((4 * 13) + 3)
				);
			}
		}
	}
}