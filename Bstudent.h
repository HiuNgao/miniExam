#pragma once
#include <string>
#include <iostream>
#include "School.h"

using namespace std;

class Bstudent : public School
{
private:
	string m_class;
	int m_point{};

public:

	Bstudent() {}
	
	Bstudent(int id, string name, int age, string phone)
		: School{ id, name, age, phone }
	{}
	
		
	

	virtual void show() ;
	virtual void input() ;

	string getClass();
	int getPoint();

};

