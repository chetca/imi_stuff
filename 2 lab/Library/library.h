#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

class Library
{
private:
    std::vector<Book> book;
public:    
    Library();

    void add();
    void remove();
    void print_surname();
    void print_year();
};

#endif // LIBRARY_H
