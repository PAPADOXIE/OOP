#include "../include/ProductionWorker.h"
#include <iostream>

ProductionWorker::ProductionWorker(Date hire_date) : Employee(hire_date)
{
}

ProductionWorker::ProductionWorker(Date hire_date, unsigned int shift, float rate) : Employee(hire_date)
{
    if (!(setShift(shift) && setRate(rate)))
    {
        std::cout << "Could not initialize worker" << std::endl;
    }
}

bool ProductionWorker::setShift(unsigned int shift)
{
    if (shift > 0 && shift < 3)
    {
        this->shift = shift;
        return true;
    }
    std::cout << "Invalid Shift" << std::endl;
    return false;
}

bool ProductionWorker::setRate(float rate)
{
    this->rate = rate;
    return true;
}

unsigned int ProductionWorker::getShift() const
{
    return shift;
}

float ProductionWorker::getRate() const
{
    return rate;
}

std::ostream &operator << (std::ostream &out, const ProductionWorker &worker){
    out << static_cast<Employee>(worker);
    out << "Shift: " << worker.shift << std::endl; 
    out << "Rate: " << worker.rate << std::endl;
    return out;
}
