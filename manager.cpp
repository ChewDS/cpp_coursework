#include "manager.h"
//Ĭ�Ϲ���
Manager::Manager()
{

}
//�вι���
Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ������ ��ȡ�������ļ�����ʦ��ѧ����Ϣ
	this->initVector();

	//��ʼ��ͼ�����Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	Library lib;

	while (ifs >> lib.m_LibId && ifs >> lib.m_MaxNum)
	{
		vLib.push_back(lib);
	}
	ifs.close();

	cout << "ͼ��ݵ�����Ϊ��" << vLib.size() << endl;
}
//ѡ��˵�
void Manager::openMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴ͼ���          |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
//����˺�
void Manager::addPerson()
{

	cout << "��������ӵ��˺�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;

	string fileName;//�������ļ���
	string tip;//��ʾid��
	string errorTip;//�ظ�������ʾ
	ofstream ofs;//�ļ��Ĳ�������

	int select = 0;
	cin >> select;//�����û���ѡ��

	if (select == 1)
	{
		//��ӵ���ѧ��
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ������������룡";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ�����ظ������������룡";
	}

	//����׷�ӵķ�ʽд�ļ�
	ofs.open(fileName, ios::out | ios::app);

	int id;
	string name;
	string pwd;

	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool rep = checkRepeat(id, select);
		if (rep)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}


	cout << "������������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	//���ļ����������
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ���" << endl;

	system("pause");
	system("cls");
	ofs.close();
	this->initVector();
}
void printStudent(Student s)
{
	Student* s1 = &s;
	cout << "ѧ�ţ�" << s1->m_Id << " ������" << s1->m_Name << " ���룺" << s1->m_Pwd << endl;
}
void printTeacher(Teacher  t)
{
	Teacher* t1 = &t;
	cout << "ְ���ţ�" << t1->m_EmpId << " ������" << t1->m_Name << " ���룺" << t1->m_Pwd << endl;
}
//�鿴�˺�
void Manager::showPerson()
{
	int select = 0;

	while (true)
	{
		cout << "��ѡ��鿴���ݣ�" << endl;
		cout << "1.�鿴����ѧ��" << endl;
		cout << "2.�鿴������ʦ" << endl;
		cout << "0.���ع���Ա�˵�" << endl;
		cin >> select;

		if (select == 1)
		{
			//�鿴ѧ��
			cout << "����������������������������������������������������������������" << endl;
			cout << "���е�ѧ����Ϣ���£�" << endl;
			for_each(vStu.begin(), vStu.end(), printStudent);
			cout << "����������������������������������������������������������������" << endl;
			cout << endl;
		}
		else if (select == 2)
		{
			//�鿴��ʦ
			cout << "����������������������������������������������������������������" << endl;
			cout << "���е���ʦ��Ϣ���£�" << endl;
			for_each(vTea.begin(), vTea.end(), printTeacher);
			cout << "����������������������������������������������������������������" << endl;
			cout << endl;
		}
		else
		{
			//������һ��
			break;
		}
	}

	system("pause");
	system("cls");
}
//�鿴ͼ�����Ϣ
void Manager::showLibrary()
{
	cout << "����������������������������������������������������������������" << endl;
	cout << "ͼ�����Ϣ���£�" << endl;

	for (vector<Library>::iterator it = vLib.begin(); it != vLib.end(); it++)
	{
		cout << "ͼ��ݱ�ţ�" << it->m_LibId << " ͼ���������" << it->m_MaxNum << endl;
	}
	cout << "����������������������������������������������������������������" << endl;
	system("pause");
	system("cls");
}
//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ��� " << endl;
	system("pause");
	system("cls");
}
//��ʼ������
void Manager::initVector()
{
	//ȷ����������յ�״̬
	vStu.clear();
	vTea.clear();

	//��ȡ��Ϣ ѧ������ʦ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ��������" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ������" << vTea.size() << endl;
	ifs.close();

}
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		//�����ʦ
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}