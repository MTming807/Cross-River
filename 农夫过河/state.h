#pragma once
//状态类
//定义状态，检查传入的状态是否符合要求
class state
{
public:
    state();
    ~state();
	
	int getA();
	int getB();
	int getC();
	int getD();
	void setA(int a);
	void setB(int b);
	void setC(int c);
	void setD(int d);

	bool checkfinal();//检查状态结束?
	bool checksafe();//检查状态安全？

	void printinfo();

public:
    int m_iA;
    int m_iB;
	int m_iC;
	int m_iD;
};


