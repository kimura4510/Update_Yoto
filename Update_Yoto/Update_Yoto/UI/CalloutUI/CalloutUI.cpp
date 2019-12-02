﻿#include"../CalloutUI/CalloutUI.h"
#include"../../3DLibrary/3DLibrary/Engine/Graphics.hpp"
#include"../../3DLibrary/3DLibrary/Texture/Texture.hpp"
#include"../../TextureId/TextureId.h"


void CalloutUI::Update() {


}


void CalloutUI::Draw() {


	// テクスチャ取得
	Texture* p_call_out = 
		cTexture::GetTextureInstance()->GetTexture((int)CategoryId::UI, (int)TextureId::CALLOUT);

	// HP描画
	//Graphics::GetGraphicInstance()->DrawTexture(500.f, 500.f, hp);

	// 分割して描画
	Graphics::GetGraphicInstance()->DrawIntegratedImage(
		(float)400.f,
		(float)400.f,
		p_call_out,
		0.2f,
		0.5f,
		1000.f,
		1000.f,
		1,
		1
	);
}