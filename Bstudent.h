#pragma once
#include <string>
#include <iostream>
#include "School.h"

using namespace std;

class Bstudent : public School
{
private:
	string m_class;
	

public:

	Bstudent() {}

	
	
	Bstudent(int id, string name,int age,string phone)
		: School{ id, name,age,phone}
	{}
	 
	/*Bstudent(string aclass,int point)
		: m_class{aclass},m_point{point}
	{}*/
	
    void show() override ;
    void input() override;

	string getClass();
	

};

