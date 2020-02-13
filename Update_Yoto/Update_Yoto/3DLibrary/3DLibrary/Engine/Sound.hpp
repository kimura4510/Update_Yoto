#ifndef SOUND_H_
#define SOUND_H_

#include <dsound.h>
#include <unordered_map>
#include <string>

class Sound
{
public:
	/**
	* @brief サウンド初期化関数
	* DirectSoundを使用可能にするため初期化を行います
	* @return 成功の場合はtrue、失敗した場合はfalse
	*/
	bool InitSound(HWND hw);

	/**
	* @brief waveデータの読み込み関数
	* 指定したパスのwaveデータをセカンダリ・バッファに読み込みます
	* @return 成功した場合はtrue、そうでないならfalse
	* @param[in] file_name 読み込むパスを含むファイル名
	* @param[in] key_name 読み込むデータを管理するキー
	*/
	bool LoadSound(std::string file_name, std::string key_name);

	/**
	* @brief サウンド開放関数
	* 読み込んだデータとDirectSoundの解放を行います
	*/
	void ReleaseSound();

	/**
	* @brief サウンド再生関数
	* 指定したセカンダリ・バッファのサウンドを再生します
	* @param[in] key_ 再生したいサウンドのキー
	*/
	void Play(std::string key_);

	/**
	* @brief サウンド停止関数
	* 指定したセカンダリ・バッファのサウンドを停止します
	* @param[in] key_ 停止したいサウンドのキー
	*/
	void Stop(std::string key_);

	//シングルトン
	/**
	* @brief インスタンス生成関数@n
	* インスタンスを生成する関数です@n
	*/
	static void CreateInputInstance()
	{
		if (IsInputInstance_NULL() == true)
		{
			p_Instance = new Sound;
		}
	}

	/**
	* @brief インスタンス破棄関数@n
	* インスタンスを破棄する関数です@n
	*/
	static void DestroyInputInstance()
	{
		if (IsInputInstance_NULL() == false)
		{
			delete p_Instance;
			p_Instance = nullptr;
		}
	}

	/**
	* @brief インスタンス確認関数@n
	* インスタンスの有無を確認する関数です@n
	*/
	static bool IsInputInstance_NULL()
	{
		return p_Instance == nullptr;
	}

	/**
	* @brief インスタンス取得関数@n
	* インスタンスを取得する関数です@n
	*/
	static Sound* GetInputInstance()
	{
		return p_Instance;
	}
private:
	Sound() : m_pSound(nullptr) { }		//!< コンストラクタ
	~Sound() { }						//!< デストラクタ

private:
	LPDIRECTSOUND8 m_pSound;
	std::unordered_map <std::string, LPDIRECTSOUNDBUFFER8> m_pSoundData;

	static Sound* p_Instance;
};



#endif