#include"HpUI.h"
#include"../../3DLibrary/3DLibrary/Engine/Graphics.hpp"
#include"../../3DLibrary/3DLibrary/Texture/Texture.hpp"
#include"../../TextureId/TextureId.h"
#include"../../3DLibrary/3DLibrary/GameDefinition.h"

HpUI::HpUI(
	DrawType draw_type,
	DrawDirection dir,
	const float& pos_x,
	const float& pos_y,
	const float&graph_size_w,
	const float&graph_size_h
) {

	m_draw_type = DrawType::HP_MAX;
	m_draw_type = draw_type;
	m_dir = DrawDirection::RIGHT;
	m_dir = dir;

	m_pos_x = pos_x;
	m_pos_y = pos_y;
	m_tu = 0.127f;
	m_tv = 0.08f;
	m_width_size = graph_size_w;
	m_height_size = graph_size_h;
	m_split_num_x = 1;
	m_split_num_y = 1;

	// 方向変更
	ChangeHpType();
}

void HpUI::Update() {

	// 方向変更
	ChangeHpType();


	switch (m_draw_type) {

	case DrawType::HP_NONE:

		
		m_split_num_x = 1;
		//m_split_num_y = 1;
		break;

	case DrawType::HP_LITTLE:

		
		m_split_num_x = 2;
		//m_split_num_y = 1;
		break;

	case DrawType::HP_MEDIUM:

		
		m_split_num_x = 3;
		//m_split_num_y = 1;

		break;

	case DrawType::HP_MAX:

		
		m_split_num_x = 4;
		//m_split_num_y = 1;

		break;
	}
}


void HpUI::Draw() {
	Graphics* gp = Graphics::GetGraphicInstance();
	cTexture* tex = cTexture::GetTextureInstance();
	gp->DrawIntegratedImage(
		m_pos_x, m_pos_y,
		tex->GetTexture(hpui_tex),
		m_tu, m_tv,
		m_width_size, m_height_size,
		m_split_num_x, m_split_num_y);
}
