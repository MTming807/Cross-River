#pragma once
#include "state.h"

class MyQueue
{
public:
	MyQueue(int queueCapacity);   //创建队列
	virtual ~MyQueue();    //销毁队列

	void ClearQueue();   //清空队列
	bool QueueEmpty() const;   //判空队列
	int QueueLength() const;   //队列长度
	bool QueueFull() const;    //队列是否满

	bool EnQueue(state element);  //新元素入队
	state DeQueue();   //首元素出队
	void QueueTraverse();    //遍历队列

	bool checksaved(state nowstate);//检查状态保存过没？思路：利用队列保存路径，同时遍历该队列是否存在相同状态
	bool checkshit(state nowstate);

	state getTailQueue();

private:
	state *m_pQueue;     //队列数组指针
	int m_iQueueLen;     //队列元素个数
	int m_iQueueCapacity;   //队列数组容量

	int m_iHead;  //队头
	int m_iTail;   //队尾
};