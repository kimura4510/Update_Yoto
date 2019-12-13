#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "CharacterID.h"

class Character {
public:
	enum class GAME_END {
		GAME_CLEAR,
		GAME_OVER,

		GAME_END_MAX,
	};

public:
	//Character();
	virtual ~Character() {}

public:
	virtual void Init() = 0;
	virtual void Draw() = 0;
	virtual void Update() = 0;

	/*CHARACTER_HP GetHp();*/
	virtual int GetHp() = 0;
	virtual void HpDown() = 0;

	/*virtual bool PlayerHpDown();
	virtual bool EnemyHpDown();*/
	
	//int OpponetHpDown(HP_DOWN hp_down_chara_);
	/*HP_DOWN PlayerHpDown();
	HP_DOWN EnemyHpDown();*/

	virtual int GetQuickPressFlame() { return m_quick_press_flame; }
	virtual void QuickPressFlameDown() {}
	//void QuickPressFlameReset();

	virtual ENEMY_ID GetEnemyID();
	virtual void ChangeEnemy(ENEMY_ID next_id_);

	virtual GAME_END GameOver();
	virtual GAME_END GameClear();

protected:
	bool m_isdeth;
	float m_x, m_y, m_z;
	int m_hp;

	float m_quick_press_flame;

	/*CHARACTER_HP m_character_hp;*/
};

#endif