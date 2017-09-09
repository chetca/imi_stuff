#include <string>

struct Book {
    std::string Author;
    std::string Name;
    int Year;
    int Sum;

    friend std::ostream& operator<<(std::ostream& os, const Book& bk);
};
