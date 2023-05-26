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

//进入学生子菜单页面
void studentMenu(Identity*& student)
{
	while (true)
	{
		//调用管理员子菜单
		student->openMenu();

		//将父类指针转化为子类指针，可以调用子类里其他特有的接口
		Student* stu = (Student*)student;

		int select = 0;
		//接受用户选择
		cin >> select;

		if (select == 1)//申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)//查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3)//查看所有预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			stu->cancelOrder();
		}
		else//注销登录
		{
			delete student;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入教师子菜单页面
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//调用教师子菜单
		teacher->openMenu();

		//将父类指针转化为子类指针，可以调用子类里其他特有的接口
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		//接受用户选择
		cin >> select;

		if (select == 1)
		{
			cout << "显示所有预约：" << endl;
			tea->showOrder();
		}
		else if (select == 2)
		{
			cout << "审核预约：" << endl;
			tea->validOrder();
		}
		else
		{
			delete teacher;//销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}



//进入管理员子菜单页面
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->openMenu();

		//将父类指针转化为子类指针，可以调用子类里其他特有的接口
		Manager* man = (Manager*)manager;

		int select = 0;
		//接受用户选择
		cin >> select;

		if (select == 1)//添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)//查看图书馆
		{
			cout << "查看图书馆" << endl;
			man->showLibrary();
		}
		//清空预约
		else if (select == 4)
		{
			man->cleanFile();
		}
		else
		{
			delete manager;//销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录功能 参数1 操作文件的名称 参数2 操作身份类型
void LoginIn(string fileName, int type)
{
	//父类指针 用于指向子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();//关闭文件
		return;
	}

	//准备接受用户信息
	int id = 0;
	string name;
	string pwd;

	//用户身份为学生
	if (type == 1)
	{
		//学生身份验证
		//从文件中获取的id
		int fid;
		//从文件中获取的姓名
		string fName;
		//从文件中获取的密码
		string fpwd;
		while (ifs >> fid && ifs >> fName && ifs >> fpwd)
		{
			while (true)
			{
				cout << "请输入你的学号：" << endl;
				cin >> id;
				cout << "请输入用户名：" << endl;
				cin >> name;
				cout << "请输入密码：" << endl;
				cin >> pwd;
				while (true)
				{
					//设置随机数种子
					srand(int(time(NULL)));
					int a = rand() % (10000 - 1000) + 1000;
					cout << a << endl;
					cout << "请输入屏幕上出现的验证码" << endl;
					int b = 0;
					cin >> b;
					//与用户输入信息做对比
					//验证码有误
					if (a != b)
					{
						cout << "您输入的验证码有误,请重新输入" << endl;
					}
					else if (a == b)
					{
						break;
					}
				}
				if (fid == id && fName == name && fpwd == pwd)
				{
					cout << "学生验证登录成功！" << endl;
					system("pause");
					system("cls");
					person = new Student(id, name, pwd);
					//进入学生页面子菜单
					studentMenu(person);
					return;
				}
				//验证码无误，验证学号
				else if (fid != id)
				{
					cout << "您的学号输入有误,请重新输入" << endl;
					system("pause");
					system("cls");
				}
				//学号无误，再进行用户名和密码验证
				else if (fid == id)
				{
					if (fName != name || fpwd != pwd)
					{
						cout << "您的用户名或密码输入有误,请重新输入" << endl;
							system("pause");
							system("cls");
					}
				}
			}
		}
		if (!(ifs >> fid && ifs >> fName && ifs >> fpwd))
		{
			cout << "暂无学生用户" << endl;
		}
	}
	else if (type == 2)
	{
		//从文件中获取的id
		int fid;
		//从文件中获取的姓名
		string fName;
		//从文件中获取的密码
		string fpwd;
		while (ifs >> fid && ifs >> fName && ifs >> fpwd)
		{
			while (true)
			{
				cout << "请输入你的职工编号：" << endl;
				cin >> id;
				cout << "请输入用户名：" << endl;
				cin >> name;
				cout << "请输入密码：" << endl;
				cin >> pwd;
				while (true)
				{
					//设置随机数种子
					srand(int(time(NULL)));
					int a = rand() % (10000 - 1000) + 1000;
					cout << a << endl;
					cout << "请输入屏幕上出现的验证码" << endl;
					int b = 0;
					cin >> b;
					//与用户输入信息做对比
					//验证码有误
					if (a != b)
					{
						cout << "您输入的验证码有误,请重新输入" << endl;
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
					cout << "老师验证登录成功！" << endl;
					system("pause");
					system("cls");
					person = new Teacher(id, name, pwd);
					//进入老师页面子菜单
					teacherMenu(person);
					return;
				}
				//验证码无误，验证职工编号
				else if (fid != id)
				{
					cout << "您的职工编号输入有误,请重新输入" << endl;
					system("pause");
					system("cls");
				}
				//职工编号无误，再进行用户名和密码验证
				else if (fid == id)
				{
					if (fName != name || fpwd != pwd)
					{
						cout << "您的用户名或密码输入有误,请重新输入" << endl;
						system("pause");
						system("cls");
					}
				}
			}
		}
		if (!(ifs >> fid && ifs >> fName && ifs >> fpwd))
		{
			cout << "暂无老师用户" << endl;
		}
	}
	else if (type == 3)
	{
		//管理员身份验证
		//从文件中获取的姓名
		string fName;
		//从文件中获取的密码
		string fpwd;

		while (ifs >> fName && ifs >> fpwd)
		{
			while (true)
			{
				cout << "请输入用户名：" << endl;
				cin >> name;
				cout << "请输入密码：" << endl;
				cin >> pwd;
				while (true)
				{
					//设置随机数种子
					srand(int(time(NULL)));
					int a = rand() % (10000 - 1000) + 1000;
					cout << a << endl;
					cout << "请输入屏幕上出现的验证码" << endl;
					int b = 0;
					cin >> b;
					//与用户输入信息做对比
					//验证码有误
					if (a != b)
					{
						cout << "您输入的验证码有误,请重新输入" << endl;
						system("pause");
						system("cls");
					}
					else if (a == b)
					{
						break;
					}
				}
				//与用户输入信息做对比
				if (fName == name && fpwd == pwd)
				{
					cout << "管理员验证登录成功！" << endl;
					system("pause");
					system("cls");
					//创建管理员对象
					person = new Manager(name, pwd);
					//进入管理员页面子菜单
					managerMenu(person);
					return;
				}
				//验证码无误，进行用户名和密码验证
				if (fName != name || fpwd != pwd)
				{
					cout << "您的用户名或密码输入有误,请重新输入" << endl;
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
		cout << "=================  欢迎来到Chew的图书馆预约系统  ================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select;//接受用户选择

		switch (select)//根据用户选择实现不同的接口
		{
		case 1://学生
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://老师
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://退出
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");

	return 0;
}