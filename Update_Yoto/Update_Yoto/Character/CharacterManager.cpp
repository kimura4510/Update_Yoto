#include "CharacterManager.h"
#include "Player/Player.h"
#include "Enemy/Enemies/Drawer.h"
#include "Enemy/Enemies/Perry.h"
#include "Enemy/Enemies/Hermit.h"
#include "Enemy/Enemies/Sinsengumi.h"
#include "Enemy/Enemies/Fox.h"
#include "../3DLibrary/3DLibrary/Engine/Input.hpp"
#include "../DataBank/DataBank.h"
#include "../3DLibrary/3DLibrary/Engine/Camera.h"

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

	if (m_p_player == nullptr && m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_PLAYER] == nullptr)
	{
		m_p_player = new Player;
		if (m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_PLAYER] == nullptr)
		{
			m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_PLAYER] = new CutIn(
			CutIn::DrawMethod::LEFT,
			CutIn::CutInType::PLAYER);
		}
	}

	// �G�̓���ւ�����
	m_enemy_id = static_cast<ENEMY_ID>(p_db->GetEnemyType());
	if (m_p_enemy == nullptr && m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY] == nullptr)
	{
		switch (m_enemy_id)
		{
		case ENEMY_ID::DRAWER:
			m_p_enemy = new Drawer;
			m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY] = new CutIn(
			CutIn::DrawMethod::RIGHT,
			CutIn::CutInType::DRAWER);
			break;
		case ENEMY_ID::PERRY:
			m_p_enemy = new Perry;
			m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY] = new CutIn(
			CutIn::DrawMethod::RIGHT,
			CutIn::CutInType::PERRY);
			break;
		case ENEMY_ID::HERMIT:
			m_p_enemy = new Hermit;
			m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY] = new CutIn(
			CutIn::DrawMethod::RIGHT,
			CutIn::CutInType::HERMIT);
			break;
		case ENEMY_ID::SINSENGUMI:
			m_p_enemy = new Sinsengumi;
			m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY] = new CutIn(
			CutIn::DrawMethod::RIGHT,
			CutIn::CutInType::SINSENGUMI);
			break;
		case ENEMY_ID::FOX:
			m_p_enemy = new Fox;
			m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY] = new CutIn(
			CutIn::DrawMethod::RIGHT,
			CutIn::CutInType::FOX);
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

	if (m_p_player == nullptr && m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_PLAYER] == nullptr)
	{
		m_p_player = new Player;
		if (m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_PLAYER] == nullptr)
		{
			m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_PLAYER] = new CutIn(
				CutIn::DrawMethod::LEFT,
				CutIn::CutInType::PLAYER);
		}
	}

	// �G�̓���ւ�����
	m_enemy_id = static_cast<ENEMY_ID>(p_db->GetEnemyType());
	if (m_p_enemy == nullptr && m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY] == nullptr)
	{
		switch (m_enemy_id)
		{
		case ENEMY_ID::DRAWER:
			m_p_enemy = new Drawer;
			m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY] = new CutIn(
				CutIn::DrawMethod::RIGHT,
				CutIn::CutInType::DRAWER);
			break;
		case ENEMY_ID::PERRY:
			m_p_enemy = new Perry;
			m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY] = new CutIn(
				CutIn::DrawMethod::RIGHT,
				CutIn::CutInType::PERRY);
			break;
		case ENEMY_ID::HERMIT:
			m_p_enemy = new Hermit;
			m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY] = new CutIn(
				CutIn::DrawMethod::RIGHT,
				CutIn::CutInType::HERMIT);
			break;
		case ENEMY_ID::SINSENGUMI:
			m_p_enemy = new Sinsengumi;
			m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY] = new CutIn(
				CutIn::DrawMethod::RIGHT,
				CutIn::CutInType::SINSENGUMI);
			break;
		case ENEMY_ID::FOX:
			m_p_enemy = new Fox;
			m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY] = new CutIn(
				CutIn::DrawMethod::RIGHT,
				CutIn::CutInType::FOX);
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
		if (m_p_enemy->GetHp() >= 1)
		{
			m_p_enemy->Wait();
		}
		else
		{
			// �G�l�~�[���|���A�j���[�V����
			if (m_p_enemy->Dead() == false)
			{
				m_p_enemy->Fall();
			}
			else
			{
				// �v���C���[����ʂ���o�Ă����A�j���[�V����
				m_p_player->Walk();
				if (m_p_player->GetPosX() >= 768.0f)
				{
					m_p_player->StopWalk();
				}
			}
		}
		if (m_p_player->GetHp() <= 0)
		{
			// �v���C���[���|���A�j���[�V����
			if (m_p_player->Dead() == false)
			{
				m_p_player->Fall();
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
void CharacterManager::PlayerStandBy()
{
	if (m_p_player->GetPosX() <= 512.0f - 128.0f)
	{
		m_p_player->Walk();
	}
	else
	{
		m_p_player->StopWalk();
		m_p_player->HoldWeapon();
		if (m_p_player->HoldWeapon() == true)
		{
			m_p_player->Wait();
			Battle();
		}
	}
}
void CharacterManager::Battle()
{
	Camera::GetCameraInstance()->UpdateCamera();
	Input* input = Input::GetInputInstance();

	//�u�����I�v�̕`��܂ł̃J�E���g���n�߂�
	m_p_callout_ui->Update();
	//if (�J�E���g��0�ɂȂ�����u�����I�v��`��)
	if (m_p_callout_ui->IsOn() == true)
	{
		// �v���C���[���G���^�[�L�[�������Ă��Ȃ�������
		//�u�����I�v��`�撆�ɃG�l�~�[�̃J�E���g�����炷
		if (m_pcutin_trigger == false)
		{
			m_p_enemy->QuickPressFlameDown();
		}

		//if (�v���C���[���G���^�[�L�[����������)
		if ((input->GetKeyDown(KEY_INFO::ENTER_KEY) == true ||
			input->GetGamePadBottonState(0, GAMEPAD_BUTTONS::A) == INPUT_STATE::PUSH_DOWN) &&
			m_pcutin_trigger == false &&
			m_ecutin_trigger == false)
		{
			m_pcutin_trigger = true;
		}
		//if (�G�l�~�[�̃J�E���g��0�ȉ��ɂȂ�����)
		if (m_p_enemy->GetQuickPressFlame() <= 0 &&
			m_ecutin_trigger == false &&
			m_pcutin_trigger == false)
		{
			m_ecutin_trigger = true;
			// ���Z�b�g
			m_p_enemy->SetQuickPressFlame();
		}
	}
	else
	{
		// ����t��
		if (input->GetKeyDown(KEY_INFO::ENTER_KEY) == true ||
			input->GetGamePadBottonState(0, GAMEPAD_BUTTONS::A) == INPUT_STATE::PUSH_DOWN)
		{
			// �v���C���[��HP�����炷
			m_p_player->HpDown();
			HpUiManager(BATTLE_CHARACTER::BATTLE_PLAYER);
			m_p_enemy->SetQuickPressFlame();
		}
	}

	if (m_pcutin_trigger == true)
	{
		//�v���C���[�̃J�b�g�C����`��
		m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_PLAYER]->Update();
		Camera::GetCameraInstance()->ChangeCameraPos(CameraState::WinningPlayer);
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
		//�G�l�~�[�̃J�b�g�C����`��
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

	if (m_enemy_trigger == true)
	{
		// �v���C���[�ɍU������A�j���[�V����
		if (m_p_enemy->Attack() == true)
		{
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
	if (m_player_trigger == true)
	{
		// �G�l�~�[�ɍU������A�j���[�V����
		if (m_p_player->Attack() == true)
		{
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
		return true;	// �Փ˂����ꍇ
	}
	else 
	{
		return false;	// �Փ˂��Ă��Ȃ��ꍇ
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
		if (m_p_player->Dead() == true || m_p_player->GetPosX() >= 768.0f)
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
	if (m_p_player->Dead() == true || m_p_player->GetPosX() >= 768.0f)//m_p_enemy->GetHp() <= 0)
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
	if (m_p_player->Dead() == true)
	{
		return GAME_END::GAME_OVER;
	}
	if (m_p_enemy->Dead() == true)
	{
		//���̃L���������Ȃ�������N���A��Ԃ�
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
		break;
	case ENEMY_ID::PERRY:
		m_enemy_id = ENEMY_ID::HERMIT;
		p_db->SetEnemyType(static_cast<int>(m_enemy_id));
		break;
	case ENEMY_ID::HERMIT:
		m_enemy_id = ENEMY_ID::SINSENGUMI;
		p_db->SetEnemyType(static_cast<int>(m_enemy_id));
		break;
	case ENEMY_ID::SINSENGUMI:
		m_enemy_id = ENEMY_ID::FOX;
		p_db->SetEnemyType(static_cast<int>(m_enemy_id));
		break;
	}
	return m_enemy_id;
}

void CharacterManager::ChangeNextEnemy()
{
	m_enemy_id = GetNextEnemyID();
}