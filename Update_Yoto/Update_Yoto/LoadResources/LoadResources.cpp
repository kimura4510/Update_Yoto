#include"../LoadResources/LoadResources.h"
#include"../TextureId/TextureId.h"



namespace LoadResources {

	void Load() {

		if (cTexture::GetTextureInstance()->
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
		}
	}
}