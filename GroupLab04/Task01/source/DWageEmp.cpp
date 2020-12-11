#include "../include/DWageEmp.h"

DWageEmp::DWageEmp(std::string fName, std::string sName, int hourRate, int hours) : 
Employee(fName, sName, 0)
{
    this->hRate = hourRate;
    this->hours = hours;
}

int DWageEmp::calcSal(){
    return (hRate * hours);
}