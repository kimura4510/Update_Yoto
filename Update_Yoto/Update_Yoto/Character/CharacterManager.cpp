#include "CharacterManager.h"
#include "Player/Player.h"
#include "Enemy/Enemies/Drawer.h"
#include "Enemy/Enemies/Perry.h"
#include "Enemy/Enemies/Hermit.h"
#include "Enemy/Enemies/Sinsengumi.h"
#include "Enemy/Enemies/Fox.h"
#include "../3DLibrary/3DLibrary/Engine/Input.hpp"
#include <time.h>


CharacterManager::CharacterManager()
{
	m_p_player = nullptr;
	m_p_enemy = nullptr;

	m_p_callout_ui = nullptr;
	for (int i = 0; i < 2; i++)
	{
		m_p_hp_ui[i] = nullptr;
	}

}

CharacterManager::~CharacterManager()
{
	if (m_p_player != nullptr)
	{
		delete m_p_player;
		m_p_player = nullptr;
	}
	if (m_p_enemy != nullptr)
	{
		delete m_p_enemy;
		m_p_enemy = nullptr;
	}
	if (m_p_callout_ui != nullptr)
	{
		delete m_p_callout_ui;
		m_p_callout_ui = nullptr;
	}
	
	for (int i = 0; i < 2; i++)
	{
		if (m_p_hp_ui[i] != nullptr)
		{
			delete m_p_hp_ui[i];
			m_p_hp_ui[i] = nullptr;
		}
	}
}

void CharacterManager::Init()
{
	if (m_p_player == nullptr)
	{
		m_p_player = new Player;
	}
	if (m_p_enemy == nullptr)
	{
		m_p_enemy = new Drawer;
	}
	if (m_p_callout_ui == nullptr)
	{
		m_p_callout_ui = new CalloutUI;
	}
	// プレイヤーのHPゲージ
	if (m_p_hp_ui[0] == nullptr)
	{
		m_p_hp_ui[0] = new HpUI(
			HpUI::DrawType::HP_MAX,
			HpUI::DrawDirection::RIGHT,
			0.0f,
			0.0f);
	}
	// エネミーのHPゲージ
	if (m_p_hp_ui[1] == nullptr)
	{
		m_p_hp_ui[1] = new HpUI(
			HpUI::DrawType::HP_MAX,
			HpUI::DrawDirection::LEFT,
			1320.0f,
			0.0f);
	}
}

void CharacterManager::Create()
{
	if (m_p_player == nullptr)
	{
		m_p_player = new Player;
	}
	
	if (m_p_enemy == nullptr)
	{
		switch (m_p_enemy->GetEnemyID())
		{
		case DRAWER:
			m_p_enemy = new Drawer;
			break;
		case PERRY:
			m_p_enemy = new Perry;
			break;
		case HERMIT:
			m_p_enemy = new Hermit;
			break;
		case SINSENGUMI:
			m_p_enemy = new Sinsengumi;
			break;
		case FOX:
			m_p_enemy = new Fox;
			break;
		default:
			break;
		}
	}
}

void CharacterManager::Update()
{
	if (m_p_player != nullptr && m_p_enemy != nullptr)
	{
		/*CallOutUIの描画「押せ！」*/
		m_p_callout_ui->Update();
		if(m_p_callout_ui->IsOn()==true)
		{
			m_p_enemy->QuickPressFlameDown();
			if (Input::GetInputInstance()->GetKey(KEY_INFO::ENTER_KEY) == true)
			{
				// エネミーのHPを減らす
				m_p_enemy->HpDown();
				if (m_p_enemy->GetHp() == 0) 
				{
					m_p_hp_ui[1]->ChangeDrawTypeNone();
				}
				else if (m_p_enemy->GetHp() == 1)
				{
					m_p_hp_ui[1]->ChangeDrawTypeLittle();
				}
				else if (m_p_enemy->GetHp() == 2) 
				{
					m_p_hp_ui[1]->ChangeDrawTypeMedium();
				}
				else if (m_p_enemy->GetHp() == 3) 
				{ 
					m_p_hp_ui[1]->ChangeDrawTypeMax();
				}
				m_p_callout_ui->IsNotOn();
			}
			if (m_p_enemy->GetQuickPressFlame() <= 0)
			{
				// プレイヤーのHPを減らす
				m_p_player->HpDown();
				if (m_p_player->GetHp() == 0)
				{
					m_p_hp_ui[0]->ChangeDrawTypeNone();
				}
				else if (m_p_player->GetHp() == 1)
				{
					m_p_hp_ui[0]->ChangeDrawTypeLittle();
				}
				else if (m_p_player->GetHp() == 2)
				{
					m_p_hp_ui[0]->ChangeDrawTypeMedium();
				}
				else if (m_p_player->GetHp() == 3)
				{
					m_p_hp_ui[0]->ChangeDrawTypeMax();
				}
				m_p_callout_ui->IsNotOn();
			}	
		}
		else
		{
			// お手付き
			if (Input::GetInputInstance()->GetKey(KEY_INFO::ENTER_KEY) == true)
			{
				// プレイヤーのHPを減らす
				m_p_player->HpDown();
				if (m_p_enemy->GetHp() == 0)
				{
					m_p_hp_ui[1]->ChangeDrawTypeNone();
				}
				else if (m_p_enemy->GetHp() == 1)
				{
					m_p_hp_ui[1]->ChangeDrawTypeLittle();
				}
				else if (m_p_enemy->GetHp() == 2)
				{
					m_p_hp_ui[1]->ChangeDrawTypeMedium();
				}
				else if (m_p_enemy->GetHp() == 3)
				{
					m_p_hp_ui[1]->ChangeDrawTypeMax();
				}
			}
		}
		m_p_player->Update();
		m_p_enemy->Update();
	}

	for (int i = 0; i < 2; i++)
	{
		if (m_p_hp_ui[i] != nullptr)
		{
			m_p_hp_ui[i]->Update();
		}
	}
}

void CharacterManager::Draw()
{
	if (m_p_player != nullptr)
	{
		m_p_player->Draw();
	}
	if (m_p_enemy != nullptr)
	{
		m_p_enemy->Draw();
	}
	if (m_p_callout_ui != nullptr)
	{
		m_p_callout_ui->Draw();
	}
	for (int i = 0; i < 2; i++)
	{
		if (m_p_hp_ui[i] != nullptr)
		{
			m_p_hp_ui[i]->Draw();
		}
	}
}

bool CharacterManager::PlayerIsExit()
{
	if (m_p_player->GetHp() <= 0)
	{
		return true;
	}
}
bool CharacterManager::EnemyIsExit()
{
	if (m_p_enemy->GetHp() <= 0)
	{
		return true;
	}
}

void CharacterManager::Release()
{
	if (PlayerIsExit() == true)
	{
		delete m_p_player;
		m_p_player = nullptr;
	}
	if (EnemyIsExit() == true)
	{
		delete m_p_enemy;
		m_p_enemy = nullptr;
	}
}

int CharacterManager::GameEnd(Character::GAME_END game_end_id_)
{
	if (game_end_id_ == Character::GAME_END::GAME_CLEAR)
	{
		return 1;
	}
	if (game_end_id_ == Character::GAME_END::GAME_OVER)
	{
		return 2;
	}
}