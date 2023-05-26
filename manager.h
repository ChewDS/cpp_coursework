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
//����Ա��
class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();
	//�вι���
	Manager(string name, string pwd);
	//ѡ��˵�
	virtual void openMenu();
	//����˺�
	void addPerson();
	//�鿴�˺�
	void showPerson();
	//�鿴ͼ�����Ϣ
	void showLibrary();
	//���ԤԼ��¼
	void cleanFile();
	//��ʼ������
	void initVector();
	//����ظ� ����1 ѧ��/ְ���� ����2 ѧ��/��ʦ����
	bool checkRepeat(int id, int type);
	//ѧ������
	vector<Student>vStu;
	//��ʦ����
	vector<Teacher>vTea;
	//ͼ�������
	vector<Library>vLib;
};

