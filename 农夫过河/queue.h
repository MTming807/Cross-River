#pragma once
#include "state.h"

class MyQueue
{
public:
	MyQueue(int queueCapacity);   //��������
	virtual ~MyQueue();    //���ٶ���

	void ClearQueue();   //��ն���
	bool QueueEmpty() const;   //�пն���
	int QueueLength() const;   //���г���
	bool QueueFull() const;    //�����Ƿ���

	bool EnQueue(state element);  //��Ԫ�����
	state DeQueue();   //��Ԫ�س���
	void QueueTraverse();    //��������

	bool checksaved(state nowstate);//���״̬�����û��˼·�����ö��б���·����ͬʱ�����ö����Ƿ������ͬ״̬
	bool checkshit(state nowstate);

	state getTailQueue();

private:
	state *m_pQueue;     //��������ָ��
	int m_iQueueLen;     //����Ԫ�ظ���
	int m_iQueueCapacity;   //������������

	int m_iHead;  //��ͷ
	int m_iTail;   //��β
};