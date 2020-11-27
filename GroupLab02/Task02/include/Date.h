#pragma once

#include <iostream>

class Date
{
public:
    Date(); //Constructor
    Date(int day, int month, int year);
    //Setters
    bool setDay(int day);
    bool setMonth(int month);
    bool setYear(int year);
    //Getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    //Friends
    friend std::ostream &operator<<(std::ostream &out, const Date &date);

private:
    int day, month, year;
};