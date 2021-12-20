#pragma once
#include <string>
#include <iostream>
#include "School.h"

using namespace std;
class Employee : public School
{
private:
	int m_years{};
	string m_job;

public:
	Employee();
	
	Employee(int id, string name, int age, string phone);
	

	void show() override;

	void input() override;

	int getYears();
	string getJob();




};

