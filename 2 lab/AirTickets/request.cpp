#include "date.cpp"
#include <string>

struct Request {
    int Number;
    std::string Name;
    Date day;

    friend std::ostream& operator<<(std::ostream& os, const Request& rk);
};

struct RequestDes{
    std::string Destination;
    int Number;
    std::string Name;

    friend std::ostream& operator<<(std::ostream& os, const RequestDes& rk);
};

std::ostream& operator<< (std::ostream& os, const Request& rk) {
    os << rk.Number << " " << rk.Name << " " << rk.day;
    return os;
}

std::ostream& operator<< (std::ostream& os, const RequestDes& rk) {
    os << rk.Destination << " " << rk.Number << " " << rk.Name;
    return os;
}
