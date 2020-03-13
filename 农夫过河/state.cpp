#include <iostream>
#include "state.h"
using namespace std;

state::state()
{
}

state::~state()
{
}

int state::getA()
{
	return m_iA;
}

int state::getB()
{
	return m_iB;
}

int state::getC()
{
	return m_iC;
}

int state::getD()
{
	return m_iD;
}

void state::setA(int a)
{
	m_iA = a;
}

void state::setB(int b)
{
	m_iB = b;
}

void state::setC(int c)
{
	m_iC = c;
}

void state::setD(int d)
{
	m_iD = d;
}

bool state::checkfinal()
{
	if (m_iA == 1 && m_iB == 1 && m_iC == 1 && m_iD  == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool state::checksafe()//判断，除0000和1111的八种安全状态返回true
{
	if ((m_iA == 0 && m_iB == 0 && m_iC == 0 && m_iD == 1) ||	//0001
		(m_iA == 0 && m_iB == 0 && m_iC == 1 && m_iD == 0) ||	//0010
		(m_iA == 0 && m_iB == 1 && m_iC == 0 && m_iD == 1) ||	//0101
		(m_iA == 0 && m_iB == 1 && m_iC == 0 && m_iD == 0) ||	//0100
		(m_iA == 1 && m_iB == 0 && m_iC == 1 && m_iD == 1) ||	//1011
		(m_iA == 1 && m_iB == 0 && m_iC == 1 && m_iD == 0) ||	//1010
		(m_iA == 1 && m_iB == 1 && m_iC == 0 && m_iD == 1) ||	//1101
		(m_iA == 1 && m_iB == 1 && m_iC == 1 && m_iD == 0))		//1110
	{
		return true;
	}
	else
	{
		return false;
	}
}

void state::printinfo()
{
	cout << "(" << m_iA << "," << m_iB << "," << m_iC << "," << m_iD << ")" << endl;
}

