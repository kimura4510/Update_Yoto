#ifndef DATA_BANK_H_
#define DATA_BANK_H_

// Template_Class
template<class T>
class Singleton {
	//シングルトンデザインパターン
public:
	//実体を作る関数
	static void CreateInstance()
	{
		if (CheckNull() == true)
		{
			p_Instance = new T();
		}
	}
	//実体を破棄する関数
	static void DestroyInstance()
	{
		if (!CheckNull() == false)
		{
			delete p_Instance;
		}
	}
	//実体が存在するか確認する変数
	static bool CheckNull()
	{
		return p_Instance == nullptr;
	}

	//実体を取得する関数
	static T* GetInstance()
	{
		return p_Instance;
	}

protected:
	Singleton() {}			//コンストラクタ抑制
	~Singleton() {}			//デストラクタ抑制

private:
	static T* p_Instance;		//自分自身の唯一の実体

};

//staticなメンバ変数を初期化
template<class T>
T* Singleton<T>::p_Instance = nullptr;




// DataBank_Class
class DataBank :public Singleton<DataBank> {
private:
	friend Singleton<DataBank>;

public:
	void SetEnemyType(int enemy_type_);
	int GetEnemyType();

	void SetCutInType(int cutn_type_);
	int GetCutInType();

private:
	DataBank() { m_enemy_type = 0; }
	virtual ~DataBank() {}

	// コピーコンストラクタの禁止
	DataBank(const DataBank&);
	DataBank& operator = (const DataBank&) = delete;
	// ムーブコンストラクタの禁止
	DataBank& operator = (const DataBank&&) = delete;

private:
	int m_enemy_type;
	int m_cutin_type;

};

#endif