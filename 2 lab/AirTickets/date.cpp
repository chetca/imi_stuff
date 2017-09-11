#include <iostream>

struct Date {
    int d;
    int m;
    int y;

    friend std::ostream& operator<< (std::ostream& os, const Date& bk);
    friend std::istream& operator>> (std::istream& is, Date& bk);
};

std::ostream& operator << (std::ostream& os, const Date& dt) {
    os << " " << dt.d << "." << dt.m << "." << dt.y << " ";
    return os;
}

std::istream& operator>> (std::istream& is, Date& dt )
{
   is >> dt.d >> dt.m >> dt.y;
   return is;
}

bool operator == (const Date &dt1, const Date &dt2)
{
    return dt1.d == dt2.d && dt1.m == dt2.m && dt1.y == dt2.y;
}

bool operator < (const Date &dt1, const Date &dt2)
{
    if (dt1.y < dt2.y) return true;
    if (dt1.y > dt2.y) return false;
    if (dt1.m < dt2.m) return true;
    if (dt1.m > dt2.m) return false;
    return dt1.d < dt2.d;
}





