#include "Employee.h"
#include <String>
#include <iostream>

using namespace std;

Employee::Employee()
	: School{}
{}

Employee::Employee(int id, string name, int age, string phone)
	: School{ id,name,age,phone}
{};

//Employee::Employee(int years,string job)
//	: m_job{job},m_years{years}
//{}

void Employee::show()
{
	School::show();
	cout << "teacher: " << m_job << '\n';
	
};

void Employee::input()
{
	cout << "I am Teacher" << '\n';
	School::input();

	
	cout << "Subject: "; getline(cin, m_job);

};


string Employee::getJob()
{
	return m_job;
};

