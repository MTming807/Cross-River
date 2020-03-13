#include<iostream>
#include"event.h"
using namespace std;

event::event()
{
	m_iCount = 0;
}

event::~event()
{
}

state *event::go(state crtb)
{
	//���жϺ�����λ�м���0�������ؽ�������飩�м���Ԫ��
	if (crtb.getB() == 0)
	{
		m_iCount = m_iCount + 1;
	}
	if (crtb.getC() == 0)
	{
		m_iCount = m_iCount + 1;
	}
	if (crtb.getD() == 0)
	{
		m_iCount = m_iCount + 1;
	}

	switch (m_iCount)
	{
	case(1):
		if (crtb.getB() == 0)
		{
			gop[0].setB(1);
			gop[0].setC(crtb.getC());
			gop[0].setD(crtb.getD());//gop0=11xx
		}
		if (crtb.getC() == 0)
		{
			gop[0].setB(crtb.getB());
			gop[0].setC(1);
			gop[0].setD(crtb.getD());//gop0=1x1x
		}
		if (crtb.getD() == 0)
		{
			gop[0].setB(crtb.getB());
			gop[0].setC(crtb.getC());
			gop[0].setD(1);//gop0=1xx1
		}
		break;
	case(2):
		if (crtb.getB() == 1)//crtv = 0010  1110/1011  0001  1101/1011
		{
			gop[0].setB(crtb.getB());
			gop[0].setC(1);
			gop[0].setD(crtb.getD());//gop0=111x
			gop[1].setB(crtb.getB());
			gop[1].setC(crtb.getC());
			gop[1].setD(1);//gop1=11x1
		}
		if (crtb.getC() == 1)
		{
			gop[0].setB(1);
			gop[0].setC(crtb.getC());
			gop[0].setD(crtb.getD());//gop0=111x
			gop[1].setB(crtb.getB());
			gop[1].setC(crtb.getC());
			gop[1].setD(1);//gop1=1x11
		}
		if (crtb.getD() == 1)
		{
			gop[0].setB(1);
			gop[0].setC(crtb.getC());
			gop[0].setD(crtb.getD());//gop0=11x1
			gop[1].setB(crtb.getB());
			gop[1].setC(1);
			gop[1].setD(crtb.getD());//gop1=1x11
		}
		break;
	case(3):
		gop[0].setB(1);
		gop[0].setC(crtb.getC());
		gop[0].setD(crtb.getD());//gop0=11xx
		gop[1].setB(crtb.getB());
		gop[1].setC(1);
		gop[1].setD(crtb.getD());//gop1=1x1x
		gop[2].setB(crtb.getB());
		gop[2].setC(crtb.getC());
		gop[2].setD(1);//gop2=1xx1
		break;
	default:
		cout << "���Բ�̫�ԣ�����Ҫɾ��" << endl;
		break;
	}
	for (int i = 0; i < m_iCount; i++)//ũ��go
	{
		gop[i].setA(1);//ȫ��װ��ũ��A����һ��״̬1
	}
	cout << "ũ��Ҫ���� ����λ0�ĸ�����" << m_iCount << endl;
	return gop;
}

state *event::back(state crtg)
{
	//���жϺ�����λ�м���1�������ؽ�������飩�м���Ԫ��
	if (crtg.getB() == 1)
	{
		m_iCount = m_iCount + 1;
	}
	if (crtg.getC() == 1)
	{
		m_iCount = m_iCount + 1;
	}
	if (crtg.getD() == 1)
	{
		m_iCount = m_iCount + 1;
	}

	switch (m_iCount)
	{
	case(1):
		if (crtg.getB() == 1)
		{
			backp[0].setB(0);
			backp[0].setC(crtg.getC());
			backp[0].setD(crtg.getD());//backp0=00xx

			backp[1].setB(crtg.getB());
			backp[1].setC(crtg.getC());
			backp[1].setD(crtg.getD());//���ֻ�
		}
		if (crtg.getC() == 1)
		{
			backp[0].setB(crtg.getB());
			backp[0].setC(0);
			backp[0].setD(crtg.getD());//backp0=1x1x

			backp[1].setB(crtg.getB());
			backp[1].setC(crtg.getC());
			backp[1].setD(crtg.getD());//���ֻ�
		}
		if (crtg.getD() == 1)
		{
			backp[0].setB(crtg.getB());
			backp[0].setC(crtg.getC());
			backp[0].setD(0);//backp0=0xx0

			backp[1].setB(crtg.getB());
			backp[1].setC(crtg.getC());
			backp[1].setD(crtg.getD());//���ֻ�
		}
		break;
	case(2):
		backp[2].setB(crtg.getB());
		backp[2].setC(crtg.getC());
		backp[2].setD(crtg.getD());//���ֻ�
		if (crtg.getB() == 0)
		{
			backp[0].setB(crtg.getB());
			backp[0].setC(0);
			backp[0].setD(crtg.getD());//backp0=000x
			backp[1].setB(crtg.getB());
			backp[1].setC(crtg.getC());
			backp[1].setD(0);//backp1=00x0
		}
		if (crtg.getC() == 0)
		{
			backp[0].setB(0);
			backp[0].setC(crtg.getC());
			backp[0].setD(crtg.getD());//backp0=000x
			backp[1].setB(crtg.getB());
			backp[1].setC(crtg.getC());
			backp[1].setD(0);//backp1=0x00
		}
		if (crtg.getD() == 0)
		{
			backp[0].setB(0);
			backp[0].setC(crtg.getC());
			backp[0].setD(crtg.getD());//backp0=00x0
			backp[1].setB(crtg.getB());
			backp[1].setC(0);
			backp[1].setD(crtg.getD());//backp1=0x00
		}
		break;
	case(3):
		backp[0].setB(0);
		backp[0].setC(crtg.getC());
		backp[0].setD(crtg.getD());//backp0=00xx
		backp[1].setB(crtg.getB());
		backp[1].setC(0);
		backp[1].setD(crtg.getD());//backp1=0x0x
		backp[2].setB(crtg.getB());
		backp[2].setC(crtg.getC());
		backp[2].setD(0);//backp2=0xx0

		backp[3].setB(crtg.getB());
		backp[3].setC(crtg.getC());
		backp[3].setD(crtg.getD());//���ֻ�
		break;
	default:
		cout << "���Բ�̫�ԣ�����Ҫɾ��" << endl;
		break;
	}
	int a = m_iCount + 1;
	for (int i = 0; i < a; i++)//ũ��go
	{
		backp[i].setA(0);//ȫ��װ��ũ��A����һ��״̬0
	}
	cout << "ũ��Ҫ����������λ1�ĸ�����" << m_iCount << endl;
	return backp;
}

int event::getcount(state crtstate)
{
	if (crtstate.getA() == 1)//��ʾũ��׼��back
	{
		int b = m_iCount + 1;
		return b;
	}
	else
	{
		return m_iCount;
	}
}

state *event::action(state crtstate)
{
	state *statearr;
	if (crtstate.getA() == 1)//��ʾũ��׼��back
	{
		statearr = back(crtstate);
	}
	else
	{
		statearr = go(crtstate);
	}
	return statearr;
}

