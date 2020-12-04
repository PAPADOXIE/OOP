#include "Employee.h"

class DWageEmp : public Employee
{
public:
    DWageEmp(std::string fName, std::string sName, int hourRate, int hours);
    int calcSal();

private:
    int hRate;
    int hours;
};