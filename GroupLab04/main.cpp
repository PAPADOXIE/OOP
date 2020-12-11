#include <time.h>
#include <random>
#include <iostream>
#include "include/ConEmp.h"
#include "include/RegEmp.h"
#include "include/DWageEmp.h"
#include "include/Employee.h"
#include "include/Company.h"

int main(void)
{
    srand(time(0));

    Company company("Gamer LLC");
    Employee *emparr[10];

    //Creating 10 random employees
    for (int i = 0; i < 10; i++)
    {
        int choice = (rand() % 3) + 1;

        switch (choice)
        {
        case 1:
            emparr[i] = new RegEmp("Regular", "Employee", (rand() % 1000) + 1, (rand() % 24));
            break;

        case 2:
            emparr[i] = new ConEmp("Contractual", "Employee", (rand() % 1000) + 1, (rand() % 20) + 1, (rand() % 24) + 1);
            break;

        case 3:
            emparr[i] = new DWageEmp("DailyWage", "Employee", (rand() % 20) + 1, (rand() % 24) + 1);
            break;

        default:
            std::cout << "Invalid\n";
        }
    }

    //Add employees from array to random department in the company
    for (int i = 0; i < 10; i++)
    {
        int choice = (rand() % 2) + 1;
        if (typeid(emparr[i]) == typeid(RegEmp))
        {
            company.addEmployee(choice, 1, emparr[i]);
            continue;
        }
        if (typeid(emparr[i]) == typeid(ConEmp))
        {
            company.addEmployee(choice, 2, emparr[i]);
            continue;
        }
        if (typeid(emparr[i]) == typeid(DWageEmp))
        {
            company.addEmployee(choice, 3, emparr[i]);
            continue;
        }
    }

    std::cout << company;

    return 0;
}