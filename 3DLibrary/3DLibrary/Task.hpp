#ifndef TASK_H_
#define TASK_H_


/**
* @brief Task�N���X@n
* �������A�I���A�X�V�A�`��������N���X@n
*/
class Task
{
public:
	virtual ~Task() {}

	// ����������
	virtual void Init() {}

	// �I������ 
	virtual void End()	{}

	// �X�V�����A�p����ŕK����������
	virtual void Update() = 0;

	// �`�揈���A�p����ŕK����������
	virtual void Draw() = 0;
};

#endif