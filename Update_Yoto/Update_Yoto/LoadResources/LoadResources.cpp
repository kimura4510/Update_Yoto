#include"../LoadResources/LoadResources.h"
#include"../TextureId/TextureId.h"

namespace LoadResources {

	void Load() {
		cTexture* tex = cTexture::GetTextureInstance();

		tex->LoadTexture("Resource/Transition/SceneSwitching.png", transition);

		// 3D空間
		tex->LoadTexture("Resource/BackGround/kabe20200119.png", background);		// 背景
		tex->LoadTexture("Resource/BackGround/yuka_0002 1.png", ground);			// 地面


		// キャラクター
			// 左側
				// プレイヤー
		tex->LoadTexture("Resource/Character/LeftCharacter/walk.png", player_walk_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/WalkWait.png", player_walk_wait_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/Wait.png", player_wait_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/Attack1.png", player_attack_01_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/RightAttack2.png", player_r_attack_02_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/LeftAttack2.png", player_l_attack_02_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/Defence1.png", player_defence_01_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/RightDefence2.png", player_r_defence_02_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/LeftDefence2.png", player_l_defence_02_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/RightAttackCross.png", player_r_attack_cross_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/LeftAttackCross.png", player_l_attack_cross_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/RightDefenceCross.png", player_r_defence_cross_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/LeftDefenceCross.png", player_l_defence_cross_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/RightFlick.png", player_r_frick_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/LeftFlick.png", player_l_frick_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/RightKill.png", player_r_kill_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/LeftKill.png", player_l_kill_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/RightKillWalk.png", player_r_kill_walk_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/LeftKillWalk.png", player_l_kill_walk_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/RightBack.png", player_r_back_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/LeftBack.png", player_l_back_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/RightDeath.png", player_r_death_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/LeftDeath.png", player_l_death_anime);
			// 右側
				// 絵描き
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/Wait.png", drawer_wait_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/Attack1.png", drawer_attack_01_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/RightAttack2.png", drawer_r_attack_02_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/LeftAttack2.png", drawer_l_attack_02_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/Defence1.png", drawer_defence_01_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/RightDefence2.png", drawer_r_defence_02_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/LeftDefence2.png", drawer_l_defence_02_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/RightAttackCross.png", drawer_r_attack_cross_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/LeftAttackCross.png", drawer_l_attack_cross_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/RightDefenceCross.png", drawer_r_defence_cross_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/LeftDefenceCross.png", drawer_l_defence_cross_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/RightFrick.png", drawer_r_frick_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/LeftFrick.png", drawer_l_frick_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/RightKill.png", drawer_r_kill_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/LeftKill.png", drawer_l_kill_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/RightKillStand.png", drawer_r_kill_stand_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/LeftKillStand.png", drawer_l_kill_stand_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/RightBack.png", drawer_r_back_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/LeftBack.png", drawer_l_back_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/RightDeath.png", drawer_r_death_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/LeftDeath.png", drawer_l_death_anime);
				// ペリー
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/Wait.png", perry_wait_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/Attack1.png", perry_attack_01_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/RightAttack2.png", perry_r_attack_02_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/LeftAttack2.png", perry_l_attack_02_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/Defence1.png", perry_defence_01_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/RightDefence2.png", perry_r_defence_02_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/LeftDefence2.png", perry_l_defence_02_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/RightAttackCross.png", perry_r_attack_cross_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/LeftAttackCross.png", perry_l_attack_cross_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/RightDefenceCross.png", perry_r_defence_cross_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/LeftDefenceCross.png", perry_l_defence_cross_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/RightFlick.png", perry_r_frick_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/LeftFlick.png", perry_l_frick_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/RightKill.png", perry_r_kill_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/LeftKill.png", perry_l_kill_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/RightKillStand.png", perry_r_kill_stand_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/LeftKillStand.png", perry_l_kill_stand_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/RightBack.png", perry_r_back_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/LeftBack.png", perry_l_back_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/RightDeath.png", perry_r_death_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/LeftDeath.png", perry_l_death_anime);
				// 仙人
		tex->LoadTexture("Resource/Character/RightCharacter/Hermit/Hermit.png", hermit_tex);
				// 新選組
		tex->LoadTexture("Resource/Character/RightCharacter/Sinsengumi/Sinsengumi.png", sinsengumi_tex);
				// 狐
		tex->LoadTexture("Resource/Character/RightCharacter/Fox/Fox.png", fox_tex);


		// UI
		tex->LoadTexture("Resource/UI/ose_1pmode.png", calloutui_tex);
		tex->LoadTexture("Resource/UI/HP.png", hpui_tex);

			// 右側用
		tex->LoadTexture("Resource/UI/RightCutIn/Rhero.png", r_cutin_player_tex);
		tex->LoadTexture("Resource/UI/RightCutIn/Rjapan.png", r_cutin_drawer_tex);
		tex->LoadTexture("Resource/UI/RightCutIn/Rkuro.png", r_cutin_perry_tex);
		tex->LoadTexture("Resource/UI/RightCutIn/Rsennin.png", r_cutin_hermit_tex);
		tex->LoadTexture("Resource/UI/RightCutIn/Rsinsen.png", r_cutin_sinsengumi_tex);
		tex->LoadTexture("Resource/UI/RightCutIn/Rfox.png", r_cutin_fox_tex);
			// 左側用
		tex->LoadTexture("Resource/UI/LeftCutIn/Lhero.png", l_cutin_player_tex);
		tex->LoadTexture("Resource/UI/LeftCutIn/Ljapan.png", l_cutin_drawer_tex);
		tex->LoadTexture("Resource/UI/LeftCutIn/Lkuro.png", l_cutin_perry_tex);
		tex->LoadTexture("Resource/UI/LeftCutIn/Lsennin.png", l_cutin_hermit_tex);
		tex->LoadTexture("Resource/UI/LeftCutIn/Lsinsen.png", l_cutin_sinsengumi_tex);
		tex->LoadTexture("Resource/UI/LeftCutIn/Lfox.png", l_cutin_fox_tex);
		
	}
}