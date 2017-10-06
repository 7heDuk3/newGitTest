#ifndef DATE_H
#define DATE_H

class Date
{
    public:
        Date();
        virtual ~Date();
        Date(const Date& other);
        Date(int day, int month, int year);
        Date& operator=(const Date& other);
        Date& operator++();
        Date operator++(int);
        bool operator<(const Date& d) const;
        bool operator>(const Date& d) const;
        bool operator==(const Date& d) const;
        bool operator!=(const Date& d) const;
        int operator-(const Date& d) const;
        Date operator+(const int& n) const;
        void getDate(int& d, int& m, int& y);

    protected:

    private:
        int day;
        int month;
        int year;
};



#endif // DATE_H
