#pragma once

#include <string>

class Employee
{
public:
    Employee(std::string fName, std::string sName, int salary);
    virtual int calcSal();
    void setSal(int salary);
protected:
    std::string fName;
    std::string sName;
    int salary;

    friend std::ostream &operator << (std::ostream &out, Employee *employee);
};