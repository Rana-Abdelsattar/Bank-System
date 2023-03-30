#pragma once
#include"Employee.h"
#include"FileManager.h"
# include "ClientManger.h"
using namespace std;
class  EmployeeManager {
public:
	static void printEmployeeMenu() {
		system("cls");
		cout << "-----------Employee Option-----------\n";
		cout << "(1) Display My Info \n";
		cout << "(2) Update Password \n";
		cout << "(3) Add New Client \n";
		cout << "(4) Search For Client \n";
		cout << "(5) List All Client \n";
		cout << "(6) Edit Client Info \n";
		cout << "(7) Logout\n";

	}
	static void back(Employee* employee)
	{
		cout << endl;
		system("pause");
		employeeOptions(employee);

	}
	static void newClient(Employee* employee) {
		Client c;
		c.setname(Validation::EnterName());
		c.setPassword(Validation::EnterPassword());
		c.setBalance(Validation::EnterBalance());
		employee->addClient(c);
		FileManager::UpdateClient();
		cout << "Client Added Successfully \n";
	}
	static void listAllClients(Employee* employee) {
		employee->listClient();
	}
	static void searchForClient(Employee* employee) {
		int id;
		cout << "Enter client id: ";
		cin >> id;
		if (employee->searchClient(id) == nullptr)
			cout << "Client not found \n";
		else
			employee->searchClient(id)->printInfo();

	}
	static void editClientInfo(Employee* employee) {
		int id;
		string name;
		string pass;
		double balance;
		cout << "Enter Client Id:";
		cin >> id;
		if (employee->searchClient(id) == nullptr)
		{
			cout << "Client not found \n";
		}
		else
		{
			name = Validation::EnterName();
			pass = Validation::EnterPassword();
			balance = Validation::EnterBalance();
			employee->editClient(id, name, pass, balance);
			FileManager::UpdateClient();
			cout << "Client Info Updated\n";
		}

	}
	static Employee* login(int id, string password) {

		for (int i = 0; i < allEmployee.size(); i++)
		{
			if (allEmployee[i].getId_Employee() == id && allEmployee[i].getPassword() == password)
			{
				Employee* e = &allEmployee[i];
				return e;
			}
		}
		return nullptr;
	}
	static bool employeeOptions(Employee* employee) {
		printEmployeeMenu();
		int num;
		cout << "Enter Your Choice: ";
		cin >> num;
		switch (num)
		{
		case 1:
			system("cls");
			employee->printInfo();
			break;
		case 2:
			system("cls");
			ClientManger::updatePassword(employee);
			FileManager::UpdateEmployee();
			break;
		case 3:
			system("cls");
			newClient(employee);
			break;
		case 4:
			system("cls");
			searchForClient(employee);
			break;
		case 5:
			system("cls");
			listAllClients(employee);
			break;
		case 6:
			system("cls");
			editClientInfo(employee);
			break;
		case 7:
			return false;
			break;
		default:
			system("cls");
			employeeOptions(employee);
			return true;
		}

		back(employee);
		return true;
	}
};
