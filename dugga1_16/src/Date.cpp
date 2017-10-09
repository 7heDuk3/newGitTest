#include "Date.h"
#include <iostream>

Date::Date()
{
    //ctor
    day = 1;
    month = 1;
    year = 2000;
}

Date::~Date()
{
    //dtor
}

Date::Date(const Date& other)
{
    //copy ctor
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
}

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

Date& Date::operator=(const Date& other)
{
    //copy assignment
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;

    return *this;
}

Date& Date::operator++()
{
    this->day++;

    if((this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7
       || this->month == 8 || this->month == 10 || this->month == 12) && this->day > 31)
    {
        this->day = 1;
        this->month++;

        if(this->month > 12)
        {
            this->year++;
            this->month = 1;
        }
    }
    else if(this->month == 2 && this->day > 28)
    {
        this->day = 1;
        this->month++;
    }
    else if(this->day > 30)
    {
        this->day = 1;
        this->month++;
    }

    return *this;
}

Date Date::operator++(int)
{
    this->day++;

    if((this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7
       || this->month == 8 || this->month == 10 || this->month == 12) && this->day > 31)
    {
        this->day = 1;
        this->month++;

        if(this->month > 12)
        {
            this->year++;
            this->month = 1;
        }
    }
    else if(this->month == 2 && this->day > 28)
    {
        this->day = 1;
        this->month++;
    }
    else if(this->day > 30)
    {
        this->day = 1;
        this->month++;
    }

    return *this;
}

bool Date::operator<(const Date& d) const
{
    std::cout << std::endl << this->year;
    std::cout << std::endl << d.year;

    if((this->year + (this->month * 30) + this->day) < (d.year + (d.month * 30) + d.day))
        return true;

    return false;
}

bool Date::operator>(const Date& d) const
{
    if((this->year + (this->month * 30) + this->day) > (d.year + (d.month * 30) + d.day))
        return true;

    return false;
}

bool Date::operator==(const Date& d) const
{
    if(this->year == d.year && this->month == d.month && this->day == d.day)
        return true;

    return false;
}

bool Date::operator!=(const Date& d) const
{
    if(*this == d)
        return false;

    return true;
}

int Date::operator-(const Date& d) const
{
    Date tmp1(*this);
    Date tmp2(d);
    int counter = 0;

    std::cout << "op- 1" << std::endl;

    if(tmp1 < tmp2)
    {
        std::cout << "op- 2" << std::endl;
        while(tmp1 != tmp2)
        {
            counter++;

            tmp1++;
        }

        std::cout << "op- 3" << std::endl;
        //counter *= -1;
    }
    else
    {
        std::cout << "op- 4" << std::endl;
        while(tmp1 != tmp2)
        {
            counter++;

            tmp2++;
        }
    }

    return counter;
}

Date Date::operator+(const int& n) const
{
    if(n < 0)
        return *this;

    Date tmp(*this);

    for(int i = 0; i < n; i++)
        tmp++;

    return tmp;
}

void Date::getDate(int& d, int& m, int& y)
{
    d = this->day;
    m = this->month;
    y = this->year;
}


