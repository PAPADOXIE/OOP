#include "../include/Company.h"
#include <iostream>

Company::Company(std::string companyName)
{
    noOfEmployees = 0;
    production = new Department("Production", 20);
    finance = new Department("Finance", 10);
}

void Company::addEmployee(int department,
                          int type,
                          Employee *employee)
{
    if (noOfEmployees == 30)
    {
        return;
    }

    noOfEmployees++;

    switch (department)
    {
    case 1:
        production->addEmployee(employee, type);
        break;
    case 2:
        finance->addEmployee(employee, type);
        break;
    }
}

std::ostream &operator << (std::ostream &out, Company &company){
    out << "Total Number of Employees: " << company.noOfEmployees << '\n';
    out << *production;
    out << *finance;
    return out;
}