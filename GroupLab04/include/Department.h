#pragma once
#include "Employee.h"
#include <string>
class Department{
    std::string Title;
    int no_of_possible_Employies;
    int current_no_of_Employies;
    Employee** DIO;
Department(std::string Title,int no_of_possible_Employies);
void addEmployee(Employee Jojo,int Type);
void modifyEmployee(int Employee_No,int Modified_Salary);
void calcSalary(int Employee_No);
void calcAllSalary();
void deleteEmployee(int Employee_no);
};