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
void Department::modifyEmployee(int Employee_No,int Modified_Salary){
    DIO[Employee_No]->setSal(Modified_Salary);
}
void Department::calcSalary(int Employee_No){
    std::cout<<"Employee No "<<Employee_No<<"'s Salary is "<<DIO[Employee_No]->calcSal()<<"\n";
}
void Department::calcAllSalary(){
    for(int i =0;i<current_no_of_Employees;i++){
        calcSalary(i);
    }
}
void Department::deleteEmployee(int Employee_no){
    delete DIO[Employee_no];
    DIO[Employee_no]=NULL;
    for(int i=Employee_no;i<current_no_of_Employees-1;i++){
        DIO[i]=DIO[i+1];
    }
    current_no_of_Employees--;
}