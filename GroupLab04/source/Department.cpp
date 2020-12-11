#include "../include/Department.h"
#include "../include/DWageEmp.h"
#include "../include/RegEmp.h"
#include "../include/ConEmp.h"
#include <iostream>
Department::Department(std::string Title,int no_of_possible_Employees){
    this->Title=Title;
    this->no_of_possible_Employees=no_of_possible_Employees;
    current_no_of_Employees=0;
    DIO = new Employee*[this->no_of_possible_Employees];
    DIO={NULL};
}
void Department::addEmployee(Employee *Jojo,int Type){
    if(Type==1){
        DIO[current_no_of_Employees++]=Jojo;
    }
    else if(Type==2){
        DIO[current_no_of_Employees++]=Jojo;
    }
    else if(Type==3){
        DIO[current_no_of_Employees++]=Jojo;
    }
}
void modifyEmployee(int Employee_No,int Modified_Salary){
    
}