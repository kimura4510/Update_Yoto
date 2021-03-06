#ifndef TITLESCENE_H_
#define TITLESCENE_H_

#include "BaseScene.hpp"
#include <string>

enum class DisplayState :int
{
	Title,
	PvE,
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
	int m_IsExit;
	int m_FPScounter;
	int m_transparency;
	bool m_IsChange;
	float m_BambooPosX;
};

#endif