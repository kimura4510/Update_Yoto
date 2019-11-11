/**
* @file Window.h
* @brief ウィンドウに関係する外部公開関数、定数の宣言
*/

#ifndef WINDOW_H_
#define WINDOW_H_

#include <Windows.h>

#define WINDOW_CLASS_NAME "Window" //ウィンドウクラス名

/** ウィンドウ作成に関するクラス*/
class Window
{
public:
	/** ウィンドウを作成する関数@n
	* 引数で指定された内容でウィンドウを作成します
	* @return 作成結果、成功の場合はtrue
	* @param[in] instance インスタンスハンドル
	* @param[in] width 横幅
	* @param[in] height 縦幅
	* @param[in] title タイトルバーに表示される文字列
	*/
	HWND MakeWindow(HINSTANCE instance, int width, int height, const char* title);
};

#endif