#include "../include/RegEmp.h"

RegEmp::RegEmp(std::string fName, std::string sName, int salary, int addHours) : 
Employee(fName, sName, salary)
{
    this->addHours = addHours;
}

int RegEmp::calcSal()
{
    return (addHours * 100) + salary;
}

