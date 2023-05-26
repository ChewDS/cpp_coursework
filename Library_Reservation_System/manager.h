#pragma once
#include <iostream>
#include "identity.h"
#include <fstream>
#include "globalFile.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include <algorithm>
#include "library.h"
using namespace std;
//管理员类
class Manager :public Identity
{
public:
	//默认构造
	Manager();
	//有参构造
	Manager(string name, string pwd);
	//选择菜单
	virtual void openMenu();
	//添加账号
	void addPerson();
	//查看账号
	void showPerson();
	//查看图书馆信息
	void showLibrary();
	//清空预约记录
	void cleanFile();
	//初始化容器
	void initVector();
	//检测重复 参数1 学号/职工号 参数2 学生/老师类型
	bool checkRepeat(int id, int type);
	//学生容器
	vector<Student>vStu;
	//老师容器
	vector<Teacher>vTea;
	//图书馆容器
	vector<Library>vLib;
};

