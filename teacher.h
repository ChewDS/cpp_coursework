#pragma once
#include <iostream>
#include "identity.h"
#include"orderFile.h"
#include <vector>
using namespace std;

//��ʦ�����
class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();
	//�вι���
	Teacher(int empid, string name, string pwd);

	//�˵�����
	virtual void openMenu();

	//�鿴����ԤԼ
	void showOrder();

	//���ԤԼ
	void validOrder();

	//ְ�����
	int m_EmpId;
};
