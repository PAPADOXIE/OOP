#pragma once

#include "Employee.h"

class ConEmp : public Employee
{
public:
    ConEmp(std::string fName, std::string sName, int salary, int hourRate, int hours);
    int calcSal();

private:
    int hRate;
    int hours;
};