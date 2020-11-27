#pragma once

#include "Date.h"

class Employee
{
public:
    Employee();
    Employee(Date hire_date);
    ~Employee();
    //Friends
    friend std::ostream &operator << (std::ostream &out, const Employee &employee);

private:
    static int num_employees;
    int employee_number;
    Date hire_date;
};