#include "manager.h"
//默认构造
Manager::Manager()
{

}
//有参构造
Manager::Manager(string name, string pwd)
{
	//初始化管理员信息
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器 获取到所有文件中老师、学生信息
	this->initVector();

	//初始化图书馆信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	Library lib;

	while (ifs >> lib.m_LibId && ifs >> lib.m_MaxNum)
	{
		vLib.push_back(lib);
	}
	ifs.close();

	cout << "图书馆的数量为：" << vLib.size() << endl;
}
//选择菜单
void Manager::openMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看图书馆          |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
//添加账号
void Manager::addPerson()
{

	cout << "请输入添加的账号类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;

	string fileName;//操作的文件名
	string tip;//提示id号
	string errorTip;//重复输入提示
	ofstream ofs;//文件的操作对象

	int select = 0;
	cin >> select;//接受用户的选项

	if (select == 1)
	{
		//添加的是学生
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入！";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工号重复，请重新输入！";
	}

	//利用追加的方式写文件
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


	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	//向文件中添加数据
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功！" << endl;

	system("pause");
	system("cls");
	ofs.close();
	this->initVector();
}
void printStudent(Student s)
{
	Student* s1 = &s;
	cout << "学号：" << s1->m_Id << " 姓名：" << s1->m_Name << " 密码：" << s1->m_Pwd << endl;
}
void printTeacher(Teacher  t)
{
	Teacher* t1 = &t;
	cout << "职工号：" << t1->m_EmpId << " 姓名：" << t1->m_Name << " 密码：" << t1->m_Pwd << endl;
}
//查看账号
void Manager::showPerson()
{
	int select = 0;

	while (true)
	{
		cout << "请选择查看内容：" << endl;
		cout << "1.查看所有学生" << endl;
		cout << "2.查看所有老师" << endl;
		cout << "0.返回管理员菜单" << endl;
		cin >> select;

		if (select == 1)
		{
			//查看学生
			cout << "————————————————————————————————" << endl;
			cout << "所有的学生信息如下：" << endl;
			for_each(vStu.begin(), vStu.end(), printStudent);
			cout << "————————————————————————————————" << endl;
			cout << endl;
		}
		else if (select == 2)
		{
			//查看老师
			cout << "————————————————————————————————" << endl;
			cout << "所有的老师信息如下：" << endl;
			for_each(vTea.begin(), vTea.end(), printTeacher);
			cout << "————————————————————————————————" << endl;
			cout << endl;
		}
		else
		{
			//返回上一级
			break;
		}
	}

	system("pause");
	system("cls");
}
//查看图书馆信息
void Manager::showLibrary()
{
	cout << "————————————————————————————————" << endl;
	cout << "图书馆信息如下：" << endl;

	for (vector<Library>::iterator it = vLib.begin(); it != vLib.end(); it++)
	{
		cout << "图书馆编号：" << it->m_LibId << " 图书馆容量：" << it->m_MaxNum << endl;
	}
	cout << "————————————————————————————————" << endl;
	system("pause");
	system("cls");
}
//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！ " << endl;
	system("pause");
	system("cls");
}
//初始化容器
void Manager::initVector()
{
	//确保容器是清空的状态
	vStu.clear();
	vTea.clear();

	//读取信息 学生、老师
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量：" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前老师数量：" << vTea.size() << endl;
	ifs.close();

}
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//检测学生
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
		//检测老师
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