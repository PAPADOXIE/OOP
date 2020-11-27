#pragma once

#include "Employee.h"
#include <iostream>

class ProductionWorker : public Employee
{
public:
    ProductionWorker(Date hire_date); //Constructor
    ProductionWorker(Date hire_date, unsigned int shift, float rate); //Parameterized Constructor
    //Setters
    bool setShift(unsigned int shift);
    bool setRate(float rate);
    //Getters
    unsigned int getShift() const;
    float getRate() const;
    //Friends
    friend std::ostream &operator << (std::ostream &out, const ProductionWorker &worker);

private:
    unsigned int shift;
    float rate;
};