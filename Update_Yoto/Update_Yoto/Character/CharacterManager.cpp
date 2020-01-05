#include "CharacterManager.h"
#include "Player/Player.h"
#include "Enemy/Enemies/Drawer.h"
#include "Enemy/Enemies/Perry.h"
#include "Enemy/Enemies/Hermit.h"
#include "Enemy/Enemies/Sinsengumi.h"
#include "Enemy/Enemies/Fox.h"
#include "../3DLibrary/3DLibrary/Engine/Input.hpp"

CharacterManager::CharacterManager() : 
	m_enemy_id(ENEMY_ID::DRAWER)
{
	m_p_player = nullptr;
	m_p_enemy = nullptr; 

	m_p_callout_ui = nullptr;

	for (int i = 0; i < (int)BATTLE_CHARACTER::BATTLE_MAX; i++)
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

	for (int i = 0; i < (int)BATTLE_CHARACTER::BATTLE_MAX; i++)
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

	// �v���C���[��HP�Q�[�W
	if (m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_PLAYER] == nullptr)
	{
		m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_PLAYER] = new HpUI(
			HpUI::DrawType::HP_MAX,
			HpUI::DrawDirection::RIGHT,
			0.0f,
			0.0f);
	}
	// �G�l�~�[��HP�Q�[�W
	if (m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_ENEMY] == nullptr)
	{
		m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_ENEMY] = new HpUI(
			HpUI::DrawType::HP_MAX,
			HpUI::DrawDirection::LEFT,
			1320.0f,
			0.0f);
	}
	m_p_enemy->SetQuickPressFlame();
}

void CharacterManager::Create()
{
	if (m_p_player == nullptr)
	{
		m_p_player = new Player;
	}

	// �G�̓���ւ�����
	if (m_p_enemy == nullptr)
	{
		switch (m_enemy_id)
		{
		case ENEMY_ID::DRAWER:
			m_p_enemy = new Drawer;
			break;
		case ENEMY_ID::PERRY:
			m_p_enemy = new Perry;
			break;
		case ENEMY_ID::HERMIT:
			m_p_enemy = new Hermit;
			break;
		case ENEMY_ID::SINSENGUMI:
			m_p_enemy = new Sinsengumi;
			break;
		case ENEMY_ID::FOX:
			m_p_enemy = new Fox;
			break;
		default:
			break;
		}
	}

	if (m_p_callout_ui == nullptr)
	{
		m_p_callout_ui = new CalloutUI;
	}

	// �v���C���[��HP�Q�[�W
	if (m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_PLAYER] == nullptr)
	{
		m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_PLAYER] = new HpUI(
			HpUI::DrawType::HP_MAX,
			HpUI::DrawDirection::RIGHT,
			0.0f,
			0.0f);
	} 
	// �G�l�~�[��HP�Q�[�W
	if (m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_ENEMY] == nullptr)
	{
		m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_ENEMY] = new HpUI(
			HpUI::DrawType::HP_MAX,
			HpUI::DrawDirection::LEFT,
			1320.0f,
			0.0f);
	}
}

void CharacterManager::Update()
{
	Create();

	if (m_p_player != nullptr && m_p_enemy != nullptr)
	{
		/*CallOutUI�̕`��u�����I�v*/
		m_p_callout_ui->Update();
		if(m_p_callout_ui->IsOn()==true)
		{
			m_p_enemy->QuickPressFlameDown();
			if (Input::GetInputInstance()->GetKeyDown(KEY_INFO::ENTER_KEY) == true)
			{
				// �v���C���[�̃J�b�g�C����`��

				// �G�l�~�[��HP�����炷
				m_p_enemy->HpDown();
				HpUiManager(BATTLE_CHARACTER::BATTLE_ENEMY);
				m_p_callout_ui->IsNotOn();
				m_p_enemy->SetQuickPressFlame();
			}
			else if (m_p_enemy->GetQuickPressFlame() <= 0)
			{
				// �G�l�~�[�̃J�b�g�C����`��

				// �v���C���[��HP�����炷
				m_p_player->HpDown();
				HpUiManager(BATTLE_CHARACTER::BATTLE_PLAYER);
				m_p_callout_ui->IsNotOn();
				m_p_enemy->SetQuickPressFlame();
			}	
		}
		else
		{
			// ����t��
			if (Input::GetInputInstance()->GetKeyDown(KEY_INFO::ENTER_KEY) == true)
			{
				// �v���C���[��HP�����炷
				m_p_player->HpDown();
				HpUiManager(BATTLE_CHARACTER::BATTLE_PLAYER);
				m_p_enemy->SetQuickPressFlame();
			}
		}
		m_p_player->Update();
		m_p_enemy->Update();
	}

	for (int i = 0; i < (int)BATTLE_CHARACTER::BATTLE_MAX; i++)
	{
		if (m_p_hp_ui[i] != nullptr)
		{
			m_p_hp_ui[i]->Update();
		}
	}
	// m_p_enemy�̒���nullptr�ɂȂ�O�Ɏ��̃G�l�~�[��ID���擾���Ă���
	// 2019/12/20 ID�̐؂�ւ��̓Q�[���V�[�����ōs��
	//m_enemy_id = (ENEMY_ID)m_p_enemy->GetEnemyID();

	//DeleteCheck();
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

	for (int i = 0; i < (int)BATTLE_CHARACTER::BATTLE_MAX; i++)
	{
		if (m_p_hp_ui[i] != nullptr)
		{
			m_p_hp_ui[i]->Draw();
		}
	}
}

void CharacterManager::DeleteCheck()
{
	if (m_p_player != nullptr && m_p_enemy != nullptr)
	{
		if (m_p_player->GetHp() <= 0 || m_p_enemy->GetHp() <= 0)
		{
			for (int i = 0; i < (int)BATTLE_CHARACTER::BATTLE_MAX; i++)
			{
				delete m_p_hp_ui[i];
				m_p_hp_ui[i] = nullptr;
			}

			delete m_p_player;
			m_p_player = nullptr;

			delete m_p_enemy;
			m_p_enemy = nullptr;
		}
	}
}

void CharacterManager::HpUiManager(BATTLE_CHARACTER battle_character_)
{
	// �v���C���[��HPUI�\��
	if (battle_character_ == BATTLE_CHARACTER::BATTLE_PLAYER)
	{
		if (m_p_player->GetHp() == 0)
		{
			m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_PLAYER]->ChangeDrawTypeNone();
		}
		else if (m_p_player->GetHp() == 1)
		{
			m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_PLAYER]->ChangeDrawTypeLittle();
		}
		else if (m_p_player->GetHp() == 2)
		{
			m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_PLAYER]->ChangeDrawTypeMedium();
		}
		else if (m_p_player->GetHp() == 3)
		{
			m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_PLAYER]->ChangeDrawTypeMax();
		}
	}
	// �G�l�~�[��HPUI�\��
	if (battle_character_ == BATTLE_CHARACTER::BATTLE_ENEMY)
	{
		if (m_p_enemy->GetHp() == 0)
		{
			m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_ENEMY]->ChangeDrawTypeNone();
		}
		else if (m_p_enemy->GetHp() == 1)
		{
			m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_ENEMY]->ChangeDrawTypeLittle();
		}

		else if (m_p_enemy->GetHp() == 2)
		{
			m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_ENEMY]->ChangeDrawTypeMedium();
		}
		else if (m_p_enemy->GetHp() == 3)
		{
			m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_ENEMY]->ChangeDrawTypeMax();
		}
	}
}




bool CharacterManager::IsBattleFinish()
{
	if (m_p_player->GetHp() <= 0 || m_p_enemy->GetHp() <= 0)
	{
		return true;
	}
	else
	{
		false;
	}
}

GAME_END CharacterManager::GetGameEnd()
{
	if (m_p_player->GetHp() <= 0)
	{
		return GAME_END::GAME_OVER;
	}
	if (m_p_enemy->GetHp() <= 0)
	{
		//���̃L���������Ȃ�������N���A��Ԃ�
		if (GetNextEnemyID() == ENEMY_ID::ENMEY_NONE)
		{
			return GAME_END::GAME_CLEAR;
		}
	}
	return GAME_END::GAME_NONE;
}

ENEMY_ID CharacterManager::GetNextEnemyID()
{
	switch (m_enemy_id)
	{
	case ENEMY_ID::DRAWER:
		return ENEMY_ID::PERRY;
		break;
	case ENEMY_ID::PERRY:
		return ENEMY_ID::HERMIT;
		break;
	case ENEMY_ID::HERMIT:
		return ENEMY_ID::SINSENGUMI;
		break;
	case ENEMY_ID::SINSENGUMI:
		return  ENEMY_ID::FOX;
		break;
	}
	return ENEMY_ID::ENMEY_NONE;
}

void CharacterManager::ChangeNextEnemy()
{
	m_enemy_id = GetNextEnemyID();
}