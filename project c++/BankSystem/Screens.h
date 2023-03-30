
#pragma once
#include"ClientManger.h"
#include<iostream>
#include"EmployeeManager.h"
#include"AdminManager.h"
#include "Windows.h"
using namespace std;
class   Screens {
public:
	static void bankName() {
		cout << "\n\n\n";
		cout << "\t\t\t\t\t    ======    ==     ======    " << endl;
		cout << "\t\t\t\t\t   =          ==     =     =   " << endl;
		cout << "\t\t\t\t\t  =           ==     =     =   " << endl;
		cout << "\t\t\t\t\t  =           ==     ======    " << endl;
		cout << "\t\t\t\t\t  =           ==     =     =   " << endl;
		cout << "\t\t\t\t\t   =          ==     =     =   " << endl;
		cout << "\t\t\t\t\t    ======    ==     ======    " << endl;

	}
	static void welcome() {
		cout << "\n\n\n\n\n";
		cout << "\t \t   ==      ==  ======   ==     ======    = = = =    ==       ==   ======     " << endl;
		cout << "\t \t   ==      ==  ==       ==    =         =        =  == =   = ==   ==         " << endl;
		cout << "\t \t   ==      ==  ==       ==    =         =        =  ==   ==  ==   ==         " << endl;
		cout << "\t \t   ==  ==  ==  ======   ==    =         =        =  ==       ==   ======     " << endl;
		cout << "\t \t   == =  = ==  ==       ==    =         =        =  ==       ==   ==         " << endl;
		cout << "\t \t   == =  = ==  ==       ==    =         =        =  ==       ==   ==         " << endl;
		cout << "\t \t   ==      ==  ======   ==     ======     = = = =    ==       ==   ======     " << endl;
		bankName();
		Sleep(4000);
		system("cls");


	}
	static void loginOptions() {
		cout << "--------Log As---------" << endl;
		cout << "(1) Admin" << endl;
		cout << "(2) Employee" << endl;
		cout << "(3) Client" << endl;
		cout << "Login As: ";
	}
	static int loginAs() {
		loginOptions();
		int num;
		cout << "Enter Your Choice: ";
		cin >> num;
		if (num == 1 || num == 2 || num == 3)
		{
			system("cls");
			return num;
		}
		else
		{
			system("cls");
			return loginAs();
		}

	}

	static void invalid(int c)
	{
		system("cls");
		cout << "Invalid Id or Password \n";
		loginScreen(c);

	}
	static void logout()
	{
		system("cls");
		loginScreen(loginAs());
	}
	static void loginScreen(int c)
	{
		int num = c;
		int id;
		string pass;
		cout << "Enter Id: ";
		cin >> id;
		cout << "Enter Password: ";
		cin >> pass;
		switch (num)
		{
		case 1:
			if (AdminManager::login(id, pass) != nullptr) {
				while (AdminManager::AdminOptions(AdminManager::login(id, pass)) != false);
				logout();
			}
			else
				invalid(1);
			break;
		case 2:
			if (EmployeeManager::login(id, pass) != nullptr) {
				while (EmployeeManager::employeeOptions(EmployeeManager::login(id, pass)) != false);
				logout();
			}
			else
				invalid(2);
			break;

		case 3:
			if (ClientManger::login(id, pass) != nullptr) {
				while (ClientManger::clientOptions(ClientManger::login(id, pass)) != false);
				logout();
			}
			else
				invalid(3);
			break;
		default:
			system("cls");
			loginOptions();
		}

	}
	static void runApp() {
		FileManager::getAllData();
		//FileManager::getAllClients();
		//FileManager::getAllEmployees();
		//FileManager::getAllAdmins();
		welcome();
		loginScreen(loginAs());


	}
};