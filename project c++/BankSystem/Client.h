#pragma once
#include "Person.h"
#include <vector>

class Client : public Person
{
    int Id_Client;
public:
    static int CountClient;

    Client() :Person()
    {
        Id_Client = CountClient + 1;
        CountClient++;
    }
    Client(string name, string password, double balance) :Person(name, password, balance)
    {
        Id_Client = CountClient + 1;
        CountClient++;
    }
    void setId_Client(int id)
    {
        Id_Client = id;
    }
    int getId_Client()
    {
        return Id_Client;
    }
    void deposit(double amount)
    {
        setBalance(getbalance() + amount);
        cout << "Successful transaction \n";
        cout << "Your New balance after deposit " << amount << " is: " << getbalance() << endl;
    }

    void withdraw(double amount)
    {
        if (amount < getbalance())
        {
            setBalance(getbalance() - amount);
            cout << "Successful transaction \n";
            cout << "balance after withdraw " << amount << "is: " << getbalance() << endl;
        }
        else
            cout << "amount exceeded balance \n";
    }

    void tranferTo(double amount, Client& recipient)
    {
        if (amount < getbalance())
        {
            setBalance(getbalance() - amount);
            recipient.setBalance(recipient.getbalance() + amount);
            cout << "Your New balance after Transferring " << amount << " is: " << getbalance() << endl;
        }
        else
            cout << "amount exceeded balance \n";
    }

    void checkBalance()
    {
        cout << "Your Balance: " << getbalance() << endl;
    }
    void printInfo()
    {
        cout << "Id: " << Id_Client << endl;
        Person::printInfo();
    }
};
int Client::CountClient = 0;
static vector<Client> allClient;
