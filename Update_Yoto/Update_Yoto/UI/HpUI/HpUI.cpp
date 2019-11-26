#include"HpUI.h"
#include"../../3DLibrary/3DLibrary/Engine/Graphics.hpp"
#include"../../3DLibrary/3DLibrary/Texture/Texture.hpp"
#include"../../TextureId/TextureId.h"



void HpUI::Update() {

}

void HpUI::Draw() {

	// テクスチャ取得
	Texture *hp = 
		cTexture::GetTextureInstance()->GetTexture(0, (int)TextureId::HP);

	// HP描画
	Graphics::GetGraphicInstance()->DrawTexture(500.f,500.f,hp);

	// 分割して描画
	Graphics::GetGraphicInstance()->DrawIntegratedImage(
		1920.f / 2,
		1080.f / 2,
		hp,
		0.2,
		0.2,
		0.f,
		0.f,
		0,
		0
	);

}
