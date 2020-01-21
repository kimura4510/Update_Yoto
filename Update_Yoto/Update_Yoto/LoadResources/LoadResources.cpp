#include"../LoadResources/LoadResources.h"
#include"../TextureId/TextureId.h"

namespace LoadResources {

	void Load() {
		cTexture* tex = cTexture::GetTextureInstance();

		// トランジションシーン
		tex->LoadTexture("Resource/Transition/rogo2.png", transition);


		// 3D空間
		tex->LoadTexture("Resource/BackGround/kabe20200119.png", background);		// 背景
		tex->LoadTexture("Resource/BackGround/yuka_0002 1.png", ground);			// 地面


		// キャラクター
			// 左側
				// 仮
		tex->LoadTexture("Resource/Character/LeftCharacter/CharaAnime.png", chara_anime);
				// プレイヤー
		tex->LoadTexture("Resource/Character/LeftCharacter/Walk.png", walk_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/WalkWait.png", walk_to_standby_anime);
		tex->LoadTexture("Resource/Character/LeftCharacter/Wait.png", standby_anime);

			// 右側
				// 絵描き
		tex->LoadTexture("Resource/Character/RightCharacter/Drawer/Wait.png", drawer_wait_anime);
				// ペリー
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/Wait.png", perry_wait_anime);
		tex->LoadTexture("Resource/Character/RightCharacter/Perry/RightDeath.png", perry_die_anime);
				// 仙人
		tex->LoadTexture("Resource/Character/RightCharacter/Hermit/Hermit.png", hermit_tex);
				// 新選組
		tex->LoadTexture("Resource/Character/RightCharacter/Sinsengumi/Sinsengumi.png", sinsengumi_tex);
				// 狐
		tex->LoadTexture("Resource/Character/RightCharacter/Fox/Fox.png", fox_tex);


		// UI
		tex->LoadTexture("Resource/UI/Callout2048x1024.png", calloutui_tex);
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