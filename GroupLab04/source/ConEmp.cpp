#include "../include/ConEmp.h"

ConEmp::ConEmp(std::string fName, std::string sName, int salary, int hourRate, int hours) : 
Employee(fName, sName, salary)
{
    this->hRate = hourRate;
    this->hours = hours;
}

int ConEmp::calcSal(){
    return (hRate * hours) + salary;
}