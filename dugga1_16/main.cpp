using namespace std;

#include <iostream>
#include <string>
#include <iomanip>

#include "Date.h"
#include "Boosted_Array.h"

ostream& operator<<(ostream& os, const Date& d);
ostream& operator<<(ostream& os, const Boosted_Array& ba);

int main()
{
    Boosted_Array ba1(Date(1,6,2016), 5, "hej");
    Boosted_Array ba2(Date(3,6,2016), 5, "da");

    Boosted_Array res = ba1 + ba2;

    return 0;
}


ostream& operator<<(ostream& os, const Date& d)
{
    int day, month, year;
    Date date(d);

    date.getDate(day, month, year);

    os << day << " - " << month << " - " << year << endl;

    return os;
}

ostream& operator<<(ostream& os, const Boosted_Array& ba)
{

}
