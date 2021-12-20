#include "Employee.h"
#include <String>
#include <iostream>

using namespace std;

Employee::Employee()
	: School()
{}

Employee::Employee(int id, string name, int age, string phone) 
	: School{ id, name, age, phone }
{};

 


void Employee::show()
{
	School::show();
	cout << "Working at the school " << m_years << " and" << "teacher: " << m_job << '\n';
	
};

void Employee::input()
{
	cout << "I am Employee" << '\n';
	School::input();

	cout << "Time at the school:  "; cin >> m_years; cin.ignore(1000, '\n');
	cout << "Subject: "; getline(cin, m_job);

};

int Employee::getYears()
{
	return m_years;
};
string Employee::getJob()
{
	return m_job;
};

