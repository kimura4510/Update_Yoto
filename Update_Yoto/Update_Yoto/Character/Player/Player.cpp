#include "Player.h"
#include "../../3DLibrary/3DLibrary/Texture/Texture.hpp"
#include "../../3DLibrary/3DLibrary/Engine/Input.hpp"
#include "../../3DLibrary/3DLibrary/Engine/Graphics.hpp"

Player::Player()
{
	Init();
}

void Player::Init()
{
	m_isdeth	= false;
	m_x			= -256.0f;		// 「player.png」の描画だけなら→ //128.0f;
	m_y			= 100.0f;
	m_z			= -256.0f;		// 「player.png」の描画だけなら→ //256.0f;
	m_hp		= 3;
}

void Player::Draw()
{
	if (m_isdeth == false)
	{
		// プレイヤーの描画だけ
		DrawingData3D player{
			this->m_x, this->m_y, this->m_z,
			0.0f,0.0f,
			150.0f,170.0f,
			0xffff,
			0.0f,180.0f,180.0f,
			0.5f,0.5f,
		};
		// プレイヤーの描画するやつ
		/*Graphics* gp = Graphics::GetGraphicInstance();
		cTexture* tex = cTexture::GetTextureInstance();
		gp->Draw3D(player, tex->GetTexture(player_tex));*/

		// アニメーションの描画
		static float count = 0;
		count += 0.1f;

		cTexture* ctex = cTexture::GetTextureInstance();
		Texture* tex = ctex->GetTexture(chara_anime);

		Graphics::GetGraphicInstance()->Animation3D(
			player,
			tex,
			0.0625f, 0.125f,
			150.0f, 170.0f,
			16,
			(int)count % 36		//(int)count % (16 * 2) + 4
		);
	}
}

void Player::Update()
{
	if (GetHp() <= 0)
	{
		m_isdeth = true;
	}
}