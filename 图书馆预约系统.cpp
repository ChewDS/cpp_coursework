#include<iostream>
#include"identity.h"
#include<fstream>
#include <string>
#include"globalFile.h"
#include "student.h"
#include"teacher.h"
#include"manager.h"
#include<ctime>
#include<cstdlib>
using namespace std;

//����ѧ���Ӳ˵�ҳ��
void studentMenu(Identity*& student)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		student->openMenu();

		//������ָ��ת��Ϊ����ָ�룬���Ե����������������еĽӿ�
		Student* stu = (Student*)student;

		int select = 0;
		//�����û�ѡ��
		cin >> select;

		if (select == 1)//����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2)//�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3)//�鿴����ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4)//ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else//ע����¼
		{
			delete student;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�����ʦ�Ӳ˵�ҳ��
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//���ý�ʦ�Ӳ˵�
		teacher->openMenu();

		//������ָ��ת��Ϊ����ָ�룬���Ե����������������еĽӿ�
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		//�����û�ѡ��
		cin >> select;

		if (select == 1)
		{
			cout << "��ʾ����ԤԼ��" << endl;
			tea->showOrder();
		}
		else if (select == 2)
		{
			cout << "���ԤԼ��" << endl;
			tea->validOrder();
		}
		else
		{
			delete teacher;//���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}



//�������Ա�Ӳ˵�ҳ��
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->openMenu();

		//������ָ��ת��Ϊ����ָ�룬���Ե����������������еĽӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		//�����û�ѡ��
		cin >> select;

		if (select == 1)//����˺�
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)//�鿴ͼ���
		{
			cout << "�鿴ͼ���" << endl;
			man->showLibrary();
		}
		//���ԤԼ
		else if (select == 4)
		{
			man->cleanFile();
		}
		else
		{
			delete manager;//���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��¼���� ����1 �����ļ������� ����2 �����������
void LoginIn(string fileName, int type)
{
	//����ָ�� ����ָ���������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();//�ر��ļ�
		return;
	}

	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;

	//�û����Ϊѧ��
	if (type == 1)
	{
		//ѧ�������֤
		//���ļ��л�ȡ��id
		int fid;
		//���ļ��л�ȡ������
		string fName;
		//���ļ��л�ȡ������
		string fpwd;
		while (ifs >> fid && ifs >> fName && ifs >> fpwd)
		{
			while (true)
			{
				cout << "���������ѧ�ţ�" << endl;
				cin >> id;
				cout << "�������û�����" << endl;
				cin >> name;
				cout << "���������룺" << endl;
				cin >> pwd;
				while (true)
				{
					//�������������
					srand(int(time(NULL)));
					int a = rand() % (10000 - 1000) + 1000;
					cout << a << endl;
					cout << "��������Ļ�ϳ��ֵ���֤��" << endl;
					int b = 0;
					cin >> b;
					//���û�������Ϣ���Ա�
					//��֤������
					if (a != b)
					{
						cout << "���������֤������,����������" << endl;
					}
					else if (a == b)
					{
						break;
					}
				}
				if (fid == id && fName == name && fpwd == pwd)
				{
					cout << "ѧ����֤��¼�ɹ���" << endl;
					system("pause");
					system("cls");
					person = new Student(id, name, pwd);
					//����ѧ��ҳ���Ӳ˵�
					studentMenu(person);
					return;
				}
				//��֤��������֤ѧ��
				else if (fid != id)
				{
					cout << "����ѧ����������,����������" << endl;
					system("pause");
					system("cls");
				}
				//ѧ�������ٽ����û�����������֤
				else if (fid == id)
				{
					if (fName != name || fpwd != pwd)
					{
						cout << "�����û�����������������,����������" << endl;
							system("pause");
							system("cls");
					}
				}
			}
		}
		if (!(ifs >> fid && ifs >> fName && ifs >> fpwd))
		{
			cout << "����ѧ���û�" << endl;
		}
	}
	else if (type == 2)
	{
		//���ļ��л�ȡ��id
		int fid;
		//���ļ��л�ȡ������
		string fName;
		//���ļ��л�ȡ������
		string fpwd;
		while (ifs >> fid && ifs >> fName && ifs >> fpwd)
		{
			while (true)
			{
				cout << "���������ְ����ţ�" << endl;
				cin >> id;
				cout << "�������û�����" << endl;
				cin >> name;
				cout << "���������룺" << endl;
				cin >> pwd;
				while (true)
				{
					//�������������
					srand(int(time(NULL)));
					int a = rand() % (10000 - 1000) + 1000;
					cout << a << endl;
					cout << "��������Ļ�ϳ��ֵ���֤��" << endl;
					int b = 0;
					cin >> b;
					//���û�������Ϣ���Ա�
					//��֤������
					if (a != b)
					{
						cout << "���������֤������,����������" << endl;
						system("pause");
						system("cls");
					}
					else if (a == b)
					{
						break;
					}
				}
				if (fid == id && fName == name && fpwd == pwd)
				{
					cout << "��ʦ��֤��¼�ɹ���" << endl;
					system("pause");
					system("cls");
					person = new Teacher(id, name, pwd);
					//������ʦҳ���Ӳ˵�
					teacherMenu(person);
					return;
				}
				//��֤��������ְ֤�����
				else if (fid != id)
				{
					cout << "����ְ�������������,����������" << endl;
					system("pause");
					system("cls");
				}
				//ְ����������ٽ����û�����������֤
				else if (fid == id)
				{
					if (fName != name || fpwd != pwd)
					{
						cout << "�����û�����������������,����������" << endl;
						system("pause");
						system("cls");
					}
				}
			}
		}
		if (!(ifs >> fid && ifs >> fName && ifs >> fpwd))
		{
			cout << "������ʦ�û�" << endl;
		}
	}
	else if (type == 3)
	{
		//����Ա�����֤
		//���ļ��л�ȡ������
		string fName;
		//���ļ��л�ȡ������
		string fpwd;

		while (ifs >> fName && ifs >> fpwd)
		{
			while (true)
			{
				cout << "�������û�����" << endl;
				cin >> name;
				cout << "���������룺" << endl;
				cin >> pwd;
				while (true)
				{
					//�������������
					srand(int(time(NULL)));
					int a = rand() % (10000 - 1000) + 1000;
					cout << a << endl;
					cout << "��������Ļ�ϳ��ֵ���֤��" << endl;
					int b = 0;
					cin >> b;
					//���û�������Ϣ���Ա�
					//��֤������
					if (a != b)
					{
						cout << "���������֤������,����������" << endl;
						system("pause");
						system("cls");
					}
					else if (a == b)
					{
						break;
					}
				}
				//���û�������Ϣ���Ա�
				if (fName == name && fpwd == pwd)
				{
					cout << "����Ա��֤��¼�ɹ���" << endl;
					system("pause");
					system("cls");
					//��������Ա����
					person = new Manager(name, pwd);
					//�������Աҳ���Ӳ˵�
					managerMenu(person);
					return;
				}
				//��֤�����󣬽����û�����������֤
				if (fName != name || fpwd != pwd)
				{
					cout << "�����û�����������������,����������" << endl;
					system("pause");
					system("cls");
				}
			}
		}
	}
	system("pause");
	system("cls");

	return;
}

int main() {
	int select = 0;
	while (true)
	{
		cout << "=================  ��ӭ����Chew��ͼ���ԤԼϵͳ  ================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

		cin >> select;//�����û�ѡ��

		switch (select)//�����û�ѡ��ʵ�ֲ�ͬ�Ľӿ�
		{
		case 1://ѧ��
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");

	return 0;
}