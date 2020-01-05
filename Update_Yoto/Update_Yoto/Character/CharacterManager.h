#ifndef CHARACTER_MANAGER_H_
#define CHARACTER_MANAGER_H_

#include "Character.h"
#include "../UI/CalloutUI/CalloutUI.h"
#include "../UI/HpUI/HpUI.h"

class CharacterManager {
public:
	CharacterManager();
	virtual ~CharacterManager();

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
	//void DeleteCheck();

private:
	Character* m_p_player;
	Character* m_p_enemy;

	CalloutUI* m_p_callout_ui;
	HpUI* m_p_hp_ui[(int)BATTLE_CHARACTER::BATTLE_MAX];

	ENEMY_ID m_enemy_id;

};

#endif