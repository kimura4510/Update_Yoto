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
	// シングルトンの実態を破棄
	DataBank::DestroyInstance();
}

void CharacterManager::Init()
{
	// シングルトンの実態を取得
	DataBank::CreateInstance();
	DataBank* p_db = DataBank::GetInstance();	// 実体を取得

	if (m_p_player == nullptr)
	{
		m_p_player = new Player;
	}

	// 敵の入れ替え処理
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
	// プレイヤーのカットイン
	if (m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_PLAYER] == nullptr)
	{
		m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_PLAYER] = new CutIn(
			CutIn::DrawMethod::LEFT,
			CutIn::CutInType::PLAYER,
			0.0f, 300.0f);
	}
	// エネミーのカットイン
	if (m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY] == nullptr)
	{
		m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY] = new CutIn(
			CutIn::DrawMethod::RIGHT,
			m_cutin_id,
			896.0f, 300.0f);
	}

	// プレイヤーのHPゲージ
	if (m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_PLAYER] == nullptr)
	{
		m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_PLAYER] = new HpUI(
			HpUI::DrawType::HP_MAX,
			HpUI::DrawDirection::RIGHT,
			0.0f,
			0.0f);
	}
	// エネミーのHPゲージ
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
	// シングルトンの実態を取得
	DataBank::CreateInstance();
	DataBank* p_db = DataBank::GetInstance();	// 実体を取得

	if (m_p_player == nullptr)
	{
		m_p_player = new Player;
	}

	// 敵の入れ替え処理
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
	// プレイヤーのカットイン
	if (m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_PLAYER] == nullptr)
	{
		m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_PLAYER] = new CutIn(
			CutIn::DrawMethod::LEFT,
			CutIn::CutInType::PLAYER,
			0.0f, 300.0f);
	}
	// エネミーのカットイン
	if (m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY] == nullptr)
	{
		m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY] = new CutIn(
			CutIn::DrawMethod::RIGHT,
			m_cutin_id,
			896.0f, 300.0f);
	}

	// プレイヤーのHPゲージ
	if (m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_PLAYER] == nullptr)
	{
		m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_PLAYER] = new HpUI(
			HpUI::DrawType::HP_MAX,
			HpUI::DrawDirection::RIGHT,
			0.0f,
			0.0f);
	}
	// エネミーのHPゲージ
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

	//if (プレイヤーとエネミーが生きていたら)
	if (m_p_player != nullptr && m_p_enemy != nullptr)
	{
		//「押せ！」の描画までのカウントを始める
		m_p_callout_ui->Update();
		//if (カウントが0になったら「押せ！」を描画)
		if (m_p_callout_ui->IsOn() == true)
		{
			//「押せ！」を描画中にエネミーのカウントを減らす
			if (m_pcutin_trigger == false) 
			{
				m_p_enemy->QuickPressFlameDown();
			}

			//if (プレイヤーがエンターキーを押したら)
			if (Input::GetInputInstance()->GetKeyDown(KEY_INFO::ENTER_KEY) == true && m_pcutin_trigger == false)
			{
				m_pcutin_trigger = true;
				// リセット
				m_p_enemy->SetQuickPressFlame();
			}
			//if (エネミーのカウントが0以下になったら)
			if (m_p_enemy->GetQuickPressFlame() <= 0 && m_ecutin_trigger == false)
			{
				m_ecutin_trigger = true;
				// リセット
				m_p_enemy->SetQuickPressFlame();
			}
		}
		else
		{
			// お手付き
			if (Input::GetInputInstance()->GetKeyDown(KEY_INFO::ENTER_KEY) == true)
			{
				// プレイヤーのHPを減らす
				m_p_player->HpDown();
				HpUiManager(BATTLE_CHARACTER::BATTLE_PLAYER);
				m_p_enemy->SetQuickPressFlame();
			}
		}

		if (m_pcutin_trigger == true)
		{
			//プレイヤーのカットインを1秒描画
			m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_PLAYER]->Update();
			//if (プレイヤーのカットインの描画が終わったら)
			if (m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_PLAYER]->IsOn() == false)
			{
				//「押せ！」の描画を終了
				m_p_callout_ui->IsNotOn();
				//toriggerをonにする
				m_player_trigger = true;
				m_pcutin_trigger = false;
			}
		}
		if (m_ecutin_trigger == true)
		{
			//エネミーのカットインを1秒描画
			m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY]->Update();
			//if (エネミーのカットインの描画が終わったら)
			if (m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_ENEMY]->IsOn() == false)
			{
				//「押せ！」の描画を終了
				m_p_callout_ui->IsNotOn();
				//toriggerをonにする
				m_enemy_trigger = true;
				m_ecutin_trigger = false;
			}
		}
		//m_is_triggerをonなら
		//if (エネミーがプレイヤーと近づいていなかったら)
		if (m_enemy_trigger == true)
		{
			//エネミーがプレイヤーに近づく
			if (CollisionRect() == false)
			{
				//エネミーがプレイヤーに近づく
				m_p_enemy->GoToApproach();
			}
			else
			{
				// 近づくのをやめる
				m_p_enemy->StopApproach();
				//プレイヤーのHPを減らす
				m_p_player->HpDown();
				//プレイヤーのHPUIを減らす
				HpUiManager(BATTLE_CHARACTER::BATTLE_PLAYER);
				//エネミーのカウントをリセット
				m_p_enemy->SetQuickPressFlame();
				//toriggerをoffにする
				m_enemy_trigger = false;
			}
		}
		//m_is_triggerをonなら
		if (m_player_trigger == true)
		{
			//if (プレイヤーがエネミーと近づいていなかったら)
			if (CollisionRect() == false)
			{
				//プレイヤーがエネミーに近づく
				m_p_player->GoToApproach();
			}
			else
			{
				// 近づくのをやめる
				m_p_player->StopApproach();
				//エネミーのHPを減らす
				m_p_enemy->HpDown();
				//エネミーのHPUIを減らす
				HpUiManager(BATTLE_CHARACTER::BATTLE_ENEMY);
				//エネミーのカウントをリセット
				m_p_enemy->SetQuickPressFlame();
				//toriggerをoffにする
				m_player_trigger = false;
			}
		}
	}
	m_p_player->Update();
	m_p_enemy->Update();

	// HPUIの描画
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
	// プレイヤー
	rp = {
		m_p_player->GetPosX(),
		m_p_player->GetPosY(),
		m_p_player->GetWidth(),
		m_p_player->GetHeight()
	};
	// エネミー
	re = {
		m_p_enemy->GetPosX(),
		m_p_enemy->GetPosY(),
		m_p_enemy->GetWidth(),
		m_p_enemy->GetHeight()
	};

	if (m_collision.IsHitCaracter(rp, re) == true) 
	{
		// 衝突した場合
		return true;
	}
	else 
	{
		// 衝突していない場合
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
	// プレイヤーのHPUI表示
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
	// エネミーのHPUI表示
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
		//次のキャラぎいなかったらクリアを返す
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

// 敵が切り替わってからのカットインの描画変更がまだ
ENEMY_ID CharacterManager::GetNextEnemyID()
{
	// シングルトンの実態を取得
	DataBank::CreateInstance();
	DataBank* p_db = DataBank::GetInstance();	// 実体を取得

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