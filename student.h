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
	//Ĭ�Ϲ���
	Student();
	//�вι���
	Student(long id, string name, string pwd);
	//�˵�����
	virtual void openMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴����ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();
	//ȡ��ԤԼ
	void cancelOrder();
	//ѧ��ѧ��
	int m_Id;
	//ͼ�����Ϣ
	vector<Library>vLib;
};
