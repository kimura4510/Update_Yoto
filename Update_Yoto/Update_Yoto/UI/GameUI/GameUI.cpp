#include"GameUI.h"
#include"../Lib/Sprite2D/Sprite2D/Sprite2DObject.h"


void GameUI::Draw() {

	//Sprite2DObject sp_obj;
	Sprite2DData data(500.f, 500.f, "HP");

	//data.

	// オブジェクトHP
	Sprite2DObject::GetInstance()->BoardDraw(data);
}

void GameUI::Update() {

}