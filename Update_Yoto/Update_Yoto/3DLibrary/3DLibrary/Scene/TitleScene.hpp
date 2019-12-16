#ifndef TITLESCENE_H_
#define TITLESCENE_H_

#include "BaseScene.hpp"
#include <string>

//!< Title用テクスチャリストキー
const std::string title = "Title";
const std::string menu = "Menu";

enum class DisplayState :int
{
	Title,
	PvE,
	PvP,
	Help,
};

class TitleScene : public BaseScene
{
public:
	~TitleScene() override { }
	void Init() override;
	void Update() override;
	SceneID End() override;
	void Draw() override;
	SceneID Control() override;

private:
	DisplayState m_DisplayState;
	int m_DisplayNum;
};

#endif