#ifndef BOOSTED_ARRAY_H
#define BOOSTED_ARRAY_H

#include "Date.h"
#include <string>

class Boosted_Array
{
    public:
        Boosted_Array();
        Boosted_Array(Date d, int n, std::string name);
        virtual ~Boosted_Array();
        Boosted_Array(const Boosted_Array& other);
        Boosted_Array& operator=(const Boosted_Array& rhs);
        Date begin() const;
        Date end() const;
        void resize_to(Date d);
        std::string& operator[](const Date d) const;
        Boosted_Array operator+(const Boosted_Array& ba);

    protected:

    private:
        Date date;
        std::string *name;
        int nDates;
};

#endif // BOOSTED_ARRAY_H
