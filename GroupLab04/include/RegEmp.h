#pragma once

#include "Employee.h"

class RegEmp : public Employee
{
public:
    RegEmp(std::string fName, std::string sName, int salary, int addHours);
    int calcSal();

private:
    int addHours;
};