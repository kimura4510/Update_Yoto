#include"../LoadResources/LoadResources.h"
#include"../TextureId/TextureId.h"

namespace LoadResources {

	void Load() {
		cTexture* tex = cTexture::GetTextureInstance();

		// トランジションシーン
		tex->LoadTexture("Resource/Transition/rogo2.png", transition);

		// 3D空間
		tex->LoadTexture("Resource/BackGround/title1024.png", background);		// 背景
		tex->LoadTexture("Resource/BackGround/yuka_000_1.png", ground);			// 地面

		// キャラクター
		tex->LoadTexture("Resource/Character/CharaAnime.png", chara_anime);

		tex->LoadTexture("Resource/Character/Player.png", player_tex);

		tex->LoadTexture("Resource/Character/Drawer.png", drawer_tex);
		tex->LoadTexture("Resource/Character/Perry.png", perry_tex);
		tex->LoadTexture("Resource/Character/Hermit.png", hermit_tex);
		tex->LoadTexture("Resource/Character/Sinsengumi.png", sinsengumi_tex);
		tex->LoadTexture("Resource/Character/Fox.png", fox_tex);

		// UI
		tex->LoadTexture("Resource/UI/Callout2048x1024.png", calloutui_tex);
		tex->LoadTexture("Resource/UI/HP.png", hpui_tex);

		// 右側用
		tex->LoadTexture("Resource/UI/RihtCutin.png", r_cutin_tex);
		// 左側用
		tex->LoadTexture("Resource/UI/LeftCutin.png", l_cutin_tex);
	}
}