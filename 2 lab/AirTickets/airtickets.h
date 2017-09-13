#ifndef AIRTICKETS_H
#define AIRTICKETS_H

#include "request.h"
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>

class AirTickets
{
private:
    std::multimap<std::string, Request> request;
public:
    AirTickets();

    void add();
    void remove();
    void output_num();
    void print_place();
    void print_date();
};

#endif // AIRTICKETS_H
