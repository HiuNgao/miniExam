#include "Bstudent.h"
#include <string>
#include <iostream>
using namespace std;

//Bstudent::Bstudent()
//	: School()
//{};
//
//Bstudent::Bstudent(int id, string name, int age, string phone)
//	: School{ id,name,age,phone }
//{};


void Bstudent::input()
{
	
	cout << "i am a student" << '\n';
	School::input();

	cout << "Enter Class: "; getline(cin, m_class);
	cout << "Enter Point: "; cin >> m_point; cin.ignore(1000, '\n');
};

void Bstudent::show()
{
	School::show();
	cout << "Student in class " << m_class << "Point years " << m_point << '\n';
};

string Bstudent::getClass()
{
	return m_class;
};

//int Bstudent::getPoint()
//{
//	return m_point;
//};




