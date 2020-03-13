#pragma once
#include "state.h"
//事件类 
//获取当前state放入now_state，根据go()和back()改变
//未来将返回一个数组，存放所有可能状态
class event
{
public:
	event();
	~event();

	state *go(state crtb);//过河，传入上个回头状态，返回当前状态
	state *back(state crtg);//回头，传入上个过河状态，返回当前状态

	state *action(state crtstate);//真正在main中被调用
	int getcount(state crtstate);

private:
	state gop[2];
	state backp[3];
	int m_iCount;//存放后面三位为0/1的个数
};