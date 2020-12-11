#include "../include/Employee.h"
#include <iostream>

Employee::Employee(std::string fName, std::string sName, int salary){
    this->fName = fName;
    this->sName = sName;
    this->salary = salary;
}

int Employee::calcSal(){
    return salary;
}

std::ostream &operator << (std::ostream &out, Employee *employee){
    out << "Name: " << employee->fName << " " << employee->sName;
    out << "\nSalary: " << employee->calcSal() << '\n';
    return out;
}