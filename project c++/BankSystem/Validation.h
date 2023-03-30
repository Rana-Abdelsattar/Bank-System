#pragma once
#include <string>
#include<iostream>

using namespace std;

class Validation
{
public:
    static string EnterName()
    {
        string name;
        cout << "Enter the Name: ";
        cin >> name;
        while (!validateName(name))
        {
            cout << "Invalid name" << endl;
            cout << "Name must be only alphabetic and at least 5 letters and at most 20 letters " << endl;
            cout << "Enter The Name: ";
            cin >> name;

        }
        return name;
    }

    static string EnterPassword()
    {

        string pass;
        cout << "Enter The Password: ";
        cin >> pass;
        while (!validatePassword(pass))
        {
            cout << "Invalid Password \n";
            cout << "Password must be at least 8 characters and at most 20 characters \n";
            cout << "Enter The Password: ";
            cin >> pass;
        }
        return pass;
    }

    static double EnterBalance()
    {
        double balance;
        cout << "Enter the Balance: ";
        cin >> balance;
        while (!validateBalance(balance))
        {
            cout << "Invalid balance \n";
            cout << "Balance must be at least 1500 \n";
            cout << "Enter the Balance : ";
            cin >> balance;
        }
        return balance;
    }
    static double EnterSalary()
    {
        double salary;
        cout << "Enter the Salary: ";
        cin >> salary;
        while (!validateSalary(salary))
        {
            cout << "Invalid salary \n";
            cout << "Salary must be at least 5000 \n";
            cout << "Enter the Salary : ";
            cin >> salary;
        }
        return salary;
    }
    static bool validateName(string name)
    {
        for (int i = 0; i < name.size(); i++)
        {
            if (!isalpha(name[i]) || name.size() < 5 || name.size() > 20)
                return false;
        }
        return true;
    }
    static bool validatePassword(string password)
    {
        return(password.length() >= 8 && password.length() <= 20);
    }
    static  bool validateBalance(double balance)
    {
        return(balance >= 1500);
    }
    static bool validateSalary(double salary)
    {
        return(salary >= 5000);
    }
}; 
