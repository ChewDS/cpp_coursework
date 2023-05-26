#pragma once
#include <iostream>
#include "identity.h"
#include"orderFile.h"
#include <vector>
using namespace std;

//教师类设计
class Teacher :public Identity
{
public:
	//默认构造
	Teacher();
	//有参构造
	Teacher(int empid, string name, string pwd);

	//菜单界面
	virtual void openMenu();

	//查看所有预约
	void showOrder();

	//审核预约
	void validOrder();

	//职工编号
	int m_EmpId;
};
