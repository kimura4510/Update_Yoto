#ifndef DATA_BANK_H_
#define DATA_BANK_H_

// Template_Class
template<class T>
class Singleton {
	//�V���O���g���f�U�C���p�^�[��
public:
	//���̂����֐�
	static void CreateInstance()
	{
		if (CheckNull() == true)
		{
			p_Instance = new T();
		}
	}
	//���̂�j������֐�
	static void DestroyInstance()
	{
		if (!CheckNull() == false)
		{
			delete p_Instance;
		}
	}
	//���̂����݂��邩�m�F����ϐ�
	static bool CheckNull()
	{
		return p_Instance == nullptr;
	}

	//���̂��擾����֐�
	static T* GetInstance()
	{
		return p_Instance;
	}

protected:
	Singleton() {}			//�R���X�g���N�^�}��
	~Singleton() {}			//�f�X�g���N�^�}��

private:
	static T* p_Instance;		//�������g�̗B��̎���

};

//static�ȃ����o�ϐ���������
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

	// �R�s�[�R���X�g���N�^�̋֎~
	DataBank(const DataBank&);
	DataBank& operator = (const DataBank&) = delete;
	// ���[�u�R���X�g���N�^�̋֎~
	DataBank& operator = (const DataBank&&) = delete;

private:
	int m_enemy_type;
	int m_cutin_type;

};

#endif