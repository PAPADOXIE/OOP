#include "../include/Employee.h"

int Employee::num_employees = 0;

Employee::Employee(){
    employee_number = num_employees++;
}

Employee::Employee(Date hire_date){
    employee_number = num_employees++;
    this->hire_date = hire_date;
}

std::ostream &operator << (std::ostream &out, const Employee &employee){
    out << "Employee Number: " << employee.employee_number << std::endl;
    out << employee.hire_date;
    return out;
}

Employee::~Employee(){
    num_employees--;
}