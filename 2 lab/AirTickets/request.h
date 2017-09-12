#include "date.h"
#include <string>

struct Request {
    int Number;
    std::string Name;
    Date day;

    friend std::ostream& operator<<(std::ostream& os, const Request& rk);
};

inline std::ostream& operator<< (std::ostream& os, const Request& rk) {
    os << rk.Number << " " << rk.Name << " " << rk.day;
    return os;
}

inline bool operator < (const Request &rq1, const Request &rq2) {
    if (rq1.day < rq2.day) return true;
    if (rq1.day > rq2.day) return false;
    if (rq1.Number < rq2.Number) return true;
    if (rq1.Number > rq2.Number) return false;
    return rq1.Name < rq2.Name;
}
