#include "../include/Department.h"
Department::Department(std::string Title,int no_of_possible_Employees){
    this->Title=Title;
    this->no_of_possible_Employees=no_of_possible_Employees;
    current_no_of_Employees=0;
    DIO = new Employee*[this->no_of_possible_Employees];
    DIO={NULL};
}
