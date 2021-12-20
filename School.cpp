#include "School.h"
#include <string>
#include <iostream>


using namespace std;

void School::show()
{

	cout << m_id << " " << m_name << " " << m_age << " " << m_phone << '\n';

}

void School::input()
{
	cout << "Enter id: ";
	cin >> m_id;

	cin.ignore(100, '\n');

	cout << "Enter name: ";
	getline(cin, m_name);

	cout << "Enter Phone: ";
	getline(cin, m_phone);

	cout << "Enter Age: "; cin >> m_age;
	cin.ignore(1000, '\n');

}
string School::getName()
{
	return m_name;
};
string School::getPhone()
{
	return m_phone;
};

int School::getAge()
{
	return m_age;
};
int School::getId()
{
	return m_id;
};








