#pragma once
#include "Validation.h"
#include "Admin.h"
#include "Clientmanger.h"
#include"EmployeeManager.h"
#include "Windows.h"
class AdminManager {

public:
    static void printAdminMenu() {
        system("cls");
        cout << "------------Admin Option-----------\n";
        cout << "(1) Display My Info \n";
        cout << "(2) Update Password \n";
        cout << "(3) Add New Client \n";
        cout << "(4) Search For Client \n";
        cout << "(5) List All Client \n";
        cout << "(6) Edit Client Info \n";
        cout << "(7) Add New Employee \n";
        cout << "(8) Search For Employee\n";
        cout << "(9) List All Employee \n";
        cout << "(10) Edt Employee Info \n";
        cout << "(11) Logout\n";

    }
    static void back(Admin* admin)
    {
        cout << endl;
        system("pause");
        AdminOptions(admin);

    }
    static Admin* login(int id, string password) {
        for (int i = 0; i < allAdmin.size(); i++)
        {
            if (allAdmin[i].getId_Admin() == id && allAdmin[i].getPassword() == password)
            {
                Admin* a = &allAdmin[i];
                return a;
            }
        }
        return nullptr;
    }
    static bool AdminOptions(Admin* admin) {
        printAdminMenu();
        int num;
        Employee e;
        int id;
        cout << "Enter Your Choice: ";
        cin >> num;
        switch (num)
        {
        case 1:
            system("cls");
            admin->printInfo();
            break;
        case 2:
            system("cls");
            ClientManger::updatePassword(admin);
            FileManager::UpdateAdmin();
            break;
        case 3:
            EmployeeManager::newClient(admin);
            break;
        case 4:
            EmployeeManager::searchForClient(admin);
            break;
        case 5:
            system("cls");
            EmployeeManager::listAllClients(admin);
            break;
        case 6:
            EmployeeManager::editClientInfo(admin);
            break;
        case 7:
            e.setname(Validation::EnterName());
            e.setPassword(Validation::EnterPassword());
            e.setBalance(Validation::EnterBalance());
            e.setSalary(Validation::EnterSalary());
            admin->addEmployee(e);
            FileManager::UpdateEmployee();
            cout << "Employee Added Successfully\n";
            break;
        case 8:
            system("cls");
            cout << "Enter Employee id: ";
            cin >> id;
            if (admin->searchEmployee(id) == nullptr)
                cout << "Employee not found\n";
            else
                admin->searchEmployee(id)->printInfo();
            break;
        case 9:
            system("cls");
            admin->listEmployee();
            break;
        case 10:
            system("cls");
            cout << "Enter Employee Id: ";
            cin >> id;
            if (admin->searchEmployee(id) == nullptr)
                cout << "Employee not found\n";
            else
            {
                string name = Validation::EnterName();
                string pass = Validation::EnterPassword();
                double salary = Validation::EnterSalary();
                admin->editEmployee(id, name, pass, salary);
                FileManager::UpdateEmployee();
                cout << "Employee Info Updated\n";
            }
            break;
        case 11:
            return false;
            break;
        default:
            system("cls");
            AdminOptions(admin);
            return true;
        }
    }
};
