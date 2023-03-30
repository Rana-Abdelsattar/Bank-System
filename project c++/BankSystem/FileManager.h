
#pragma once
#include "DataSourceInterface.h"
#include "Admin.h"
#include <fstream>
#include"Parser.h"


class FileManager :public DataSourceInterface
{
public:

    static void addClient(Client c)
    {
        fstream file;
        file.open("Client.txt", ios::app);
        file << c.getId_Client() << "," << c.getname() << "," << c.getPassword() << "," << c.getbalance() << endl;
        file.close();

    }
    static void addEmployee(Employee e)
    {

        fstream file;
        file.open("Employee.txt", ios::app);
        file << e.getId_Employee() << "," << e.getname() << "," << e.getPassword() << "," << e.getbalance() << "," << e.getSalary() << endl;
        file.close();

    }
    static void addAdmin(Admin a)
    {
        fstream file;
        file.open("Admin.txt", ios::app);
        file << a.getId_Admin() << "," << a.getname() << "," << a.getPassword() << "," << a.getbalance() << a.getSalary() << endl;
        file.close();


    }
    static void getAllClients()
    {
        ifstream file;
        string line;
        file.open("Client.txt");
        while (getline(file, line))
        {
            Client c = Parser::parseToClient(line);
            allClient.push_back(c);
        }
        file.close();
    }
    static void getAllEmployees()
    {
        ifstream file;
        string line;
        file.open("Employee.txt");
        while (getline(file, line))
        {
            Employee e = Parser::parseToEmployee(line);
            allEmployee.push_back(e);
        }
        file.close();
    }
    static void getAllAdmins()
    {
        ifstream file;
        string line;
        file.open("Admin.txt");
        while (getline(file, line))
        {
            Admin a = Parser::parseToAdmin(line);
            allAdmin.push_back(a);
        }
        file.close();
    }
    static  void removeAllClients()
    {

        remove("Client.txt");
        fstream f1;
        f1.open("Client.txt", ios::out);
        f1.close();

    }
    static void removeAllEmployees()
    {
        remove("Employee.txt");
        fstream f1;
        f1.open("Employee.txt", ios::out);
        f1.close();

    }
    static void removeAllAdmins()
    {
        remove("Admin.txt");
        fstream f1;
        f1.open("Admin.txt", ios::out);
        f1.close();
    }

    static void UpdateClient()
    {
        removeAllClients();
        for (auto a : allClient)
        {
            addClient(a);
        }
    }
    static void UpdateEmployee()
    {
        removeAllEmployees();
        for (auto a : allEmployee)
        {
            addEmployee(a);
        }
    }
    static void UpdateAdmin()
    {
        removeAllAdmins();
        for (auto a : allAdmin)
        {
            addAdmin(a);
        }

    }

    static void getAllData()
    {
        getAllClients();

        getAllEmployees();
        getAllAdmins();

    }
};
