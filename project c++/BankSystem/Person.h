#pragma once
#pragma once
#include <string>
#include "Validation.h"
#include <iostream>

class Person
{
    string name;
    string password;
    double balance;
public:
    Person() {
        balance = 1500;
    }
    Person(string name, string password, double balance)
    {
        setname(name);
        setPassword(password);
        setBalance(balance);
    }

    void setname(string name)
    {
        if (Validation::validateName(name))
            this->name = name;
        else
            cout << "Invalid Name:" << endl;

    }
    void setPassword(string password)
    {
        if (Validation::validatePassword(password))
            this->password = password;
        else
            cout << " \n password is invalid \n" << endl;
    }
    void setBalance(double balance)
    {
        if (Validation::validateBalance(balance))
            this->balance = balance;
        else
            cout << " \n Balance must be at least 1500 \n" << endl;
    }

    string getname()
    {
        return name;
    }
    string getPassword()
    {
        return password;
    }
    double getbalance()
    {
        return balance;
    }
    void printInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Password: " << password << endl;
        cout << "Balance: " << balance << endl;

    }

};