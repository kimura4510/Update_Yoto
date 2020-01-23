#include "Player.h"
#include "../../3DLibrary/3DLibrary/Texture/Texture.hpp"
#include "../../3DLibrary/3DLibrary/Engine/Input.hpp"
#include "../../3DLibrary/3DLibrary/Engine/Graphics.hpp"

Player::Player() : Character()
{
	m_isdeth = false;
	m_x = -256.0f;		// uplayer.pngv‚Ì•`‰æ‚¾‚¯‚È‚ç¨ //128.0f;
	m_y = 0.0f;
	m_z = 512.0f;			// uplayer.pngv‚Ì•`‰æ‚¾‚¯‚È‚ç¨ //256.0f;
	m_width = 256.0f;
	m_height = 256.0f;

	m_hp = 3;

	m_standby_count = 0;
}

void Player::Draw()
{
	DrawingData3D player{
		this->m_x, this->m_y, this->m_z,
		0.0f,0.0f,
		this->m_width,this->m_height,
		0xffff,
		0.0f,0.0f,0.0f,
		1.0f,1.0f,
	};
	cTexture* ctex = cTexture::GetTextureInstance();
	if (m_isdeth == false)
	{
		if (GetHp() >= 1)
		{
			if (m_character_state[static_cast<int>(CHARACTER_STATE::WALK)] == true) {
				Texture* tex = ctex->GetTexture(player_walk_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
					tex,
					0.25f, 0.0625f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::WALK)] % (4 * 9)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::WALK_WAIT)] == true) {
				Texture* tex = ctex->GetTexture(player_walk_wait_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
					tex,
					0.25f, 0.125f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::WALK_WAIT)] % ((4 * 4) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::WAIT)] == true) {
				Texture* tex = ctex->GetTexture(player_wait_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
					tex,
					0.25f, 0.0625f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::WAIT)] % ((4 * 8) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::ATTACK_01)] == true) {
				Texture* tex = ctex->GetTexture(player_attack_01_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::ATTACK_01)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_ATTACK_02)] == true) {
				Texture* tex = ctex->GetTexture(player_r_attack_02_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_ATTACK_02)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_ATTACK_02)] == true) {
				Texture* tex = ctex->GetTexture(player_l_attack_02_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_ATTACK_02)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::DEFENCE_01)] == true) {
				Texture* tex = ctex->GetTexture(player_defence_01_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::DEFENCE_01)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_DEFENCE_02)] == true) {
				Texture* tex = ctex->GetTexture(player_r_defence_02_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_DEFENCE_02)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_DEFENCE_02)] == true) {
				Texture* tex = ctex->GetTexture(player_l_defence_02_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_DEFENCE_02)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_ATTACK_CROSS)] == true) {
				Texture* tex = ctex->GetTexture(player_r_attack_cross_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_ATTACK_CROSS)] % ((4 * 3) + 1)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_ATTACK_CROSS)] == true) {
				Texture* tex = ctex->GetTexture(player_l_attack_cross_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_ATTACK_CROSS)] % ((4 * 3) + 1)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_DEFENCE_CROSS)] == true) {
				Texture* tex = ctex->GetTexture(player_r_defence_cross_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_DEFENCE_CROSS)] % ((4 * 3) + 1)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_DEFENCE_CROSS)] == true) {
				Texture* tex = ctex->GetTexture(player_l_defence_cross_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_DEFENCE_CROSS)] % ((4 * 3) + 1)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_FRICK)] == true) {
				Texture* tex = ctex->GetTexture(player_r_frick_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_FRICK)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_FRICK)] == true) {
				Texture* tex = ctex->GetTexture(player_l_frick_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_FRICK)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_KILL)] == true) {
				Texture* tex = ctex->GetTexture(player_r_kill_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_KILL)] % ((4 * 9) + 1)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_KILL)] == true) {
				Texture* tex = ctex->GetTexture(player_l_kill_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_KILL)] % ((4 * 9) + 1)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_KILL_WALK)] == true) {
				Texture* tex = ctex->GetTexture(player_r_kill_walk_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_KILL_WALK)] % ((4 * 3) + 3)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_KILL_WALK)] == true) {
				Texture* tex = ctex->GetTexture(player_l_kill_walk_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_KILL_WALK)] % ((4 * 3) + 3)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_BACK)] == true) {
				Texture* tex = ctex->GetTexture(player_r_back_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_BACK)] % ((4 * 2) + 2)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_BACK)] == true) {
				Texture* tex = ctex->GetTexture(player_l_back_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
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
				Texture* tex = ctex->GetTexture(player_r_death_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
					tex,
					0.25f, 0.0625f,
					this->m_width, this->m_height,
					4,
					(int)m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_DEATH)] % ((4 * 13) + 3)
				);
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_DEATH)] == true) {
				Texture* tex = ctex->GetTexture(player_l_death_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					player,
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

	}
}