#pragma once
#include "Employee.h"
#include <string>
class Department{
protected:
    std::string Title;
    int no_of_possible_Employees;
    int current_no_of_Employees;
    Employee** DIO;
public:
Department(std::string Title,int no_of_possible_Employees);
void addEmployee(Employee *Jojo,int Type);
void modifyEmployee(int Employee_No,int Modified_Salary);
void calcSalary(int Employee_No);
void calcAllSalary();
void deleteEmployee(int Employee_no);
};