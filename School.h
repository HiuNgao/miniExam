#pragma once

#include <iostream>
#include <string>

using namespace std;
class School
{
protected:
	int m_age{};
	string m_name;
	string m_phone;
	int m_id{};

public:
	School() {};
		
	School(int id, string name, int age,string phone) 
		: m_age{age},m_name{name},m_phone{phone},m_id{id}
	{}

	virtual void show();

	virtual void input();

	string getName();
	string getPhone();
	int getAge();
	int getId();

};

