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
				cout << "判断下一个可能状态:" << nextp[i].getA() << nextp[i].getB() << nextp[i].getC() << nextp[i].getD() << endl;
				if (nextp[i].checkfinal())//1111
				{
					cout << "已达到最终状态，结束！" << endl;
					sp->QueueTraverse();
					system("pause");
					return 0;
				}
				else
				{
					cout << "未到最终状态" << endl;
					if (!shit->checkshit(nextp[i]))
					{
						cout << "不在被踢出的状态集合中" << endl;
						if (nextp[i].checksafe())//安全？
						{
							cout << "是安全状态" << endl;
							if (!sp->checksaved(nextp[i]))//保存过？
							{
								initstate = nextp[i];
								sp->EnQueue(initstate);//保存
								cout << "---不在走过的状态集合中，保存" << initstate.getA() << initstate.getB() << initstate.getC() << initstate.getD() << "!---" << endl;
								pro(initstate, sp, shit);
								initstate.printinfo();
							}
							else
							{
								cout << "前面走过了，舍弃" << endl;
							}
						}
						else
						{
							cout << "非安全状态，舍弃" << endl;
						}
					}
					else
					{
						cout << "在被踢出的状态集合中，舍弃" << endl;
					}
				}
			}
		}
	}
	cout << "无可行的下一个状态，开始回溯！" << endl;
	state last;
	cout << "踢出最后状态" << endl;
	last = sp->DeQueue();
	last.printinfo();
	shit->EnQueue(last);
	hope = sp->getTailQueue();
	//hope.printinfo();
	pro(hope, sp, shit);
}

int main(void)
{
	state initstate;//初始状态
	MyQueue *process = new MyQueue(10);//队列村过程
	MyQueue *shit = new MyQueue(10);//shit

	initstate.setA(0);
	initstate.setB(0);
	initstate.setC(0);
	initstate.setD(0);

	pro(initstate, process, shit);//开始递归

	//result->QueueTraverse();

	delete process;
	process = NULL;

	////s100用于测试安全状态
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
	//					cout << "安全状态：";
	//					s100.printinfo();
	//				}
	//			}
	//		}
	//	}
	//}

	system("pause");
	return 0;
}