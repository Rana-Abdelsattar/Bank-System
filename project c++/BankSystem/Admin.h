#pragma once
#include "Employee.h"


class Admin :public Employee
{
    int Id_Admin;
public:
    static int CountAdmin;
    Admin() :Employee()
    {

        CountClient--;
        CountEmployee--;
        Id_Admin = CountAdmin + 1;
        CountAdmin++;
    }
    Admin(string name, string password, double balance, double salary) :Employee(name, password, balance, salary)
    {
        CountClient--;
        CountEmployee--;
        Id_Admin = CountAdmin + 1;
        CountAdmin++;

    }
    void setId_Admin(int id)
    {
        Id_Admin = id;
    }
    int getId_Admin()
    {
        return Id_Admin;
    }
    void printInfo()
    {
        cout << "Id: " << Id_Admin << endl;
        Person::printInfo();
        cout << "Salary: " << getSalary() << endl;

    }

    void addEmployee(Employee& employee)
    {
        allEmployee.push_back(employee);
    }
    Employee* searchEmployee(int id)
    {

        for (int i = 0; i < allEmployee.size(); i++)
        {
            if (allEmployee[i].getId_Employee() == id)

            {
                Employee* e = &allEmployee[i];
                return e;
            }

        }
        return nullptr;
    }

    void editEmployee(int id, string name, string password, double salary)
    {
        Employee* e = searchEmployee(id);
        e->setname(name);
        e->setPassword(password);
        e->setSalary(salary);
    }
    void listEmployee()
    {
        for (int i = 0; i < allEmployee.size(); i++)
        {
            cout << "Employee no:" << i + 1 << "  Id: " << allEmployee[i].getId_Employee() << " " << "  Name:  " << allEmployee[i].getname()
                << " " << "  Password:  " << allEmployee[i].getPassword() << " " << "  Balance:  " << allEmployee[i].getbalance()
                << "  Salary:  " << allEmployee[i].getSalary() << endl;
        }
    }
};
static vector<Admin> allAdmin;
int Admin::CountAdmin = 0;
