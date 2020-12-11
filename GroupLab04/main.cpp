#include <time.h>
#include <random>
#include <iostream>
#include "include/ConEmp.h"
#include "include/RegEmp.h"
#include "include/DWageEmp.h"
#include "include/Employee.h"

int main(void)
{
    srand(time(0));

    Employee *emparr[10];

    for (int i = 0; i < 10; i++)
    {
        int choice = (rand() % 3) + 1;

        switch (choice)
        {
        case 1:
            emparr[i] = new RegEmp("Regular", "Employee", (rand()%1000)+1, (rand()%24));
            break;

        case 2:
            emparr[i] = new ConEmp("Contractual", "Employee", (rand()%1000)+1, (rand()%20)+1, (rand()%24)+1);
            break;

        case 3:
            emparr[i] = new DWageEmp("DailyWage", "Employee", (rand()%20)+1, (rand()%24)+1);
            break;
        
        default:
            std::cout << "Invalid\n";
        }
    }

    for (int i = 0; i < 10; i++){
        std::cout << emparr[i];
    }

    return 0;
}