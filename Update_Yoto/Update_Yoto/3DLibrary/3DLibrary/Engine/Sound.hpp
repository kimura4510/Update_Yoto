#ifndef SOUND_H_
#define SOUND_H_

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
	* @brief プライマリ・バッファの作成関数
	* @return 作成できた場合はtrue、失敗した場合はfalse
	*/
	bool CreatePrimaryBuffer();

	/**
	* @brief waveデータの読み込み関数
	* 指定したパスのwaveデータをセカンダリ・バッファに読み込みます
	* @return 成功した場合はtrue、そうでないならfalse
	* @param[in] file_name 読み込むパスを含むファイル名
	*/
	bool LoadSound(const char* file_name);

public:
	//シングルトン
	/**
	* @biref インスタンス作成関数
	*/
	static void CreateInstance()
	{
		if (IsInstanceNULL() == true)
		{
			p_SoundInstance = new Sound;
		}
	}

	/**
	* @brief インスタンス破棄関数
	*/
	static void DestroyInstance()
	{
		if (IsInstanceNULL() == false)
		{
			delete p_SoundInstance;
			p_SoundInstance = NULL;
		}
	}

	/**
	* @brief インスタンスNULL確認関数
	* インスタンスがnullか確認する関数です
	* @return nullの場合true、そうでないならfalse
	*/
	static bool IsInstanceNULL()
	{
		return p_SoundInstance == NULL;
	}

	/**
	* @biref インスタンス取得関数
	*/
	static Sound* GetInstance()
	{
		return p_SoundInstance;
	}

private:
	/**
	* @brief セカンダリ・バッファの作成関数
	* @return 作成できた場合はtrue、失敗した場合はfalse
	* この関数はLoadSound内で処理されているため、使用する必要はありません
	*/
	bool CreateSecondaryBuffer(MMCKINFO sound_data);

private:
	Sound() { }
	~Sound() { }
	LPDIRECTSOUND8 m_pSound;
	LPDIRECTSOUNDBUFFER m_pPrimary;
	LPDIRECTSOUNDBUFFER8 m_pSoundData;

	static Sound* p_SoundInstance;
};


#endif