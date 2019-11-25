#pragma once
#include"../../3DLibrary/3DLibrary/Engine/Graphics.hpp"


// 基底のアニメーション
class CharacterAnimationBase{
public:

	// アニメーションの種類
	enum AnimationType {
		WAIT,
		MOVE,
		ATTACK,
		DEFENCE,
	};
public:

	//CharacterAnimationBase() {};

	void Draw(float x,float y,Texture*texture) {

		graph.DrawTexture(x,y,texture);
	}


private:
	Graphics graph;
};
