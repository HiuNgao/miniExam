

#include <string>
#include <vector>
#include <fstream>
#include "Employee.h"
#include "Bstudent.h"
#include "School.h"
#include "Utils.h"
#include "miniExam.h"
#include<algorithm>
#include <iostream>



//
using namespace std;



void showMenu()
{
	cout << "-----------------------Menu----------------------" << '\n';
	cout << "1. Add Members " << '\n';
	cout << "2. Edit Members " << '\n';
	cout << "3. Remove Members " << '\n';
	cout << "4. Sort Members " << '\n';
	cout << "5. Show all Members " << '\n';
	cout << "6. Find Members " << '\n';
	cout << "0. Exit " << '\n';
	cout << "--------------------------------------------------" << '\n';
	cout << "Please choose: ";

};

void showAll(vector<School*> list) {
    for (auto s : list) {
        s->show();
    }
};

School* findByName(vector<School*>& list, string name) {
	for (auto s : list) {
		if (s->getName().compare(name) == 0) {
			return s;
		}

		return nullptr;
	}
}
School* findByPhone(vector<School*>& list, string phone)
{
	for (auto s : list)
	{
		if (s->getPhone().compare(phone) == 0) {
			return s;
		}
	}
};





void editSchool(vector<School*>& list, string name) {
	auto s = findByName(list, name);

	s->input();
}


void removeSchool(vector<School*>& list, string name) {
	auto s = findByName(list, name);

	auto index = std::find(list.begin(), list.end(), s);

	list.erase(index);
}


void menunv()
{
	cout << "---------ADD Member---------" << "\n";
	cout << "1. ADD Student" << '\n';
	cout << "2. ADD Employee" << '\n';
	cout << "0. Exit" << '\n';
	cout << "-------------END------------" << '\n';
}


//void sortSchool(vector<School*>& list) {
//	cout << "Sort by name" << '\n';
//	std::sort(
//		list.begin(),
//		list.end(),
//		[](const auto& s1, const auto& s2) {return s1->getName() < s2->getName(); }
//	);
//	
//};




void addSchool(vector<School*>& list) {

	int choose;
	menunv();


	bool exit{ false };

	while (true) {
		cin >> choose;
		switch (choose) {


		case 1:
		{
			School* s{ new Bstudent{} };

			s->input();

			list.push_back(s);
		}

		break;

		case 2:
		{
			School* s{ new Employee{} };
			s->input();
			list.push_back(s);
		}
		break;
		
		case 0:
			exit = true;
			break;

		}

		if (exit) {
			break;
		}
		menunv();





	}

};

void menufind() {
	cout << "----Find Member----" << '\n';
	cout << "1. Find by name " << '\n';
	cout << "2. Find by Phone " << '\n';
	cout << "0. exit " << '\n';
	cout << "--------END--------" << '\n';
	cout << "Enter Choose: ";
};

void findSchool(vector<School*>& list) {
	int choose;
	string name;
	string phone;
	
	
	menufind();

	bool exit{ false };

	while (true) {
		cin >> choose;
		switch (choose) {


		case 1:
		{
			cout << "Remove Members" << '\n';
			cout << "Enter name: ";
			getline(cin, name);
			findByName(list, name);
		}

		break;

		case 2:
		{
			cout << "Remove Members" << '\n';
			cout << "Enter phone: ";
			getline(cin, phone);
			findByPhone(list, phone);
		}
		break;

		case 0:
			exit = true;
			break;

		}

		if (exit) {
			break;
		}
		menufind();


	}
};



int main()
{

	
	vector<School*> list{};

	ifstream fileIn{ "input.txt" };
	
	string line;
	while (getline(fileIn, line)) {

		auto vec = Utils::split(line, ",");

		if (vec.at(0) == "1") {
			list.push_back(new Bstudent{ stoi(vec.at(1)), vec.at(2), stoi(vec.at(3)), vec.at(4) });
		}
		else if (vec.at(0) == "2") {
			list.push_back(new Employee{ stoi(vec.at(1)), vec.at(2), stoi(vec.at(3)), vec.at(4) });
		}
		
	}

	


	int choose;
	bool exit{ false };

	string name;

	showMenu();
	while (true) {

		cin >> choose;
		cin.ignore(100, '\n');
		switch (choose)
		{
		case 1:
			cout << "Add Members" << '\n';

			addSchool(list);
			break;
		case 2:
			cout << "Edit Members" << '\n';
			cout << "Enter name: ";
			getline(cin, name);
			editSchool(list, name);
			break;
		case 3:
			cout << "Remove Members" << '\n';
			cout << "Enter name: ";
			getline(cin, name);
			removeSchool(list, name);
			break;
		case 4:
			/*cout << "Sort Members" << '\n';*/
			///*sortSchool(list);*/
			cout << "Sort by name" << '\n';
			std::sort(
				list.begin(),
				list.end(),
				[](const auto& s1, const auto& s2) {return s1->getName() < s2->getName(); }
			);
			showAll(list);
			break;
		case 5:
			cout << "Show all Members" << '\n';
			showAll(list);
			break;
		case 6:
			cout << "Find members" << '\n';
			findSchool(list);
			break;
		case 0:
			cout << "Exit" << '\n';
			exit = true;
			break;
		}
		if (exit) {
			break;
		}
		showMenu();
	};

	
}

