#pragma once
#include <vector>
#include <sstream>
#include "Admin.h"

class Parser
{
public:

    static vector<string> split(string line) {
        stringstream stream(line);
        string token;
        vector<string> info;
        while (getline(stream, token, ',')) info.push_back(token);
        return info;
    }
    static Client parseToClient(string line)
    {
        vector<string> v = split(line);
        Client c;
        c.setId_Client(stoi(v[0]));
        c.setname(v[1]);
        c.setPassword(v[2]);
        c.setBalance(stod(v[3]));
        return c;
    }
    static Employee parseToEmployee(string line)
    {
        vector<string> v = split(line);
        Employee e;
        e.setId_Employee(stoi(v[0]));
        e.setname(v[1]);
        e.setPassword(v[2]);
        e.setBalance(stod(v[3]));
        e.setSalary(stod(v[4]));
        return e;
    }
    static Admin parseToAdmin(string line)
    {
        vector<string> v = split(line);
        Admin a;
        a.setId_Admin(stoi(v[0]));
        a.setname(v[1]);
        a.setPassword(v[2]);
        a.setBalance(stod(v[3]));
        a.setSalary(stod(v[4]));
        return a;

    }
};