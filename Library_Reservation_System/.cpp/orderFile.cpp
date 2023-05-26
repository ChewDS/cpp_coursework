#include"orderFile.h"

//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;      //日期
	string interval;  //时间段
	string stuId;     //学生编号
	string stuName;   //学生姓名
	string roomId;    //图书馆编号
	string status;    //预约状态

	this->m_Size = 0;

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		/*cout << date << endl;
		cout << interval << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << seatId << endl;
		cout << status << endl;
		cout << endl;*/

		//date:11111
		string key;
		string value;

		map<string, string>m;

		//string容器成员函数查找
		int position = date.find(":");//4
		if (position != -1)
		{
			key = date.substr(0, position);
			value = date.substr(position + 1, date.size() - position - 1);//size=10 position=4 size-position-1=6-1=5

			m.insert(make_pair(key, value));

		}

		position = interval.find(":");
		if (position != -1)
		{
			key = interval.substr(0, position);
			value = interval.substr(position + 1, interval.size() - position - 1);

			m.insert(make_pair(key, value));

		}

		position = stuId.find(":");
		if (position != -1)
		{
			key = stuId.substr(0, position);
			value = stuId.substr(position + 1, stuId.size() - position - 1);

			m.insert(make_pair(key, value));

		}

		position = stuName.find(":");
		if (position != -1)
		{
			key = stuName.substr(0, position);
			value = stuName.substr(position + 1, stuName.size() - position - 1);

			m.insert(make_pair(key, value));

		}

		position = roomId.find(":");
		if (position != -1)
		{
			key = roomId.substr(0, position);
			value = roomId.substr(position + 1, roomId.size() - position - 1);

			m.insert(make_pair(key, value));

		}
		position = status.find(":");
		if (position != -1)
		{
			key = status.substr(0, position);
			value = status.substr(position + 1, status.size() - position - 1);

			m.insert(make_pair(key, value));

		}

		//将小容器放到大容器中

		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();


	//测试大map容器
	/*for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	{
		cout << "key1 =  " << it->first << " value1 =  " << endl;
		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
		{
			cout <<"key = " << mit->first << " value =  " << mit->second << " ";
		}
		cout << endl;
	}*/
}


//更新预约记录

void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < m_Size; i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}
