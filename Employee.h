#pragma once
#include <string>
#include <iostream>
#include "School.h"

using namespace std;
class Employee : public School
{
private:
	
	string m_job;

public:
	Employee() {};
	
	Employee(int id, string name, int age, string phone);
	
	/*Employee(int years, string job);*/


	void show() override;

	void input() override;

	
	string getJob();




};

