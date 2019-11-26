#include"../LoadResources/LoadResources.h"
#include"../TextureId/TextureId.h"



namespace LoadResources {

	void Load() {

		cTexture::GetTextureInstance()->
			LoadTexture("Resource/UI/Callout2048x1024",0,(int)TextureId::CALLOUT);

		cTexture::GetTextureInstance()->
			LoadTexture("Resource/UI/HP.png",0,(int)TextureId::HP);
	}
}