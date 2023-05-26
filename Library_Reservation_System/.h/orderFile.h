#pragma once
#pragma once
#include<fstream>
#include<iostream>
#include<map>
#include"globalFile.h"
using namespace std;


class OrderFile
{
public:
	//构造函数
	OrderFile();


	//更新预约记录
	void updateOrder();

	//记录预约条数
	int m_Size;

	//记录所有预约信息的容器 key记录预约条数  value记录具体键值对信息
	map<int, map<string, string>>m_orderData;

};
