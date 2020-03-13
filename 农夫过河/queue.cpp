#include <iostream>
#include "queue.h"
using namespace std;

MyQueue::MyQueue(int queueCapacity)
{
	m_iQueueCapacity = queueCapacity;

	//���г�ʼ��
	ClearQueue();//���ڳ�ʼ����ͷ����β������Ԫ�ظ���
				 //m_iHead = 0;//��ͷ��ʼ��
				 //m_iTail = 0;//��β��ʼ��
				 //m_iQueueLen = 0;//����Ԫ�ظ�����ʼ��

	m_pQueue = new state[m_iQueueCapacity];//Ϊ���з���m_iQueueCapacity���ռ�
}

//��������
MyQueue::~MyQueue()
{
	delete[]m_pQueue;
	m_pQueue = NULL;
}

//��ն���
void  MyQueue::ClearQueue()
{
	m_iHead = 0;//��ͷ��ʼ��
	m_iTail = 0;//��β��ʼ��
	m_iQueueLen = 0;//����Ԫ�ظ�����ʼ��
}

//�ж��Ƿ��ǿն���
bool MyQueue::QueueEmpty() const
{
	if (m_iQueueLen == 0)//�ж϶��г����Ƿ�Ϊ0������ʹ�ö�ͷ��βָ��Ϊ0
	{
		return true;
	}
	else
	{
		return false;
	}
}

//���г���
int MyQueue::QueueLength() const
{
	return m_iQueueLen;//ֱ�ӷ��ضӳ�
}

//�ж��Ƿ���������
bool MyQueue::QueueFull() const
{
	if (m_iQueueCapacity == m_iQueueLen)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//��Ԫ�����
bool MyQueue::EnQueue(state element)
{
	if (QueueFull())
	{
		cout << "����" << endl;
		return false;
	}
	else
	{
		m_pQueue[m_iTail] = element;
		m_iTail++;//��β�ƶ�
		m_iTail = m_iTail % m_iQueueCapacity; //ʹ�ö�β��������ֵ�󣬻ص���ʼλ��(��ֹ�±�Խ��)
		m_iQueueLen++;//���ȼ���
		return true;
	}
}

state MyQueue::DeQueue()
{
	if (QueueEmpty())
	{
		cout << "�ӿ�" << endl;
	}
	else
	{
		state outstate;
		m_iTail--;
		outstate = m_pQueue[m_iTail];
		m_iTail = m_iTail % m_iQueueCapacity;
		m_iQueueLen--;
		return outstate;
	}
}

//��������
void MyQueue::QueueTraverse()
{
	cout << endl;
	cout << "���򲻸������ˣ���Ҫ�Ľ�����ˣ�" << endl;
	//��ӡ����
	for (int i = m_iHead; i < m_iQueueLen + m_iHead; i++)
	{//i % m_iQueueLen (��ֹ�±�Խ��)
		
		cout << "(" << m_pQueue[i % m_iQueueCapacity].m_iA << ","
			<< m_pQueue[i % m_iQueueCapacity].m_iB << ","
			<< m_pQueue[i % m_iQueueCapacity].m_iC << ","
			<< m_pQueue[i % m_iQueueCapacity].m_iD << ")" << endl;
	}
}

//����Ƿ񱣴��
bool MyQueue::checksaved(state nowstate)
{
	bool flag = false;
	for (int i = m_iHead; i < m_iQueueLen + m_iHead; i++)
	{//i % m_iQueueLen (��ֹ�±�Խ��)
		//cout << "������й��̼���:(" << m_pQueue[i % m_iQueueCapacity].m_iA << ","
		//	<< m_pQueue[i % m_iQueueCapacity].m_iB << ","
		//	<< m_pQueue[i % m_iQueueCapacity].m_iC << ","
		//	<< m_pQueue[i % m_iQueueCapacity].m_iD << ") " << endl;
		if (m_pQueue[i % m_iQueueCapacity].m_iA == nowstate.getA() &&
			m_pQueue[i % m_iQueueCapacity].m_iB == nowstate.getB() && 
			m_pQueue[i % m_iQueueCapacity].m_iC == nowstate.getC() && 
			m_pQueue[i % m_iQueueCapacity].m_iD == nowstate.getD())
		{
			flag = true;
		}
	}
	return flag;
}

bool MyQueue::checkshit(state nowstate)
{
	bool flag = false;
	for (int i = m_iHead; i < m_iQueueLen + m_iHead; i++)
	{//i % m_iQueueLen (��ֹ�±�Խ��)
		if (m_pQueue[i % m_iQueueCapacity].m_iA == nowstate.getA() &&
			m_pQueue[i % m_iQueueCapacity].m_iB == nowstate.getB() &&
			m_pQueue[i % m_iQueueCapacity].m_iC == nowstate.getC() &&
			m_pQueue[i % m_iQueueCapacity].m_iD == nowstate.getD())
		{
			flag = true;
		}
	}
	return flag;
}

state MyQueue::getTailQueue()
{
	if (QueueEmpty())
	{
		cout << "�ӿ�" << endl;
	}
	else
	{
		state hopestate;
		m_iTail--;
		hopestate = m_pQueue[m_iTail];
		m_iTail++;
		return hopestate;
	}
}