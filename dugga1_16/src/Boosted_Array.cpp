#include "Boosted_Array.h"
#include <iostream>

Boosted_Array::Boosted_Array()
{
    //ctor
}

Boosted_Array::~Boosted_Array()
{
    //dtor
    delete[] name;
}

Boosted_Array::Boosted_Array(const Boosted_Array& other)
{
    //copy ctor
    this->nDates = other.nDates;
    //this->date = new Date[this->nDates];
    this->name = new std::string[this->nDates];

    this->date = other.date;

    for(int i = 0; i < this->nDates; i++)
    {
        //this->date[i] = other.date[i];
        this->name[i] = other.name[i];
    }
}

Boosted_Array::Boosted_Array(Date d, int n, std::string newName)
{
    this->date = d;//new Date[n];
    this->name = new std::string[n];
    this->nDates = n;

    //date[0] = d;
    //name[0] = newName;

    for(int i = 0; i < n; i++)
    {
        //date[i] = date[i - 1] + 1;
        name[i] = newName;
    }
}


Boosted_Array& Boosted_Array::operator=(const Boosted_Array& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

    this->nDates = rhs.nDates;
    //this->date = new Date[this->nDates];
    this->name = new std::string[this->nDates];

    this->date = rhs.date;

    for(int i = 0; i < this->nDates; i++)
    {
       // this->date[i] = rhs.date[i];
        this->name[i] = rhs.name[i];
    }

    return *this;
}

Date Boosted_Array::begin() const
{
    return this->date;
}

Date Boosted_Array::end() const
{
    return this->date + this->nDates;//date[nDates - 1];
}

void Boosted_Array::resize_to(Date d)
{
    int newSize = this->begin() - d;

    //Date *newDate = new Date[newSize];
    std::string *newName = new std::string[newSize];

    for(int i = 0; i < newSize; i++)
    {
        //newDate[i] = this->date[i];
        newName[i] = this->name[i];
    }


    delete[] this->name;

    this->name = newName;
}

std::string& Boosted_Array::operator[](const Date d) const
{
    Date tmp = this->date;
    std::string error = "ERROR";

    int found = 0, i;

    for(i = 0; i < this->nDates && !found; i++)
    {
        if(tmp == d)
            found = 1;

        tmp++;
    }

    if(found)
        return this->name[i];
    else
        return error;
}

Boosted_Array Boosted_Array::operator+(const Boosted_Array& ba) const
{
    int newSize;

    std::cout << "5";

    Boosted_Array newBa;
    Date tmp;

    if(this->begin() < ba.begin())
        newBa.date = this->begin();
    else
        newBa.date = ba.begin();

    std::cout << " 4";

    if(this->end() > ba.end()) {
        newBa.nDates = this->end() - newBa.date;

    }
    else {
        std::cout << "-yes";
        newBa.nDates = ba.end() - newBa.date;
    }

    std::cout << " HEJ";

    std::string *newName = new std::string[newBa.nDates];

    tmp = newBa.date;

    /// HAj
    std::string hej = ba[Date(3,6,2016)];

    std::cout << std::endl << hej;
    //Boosted_Array tmpLhs(*this);

    std::cout << std::endl << newBa.nDates;

    for(int i = 0; i < newBa.nDates; i++)
    {
        newName[i] = (*this)[tmp] + " " + ba[tmp];

        std::cout << std::endl << newName[i];

        if(i < newBa.nDates - 1)
            tmp++;
    }


    newBa.name = newName;

    return newBa;
}
