#pragma once
#include "state.h"
//�¼��� 
//��ȡ��ǰstate����now_state������go()��back()�ı�
//δ��������һ�����飬������п���״̬
class event
{
public:
	event();
	~event();

	state *go(state crtb);//���ӣ������ϸ���ͷ״̬�����ص�ǰ״̬
	state *back(state crtg);//��ͷ�������ϸ�����״̬�����ص�ǰ״̬

	state *action(state crtstate);//������main�б�����
	int getcount(state crtstate);

private:
	state gop[2];
	state backp[3];
	int m_iCount;//��ź�����λΪ0/1�ĸ���
};