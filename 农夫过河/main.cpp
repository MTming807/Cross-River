#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>
#include"event.h"
#include"queue.h"
using namespace std;

void *pro(state initstate, MyQueue *sp, MyQueue *shit)
{
	cout << endl;
	event event;
	state *nextp;
	state hope;

	nextp = event.action(initstate);
	for (int i = 0; i < event.getcount(initstate); i++)
	{
		if ((nextp[i].getA() > -1) && (nextp[i].getB()>-1) && (nextp[i].getC()>-1) && (nextp[i].getD() > -1))
		{
			if ((nextp[i].getA() < 2) && (nextp[i].getB()<2) && (nextp[i].getC()<2) && (nextp[i].getD() <2))
			{
				cout << "�ж���һ������״̬:" << nextp[i].getA() << nextp[i].getB() << nextp[i].getC() << nextp[i].getD() << endl;
				if (nextp[i].checkfinal())//1111
				{
					cout << "�Ѵﵽ����״̬��������" << endl;
					sp->QueueTraverse();
					system("pause");
					return 0;
				}
				else
				{
					cout << "δ������״̬" << endl;
					if (!shit->checkshit(nextp[i]))
					{
						cout << "���ڱ��߳���״̬������" << endl;
						if (nextp[i].checksafe())//��ȫ��
						{
							cout << "�ǰ�ȫ״̬" << endl;
							if (!sp->checksaved(nextp[i]))//�������
							{
								initstate = nextp[i];
								sp->EnQueue(initstate);//����
								cout << "---�����߹���״̬�����У�����" << initstate.getA() << initstate.getB() << initstate.getC() << initstate.getD() << "!---" << endl;
								pro(initstate, sp, shit);
								initstate.printinfo();
							}
							else
							{
								cout << "ǰ���߹��ˣ�����" << endl;
							}
						}
						else
						{
							cout << "�ǰ�ȫ״̬������" << endl;
						}
					}
					else
					{
						cout << "�ڱ��߳���״̬�����У�����" << endl;
					}
				}
			}
		}
	}
	cout << "�޿��е���һ��״̬����ʼ���ݣ�" << endl;
	state last;
	cout << "�߳����״̬" << endl;
	last = sp->DeQueue();
	last.printinfo();
	shit->EnQueue(last);
	hope = sp->getTailQueue();
	//hope.printinfo();
	pro(hope, sp, shit);
}

int main(void)
{
	state initstate;//��ʼ״̬
	MyQueue *process = new MyQueue(10);//���д����
	MyQueue *shit = new MyQueue(10);//shit

	initstate.setA(0);
	initstate.setB(0);
	initstate.setC(0);
	initstate.setD(0);

	pro(initstate, process, shit);//��ʼ�ݹ�

	//result->QueueTraverse();

	delete process;
	process = NULL;

	////s100���ڲ��԰�ȫ״̬
	//state s100;
	//for (int a = 0; a < 2; a++)
	//{
	//	for (int b = 0; b < 2; b++)
	//	{
	//		for (int c = 0; c < 2; c++)
	//		{
	//			for (int d = 0; d < 2; d++)
	//			{
	//				s100.setA(a);
	//				s100.setB(b);
	//				s100.setC(c);
	//				s100.setD(d);
	//				if (s100.checksafe())
	//				{
	//					cout << "��ȫ״̬��";
	//					s100.printinfo();
	//				}
	//			}
	//		}
	//	}
	//}

	system("pause");
	return 0;
}