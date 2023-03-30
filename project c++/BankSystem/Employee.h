#pragma once
#pragma once
#include "Validation.h"
#include "Client.h"

class Employee : public Client
{
    double salary;
    int Id_Employee;

public:
    static int CountEmployee;
    Employee() :Client()
    {
        CountClient--;
        Id_Employee = CountEmployee + 1;
        CountEmployee++;
        salary = 5000;
    }
    Employee(string name, string password, double balance, double salary) :Client(name, password, balance)
    {
        CountClient--;
        Id_Employee = CountEmployee + 1;
        CountEmployee++;
        setSalary(salary);
    }
    void setId_Employee(int id)
    {
        Id_Employee = id;
    }
    int getId_Employee()
    {
        return Id_Employee;
    }
    void setSalary(double salary)
    {
        if (Validation::validateSalary(salary))
            this->salary = salary;
        else cout << "Invalid salary \n" << endl;
    }
    double getSalary()
    {
        return salary;
    }
    void printInfo()
    {
        cout << "Id: " << Id_Employee << endl;
        Person::printInfo();
        cout << "Salary: " << getSalary() << endl;
    }
    void addClient(Client& c)
    {
        allClient.push_back(c);
    }

    Client* searchClient(int id) {
        for (int i = 0; i < allClient.size(); i++)
        {
            if (allClient[i].getId_Client() == id) {
                Client* c = &allClient[i];
                return c;
            }
        }
        return nullptr;
    }
    void listClient()
    {

        for (int i = 0; i < allClient.size(); i++)
        {

            cout << "client no:" << i + 1 << "  Id: " << allClient[i].getId_Client() << " " << "Name: " << allClient[i].getname()
                << " " << " Password: " << allClient[i].getPassword() << " " << "Balance: " << allClient[i].getbalance() << endl;

        }
    }
    void editClient(int id, string name, string password, double balance)
    {
        Client* c = searchClient(id);
        c->setname(name);
        c->setPassword(password);
        c->setBalance(balance);


    }


};
static vector<Employee> allEmployee;
int Employee::CountEmployee = 0;