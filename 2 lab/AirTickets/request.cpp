#include "date.cpp"
#include <string>

struct Request {
    int Number;
    std::string Name;
    Date day;

    friend std::ostream& operator<<(std::ostream& os, const Request& rk);
};

std::ostream& operator<< (std::ostream& os, const Request& rk) {
    os << rk.Number << " " << rk.Name << " " << rk.day;
    return os;
}
