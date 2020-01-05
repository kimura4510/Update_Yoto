#include"../LoadResources/LoadResources.h"
#include"../TextureId/TextureId.h"



namespace LoadResources {

	void Load() {

		/*if (cTexture::GetTextureInstance()->
			LoadTexture("Resource/UI/Callout2048x1024.png", (int)CategoryId::UI, (int)TextureId::CALLOUT)
			== false) {
			return;
		}

		if (cTexture::GetTextureInstance()->
			LoadTexture("Resource/UI/HP.png", (int)CategoryId::UI, (int)TextureId::HP)
			== false) {

			float hoge;
			hoge = 0;

			return;
		}*/

		//cTexture::GetTextureInstance()->LoadTexture("Resource/UI/Callout2048x1024.png", "call_out");

		//exture::GetTextureInstance()->LoadTexture()



		cTexture* tex = cTexture::GetTextureInstance();

		tex->LoadTexture("Resource/BackGround/title1024.png", background);

		tex->LoadTexture("Resource/Character/CharaAnime.png", chara_anime);

		tex->LoadTexture("Resource/Character/Player.png", player_tex);

		tex->LoadTexture("Resource/Character/Drawer.png", drawer_tex);
		tex->LoadTexture("Resource/Character/Perry.png", perry_tex);
		tex->LoadTexture("Resource/Character/Hermit.png", hermit_tex);
		tex->LoadTexture("Resource/Character/Sinsengumi.png", sinsengumi_tex);
		tex->LoadTexture("Resource/Character/Fox.png", fox_tex);

		tex->LoadTexture("Resource/UI/Callout2048x1024.png", calloutui_tex);
		tex->LoadTexture("Resource/UI/HP.png", hpui_tex);

	}
}