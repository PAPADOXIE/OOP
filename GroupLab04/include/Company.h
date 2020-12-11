#pragma once

#include <string>
#include "Employee.h"
#include "Department.h"

class Company
{
public:
    Company(std::string companyName);
    void addEmployee(int department,
                     int type,
                     Employee *employee);

private:
    Department *production;
    Department *finance;
    std::string companyName;
    int noOfEmployees;

friend std::ostream &operator << (std::ostream &out, Company &company);
};