#include <iostream>
#include "queue.h"
using namespace std;

MyQueue::MyQueue(int queueCapacity)
{
	m_iQueueCapacity = queueCapacity;

	//队列初始化
	ClearQueue();//等于初始化队头、队尾、队列元素个数
				 //m_iHead = 0;//队头初始化
				 //m_iTail = 0;//队尾初始化
				 //m_iQueueLen = 0;//队列元素个数初始化

	m_pQueue = new state[m_iQueueCapacity];//为队列分配m_iQueueCapacity个空间
}

//析构函数
MyQueue::~MyQueue()
{
	delete[]m_pQueue;
	m_pQueue = NULL;
}

//清空队列
void  MyQueue::ClearQueue()
{
	m_iHead = 0;//队头初始化
	m_iTail = 0;//队尾初始化
	m_iQueueLen = 0;//队列元素个数初始化
}

//判断是否是空队列
bool MyQueue::QueueEmpty() const
{
	if (m_iQueueLen == 0)//判断队列长度是否为0，不可使用队头队尾指针为0
	{
		return true;
	}
	else
	{
		return false;
	}
}

//队列长度
int MyQueue::QueueLength() const
{
	return m_iQueueLen;//直接返回队长
}

//判断是否是满队列
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

//新元素入队
bool MyQueue::EnQueue(state element)
{
	if (QueueFull())
	{
		cout << "队满" << endl;
		return false;
	}
	else
	{
		m_pQueue[m_iTail] = element;
		m_iTail++;//队尾移动
		m_iTail = m_iTail % m_iQueueCapacity; //使得队尾超过容量值后，回到起始位置(防止下标越界)
		m_iQueueLen++;//长度计数
		return true;
	}
}

state MyQueue::DeQueue()
{
	if (QueueEmpty())
	{
		cout << "队空" << endl;
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

//遍历队列
void MyQueue::QueueTraverse()
{
	cout << endl;
	cout << "功夫不负有心人，你要的结果来了：" << endl;
	//打印队列
	for (int i = m_iHead; i < m_iQueueLen + m_iHead; i++)
	{//i % m_iQueueLen (防止下标越界)
		
		cout << "(" << m_pQueue[i % m_iQueueCapacity].m_iA << ","
			<< m_pQueue[i % m_iQueueCapacity].m_iB << ","
			<< m_pQueue[i % m_iQueueCapacity].m_iC << ","
			<< m_pQueue[i % m_iQueueCapacity].m_iD << ")" << endl;
	}
}

//检查是否保存过
bool MyQueue::checksaved(state nowstate)
{
	bool flag = false;
	for (int i = m_iHead; i < m_iQueueLen + m_iHead; i++)
	{//i % m_iQueueLen (防止下标越界)
		//cout << "检查已有过程集合:(" << m_pQueue[i % m_iQueueCapacity].m_iA << ","
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
	{//i % m_iQueueLen (防止下标越界)
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
		cout << "队空" << endl;
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