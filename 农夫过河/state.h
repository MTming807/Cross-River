#pragma once
//״̬��
//����״̬����鴫���״̬�Ƿ����Ҫ��
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

	bool checkfinal();//���״̬����?
	bool checksafe();//���״̬��ȫ��

	void printinfo();

public:
    int m_iA;
    int m_iB;
	int m_iC;
	int m_iD;
};


