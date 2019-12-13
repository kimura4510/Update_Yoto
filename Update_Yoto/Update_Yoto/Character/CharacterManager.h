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
	void Create();
	void Draw();
	void Update();
	bool PlayerIsExit();
	bool EnemyIsExit();
	void Release();

	int GameEnd(Character::GAME_END game_end_id_);

private:
	Character* m_p_player;
	Character* m_p_enemy;

	CalloutUI* m_p_callout_ui;
	HpUI* m_p_hp_ui[2];

};

#endif