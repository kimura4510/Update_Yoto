#ifndef CHARACTER_MANAGER_H_
#define CHARACTER_MANAGER_H_

#include "Character.h"
#include "../UI/CalloutUI/CalloutUI.h"
#include "../UI/HpUI/HpUI.h"
#include "../UI/CutIn/CutIn.h"
#include "../3DLibrary/3DLibrary/Engine/Collision.hpp"

class CharacterManager {
public:
	CharacterManager();
	~CharacterManager();

public:
	void Init();
	void Draw();
	void Update();
	void HpUiManager(BATTLE_CHARACTER battle_character_);

	void DeleteCheck();

	// ç≤ì°êÊê∂ÇÃÉRÅ[Éh
	bool IsBattleFinish();
	GAME_END GetGameEnd();
	ENEMY_ID GetNextEnemyID();
	void ChangeNextEnemy();

private:
	void Create();
	bool CollisionRect();

private:
	Character* m_p_player;
	Character* m_p_enemy;

	CalloutUI* m_p_callout_ui;
	CutIn* m_p_cut_in[(int)BATTLE_CHARACTER::BATTLE_MAX];
	HpUI* m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_MAX];

	CutIn::CutInType m_cutin_id;
	ENEMY_ID m_enemy_id;
	Collision m_collision;

	bool m_player_trigger;
	bool m_enemy_trigger;
	bool m_pcutin_trigger;
	bool m_ecutin_trigger;

};

#endif