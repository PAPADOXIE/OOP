#include "../include/Date.h"

Date::Date()
{
}

Date::Date(int day, int month, int year)
{
    if (!(setMonth(month) &&
          setDay(day) &&
          setYear(year)))
    {
        std::cout << "Error! Wrong Date Format" << std::endl;
    }
}

bool Date::setDay(int day)
{
    if ((month < 8 && month % 2 != 0) || (month > 8 && month % 2 == 0))
    {
        if (!(day > 0 && day < 32))
        {
            return false;
        }
        this->day = day;
    }
    else if ((month < 8 && month % 2 == 0) || (month > 8 && month % 2 != 0))
    {
        if (!(day > 0) && day < 31)
        {
            return false;
        }
        this->day = day;
    }
    return true;
}

bool Date::setMonth(int month)
{
    if (month > 0 && month < 13)
    {
        this->month = month;
        return true;
    }
    return false;
}

bool Date::setYear(int year)
{
    this->year = year;
    return true;
}

int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

std::ostream &operator<<(std::ostream &out, const Date &date)
{
    out << "Hire Date: ";
    out << date.day << "/";
    out << date.month << "/";
    out << date.year << std::endl;
    return out;
}