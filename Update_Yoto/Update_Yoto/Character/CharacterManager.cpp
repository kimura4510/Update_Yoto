#include "CharacterManager.h"
#include "Player/Player.h"
#include "Enemy/Enemies/Drawer.h"
#include "Enemy/Enemies/Perry.h"
#include "Enemy/Enemies/Hermit.h"
#include "Enemy/Enemies/Sinsengumi.h"
#include "Enemy/Enemies/Fox.h"
#include "../3DLibrary/3DLibrary/Engine/Input.hpp"
#include "../DataBank/DataBank.h"

CharacterManager::CharacterManager() :
	m_enemy_id(ENEMY_ID::ENMEY_NONE),
	m_cutin_id(CutIn::CutInType::TYPE_MAX)
{
	m_p_player = nullptr;
	m_p_enemy = nullptr;

	m_p_callout_ui = nullptr;
	for (int i = 0; i < (int)BATTLE_CHARACTER::BATTLE_MAX; i++)
	{
		m_p_cut_in[i] = nullptr;
		m_p_hp_ui[i] = nullptr;
	}
	m_player_trigger = false;
	m_enemy_trigger = false;
	m_pcutin_trigger = false;
	m_ecutin_trigger = false;
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
		if (m_p_cut_in[i] != nullptr)
		{
			delete m_p_cut_in[i];
			m_p_cut_in[i] = nullptr;
		}
		if (m_p_hp_ui[i] != nullptr)
		{
			delete m_p_hp_ui[i];
			m_p_hp_ui[i] = nullptr;
		}
	}
	// �V���O���g���̎��Ԃ�j��
	DataBank::DestroyInstance();
}

void CharacterManager::Init()
{
	// �V���O���g���̎��Ԃ��擾
	DataBank::CreateInstance();
	DataBank* p_db = DataBank::GetInstance();	// ���̂��擾

	if (m_p_player == nullptr)
	{
		m_p_player = new Player;
	}

	// �G�̓���ւ�����
	m_enemy_id = static_cast<ENEMY_ID>(p_db->GetEnemyType());
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
		m_p_enemy->SetQuickPressFlame();
	}

	if (m_p_callout_ui == nullptr)
	{
		m_p_callout_ui = new CalloutUI;
	}

	m_cutin_id = static_cast<CutIn::CutInType>(p_db->GetCutInType());
	// �v���C���[�̃J�b�g�C��
	if (m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_PLAYER] == nullptr)
	{
		m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_PLAYER] = new CutIn(
			CutIn::DrawMethod::LEFT,
			CutIn::CutInType::PLAYER,
			0.0f, 300.0f);
	}
	// �G�l�~�[�̃J�b�g�C��
	if (m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY] == nullptr)
	{
		m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY] = new CutIn(
			CutIn::DrawMethod::RIGHT,
			m_cutin_id,
			896.0f, 300.0f);
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

void CharacterManager::Create()
{
	// �V���O���g���̎��Ԃ��擾
	DataBank::CreateInstance();
	DataBank* p_db = DataBank::GetInstance();	// ���̂��擾

	if (m_p_player == nullptr)
	{
		m_p_player = new Player;
	}

	// �G�̓���ւ�����
	m_enemy_id = static_cast<ENEMY_ID>(p_db->GetEnemyType());
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
		m_p_enemy->SetQuickPressFlame();
	}

	if (m_p_callout_ui == nullptr)
	{
		m_p_callout_ui = new CalloutUI;
	}

	m_cutin_id = static_cast<CutIn::CutInType>(p_db->GetCutInType());
	// �v���C���[�̃J�b�g�C��
	if (m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_PLAYER] == nullptr)
	{
		m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_PLAYER] = new CutIn(
			CutIn::DrawMethod::LEFT,
			CutIn::CutInType::PLAYER,
			0.0f, 300.0f);
	}
	// �G�l�~�[�̃J�b�g�C��
	if (m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY] == nullptr)
	{
		m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY] = new CutIn(
			CutIn::DrawMethod::RIGHT,
			m_cutin_id,
			896.0f, 300.0f);
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

	//if (�v���C���[�ƃG�l�~�[�������Ă�����)
	if (m_p_player != nullptr && m_p_enemy != nullptr)
	{
		//�u�����I�v�̕`��܂ł̃J�E���g���n�߂�
		m_p_callout_ui->Update();
		//if (�J�E���g��0�ɂȂ�����u�����I�v��`��)
		if (m_p_callout_ui->IsOn() == true)
		{
			//�u�����I�v��`�撆�ɃG�l�~�[�̃J�E���g�����炷
			if (m_pcutin_trigger == false) 
			{
				m_p_enemy->QuickPressFlameDown();
			}

			//if (�v���C���[���G���^�[�L�[����������)
			if (Input::GetInputInstance()->GetKeyDown(KEY_INFO::ENTER_KEY) == true && m_pcutin_trigger == false)
			{
				m_pcutin_trigger = true;
				// ���Z�b�g
				m_p_enemy->SetQuickPressFlame();
			}
			//if (�G�l�~�[�̃J�E���g��0�ȉ��ɂȂ�����)
			if (m_p_enemy->GetQuickPressFlame() <= 0 && m_ecutin_trigger == false)
			{
				m_ecutin_trigger = true;
				// ���Z�b�g
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

		if (m_pcutin_trigger == true)
		{
			//�v���C���[�̃J�b�g�C����1�b�`��
			m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_PLAYER]->Update();
			//if (�v���C���[�̃J�b�g�C���̕`�悪�I�������)
			if (m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_PLAYER]->IsOn() == false)
			{
				//�u�����I�v�̕`����I��
				m_p_callout_ui->IsNotOn();
				//torigger��on�ɂ���
				m_player_trigger = true;
				m_pcutin_trigger = false;
			}
		}
		if (m_ecutin_trigger == true)
		{
			//�G�l�~�[�̃J�b�g�C����1�b�`��
			m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY]->Update();
			//if (�G�l�~�[�̃J�b�g�C���̕`�悪�I�������)
			if (m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY]->IsOn() == false)
			{
				//�u�����I�v�̕`����I��
				m_p_callout_ui->IsNotOn();
				//torigger��on�ɂ���
				m_enemy_trigger = true;
				m_ecutin_trigger = false;
			}
		}
		//m_is_trigger��on�Ȃ�
		//if (�G�l�~�[���v���C���[�Ƌ߂Â��Ă��Ȃ�������)
		if (m_enemy_trigger == true)
		{
			//�G�l�~�[���v���C���[�ɋ߂Â�
			if (CollisionRect() == false)
			{
				//�G�l�~�[���v���C���[�ɋ߂Â�
				m_p_enemy->GoToApproach();
			}
			else
			{
				// �߂Â��̂���߂�
				m_p_enemy->StopApproach();
				//�v���C���[��HP�����炷
				m_p_player->HpDown();
				//�v���C���[��HPUI�����炷
				HpUiManager(BATTLE_CHARACTER::BATTLE_PLAYER);
				//�G�l�~�[�̃J�E���g�����Z�b�g
				m_p_enemy->SetQuickPressFlame();
				//torigger��off�ɂ���
				m_enemy_trigger = false;
			}
		}
		//m_is_trigger��on�Ȃ�
		if (m_player_trigger == true)
		{
			//if (�v���C���[���G�l�~�[�Ƌ߂Â��Ă��Ȃ�������)
			if (CollisionRect() == false)
			{
				//�v���C���[���G�l�~�[�ɋ߂Â�
				m_p_player->GoToApproach();
			}
			else
			{
				// �߂Â��̂���߂�
				m_p_player->StopApproach();
				//�G�l�~�[��HP�����炷
				m_p_enemy->HpDown();
				//�G�l�~�[��HPUI�����炷
				HpUiManager(BATTLE_CHARACTER::BATTLE_ENEMY);
				//�G�l�~�[�̃J�E���g�����Z�b�g
				m_p_enemy->SetQuickPressFlame();
				//torigger��off�ɂ���
				m_player_trigger = false;
			}
		}
	}
	m_p_player->Update();
	m_p_enemy->Update();

	// HPUI�̕`��
	for (int i = 0; i < (int)BATTLE_CHARACTER::BATTLE_MAX; i++)
	{
		if (m_p_hp_ui[i] != nullptr)
		{
			m_p_hp_ui[i]->Update();
		}
	}
}

bool CharacterManager::CollisionRect() 
{
	Rect rp ,re;
	// �v���C���[
	rp = {
		m_p_player->GetPosX(),
		m_p_player->GetPosY(),
		m_p_player->GetWidth(),
		m_p_player->GetHeight()
	};
	// �G�l�~�[
	re = {
		m_p_enemy->GetPosX(),
		m_p_enemy->GetPosY(),
		m_p_enemy->GetWidth(),
		m_p_enemy->GetHeight()
	};

	if (m_collision.IsHitCaracter(rp, re) == true) 
	{
		// �Փ˂����ꍇ
		return true;
	}
	else 
	{
		// �Փ˂��Ă��Ȃ��ꍇ
		return false;
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

	for (int i = 0; i < (int)BATTLE_CHARACTER::BATTLE_MAX; i++)
	{
		if (m_p_cut_in[i] != nullptr)
		{
			m_p_cut_in[i]->Draw();
		}
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
				delete m_p_cut_in[i];
				m_p_cut_in[i] = nullptr;

				delete m_p_hp_ui[i];
				m_p_hp_ui[i] = nullptr;
			}

			delete m_p_callout_ui;
			m_p_callout_ui = nullptr;

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
		return false;
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
		/*if (GetNextEnemyID() == ENEMY_ID::ENMEY_NONE)
		{
			return GAME_END::GAME_CLEAR;
		}*/
		if (m_enemy_id == ENEMY_ID::FOX)
		{
			return GAME_END::GAME_CLEAR;
		}
	}
	return GAME_END::GAME_NONE;
}

// �G���؂�ւ���Ă���̃J�b�g�C���̕`��ύX���܂�
ENEMY_ID CharacterManager::GetNextEnemyID()
{
	// �V���O���g���̎��Ԃ��擾
	DataBank::CreateInstance();
	DataBank* p_db = DataBank::GetInstance();	// ���̂��擾

	switch (m_enemy_id)
	{
	case ENEMY_ID::DRAWER:
		m_enemy_id = ENEMY_ID::PERRY;
		p_db->SetEnemyType(static_cast<int>(m_enemy_id));
		m_cutin_id = CutIn::CutInType::PERRY;
		p_db->SetCutInType(static_cast<int>(m_cutin_id));
		break;
	case ENEMY_ID::PERRY:
		m_enemy_id = ENEMY_ID::HERMIT;
		p_db->SetEnemyType(static_cast<int>(m_enemy_id));
		m_cutin_id = CutIn::CutInType::HERMIT;
		p_db->SetCutInType(static_cast<int>(m_cutin_id));
		break;
	case ENEMY_ID::HERMIT:
		m_enemy_id = ENEMY_ID::SINSENGUMI;
		p_db->SetEnemyType(static_cast<int>(m_enemy_id));
		m_cutin_id = CutIn::CutInType::SINSENGUMI;
		p_db->SetCutInType(static_cast<int>(m_cutin_id));
		break;
	case ENEMY_ID::SINSENGUMI:
		m_enemy_id = ENEMY_ID::FOX;
		p_db->SetEnemyType(static_cast<int>(m_enemy_id));
		m_cutin_id = CutIn::CutInType::FOX;
		p_db->SetCutInType(static_cast<int>(m_cutin_id));
		break;
	}
	return m_enemy_id;
}

void CharacterManager::ChangeNextEnemy()
{
	m_enemy_id = GetNextEnemyID();
}