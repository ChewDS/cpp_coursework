#pragma once
#include <iostream>
#include "Identity.h"
#include<vector>
#include <string>
#include "Library.h"
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"
using namespace std;
class Student :public Identity
{
public:
	//默认构造
	Student();
	//有参构造
	Student(long id, string name, string pwd);
	//菜单界面
	virtual void openMenu();
	//申请预约
	void applyOrder();
	//查看自身预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();
	//取消预约
	void cancelOrder();
	//学生学号
	int m_Id;
	//图书馆信息
	vector<Library>vLib;
};
