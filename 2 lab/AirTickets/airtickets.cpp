#include "airtickets.h"

AirTickets::AirTickets()
{
    std::cout << "Welcome to the " <<
                 "programm from Air Tickets!" << std::endl;

    std::cout << "Please, enter a number: " << std::endl;
    std::cout << "1 from added air ticket order " << std::endl;
    std::cout << "2 from remove order " << std::endl;
    std::cout << "3 from withdrawal of an order by number " << std::endl;
    std::cout << "4 from withdrawal of an order by the date " << std::endl;
    std::cout << "5 from print all orders by destination " << std::endl;
    std::cout << "6 from print all orders by date " << std::endl;
    int tmp;
    while(true) {
        std::cout << ">: ";
        std::cin >> tmp;
        switch (tmp) {
        case 1:
            add();
            break;
        case 2:
            remove();
            break;
        case 3:
            output_num();
            break;
        case 4:
            output_date();
            break;
        case 5:
            print_place();
            break;
        case 6:
            print_date();
            break;
        default:
            std::cout << "Syntax error. Please try again" << std::endl;
            break;
        }
    }

}

void AirTickets::add()
{
    std::cout << "Enter Destination, Flight number and Name" << std::endl;
    std::string Destination;
    Request tmp;
    std::cin >> Destination;
    std::cin >> tmp.Number;
    std::cin >> tmp.Name;
    std::cout << "Enter desired Departure Date: " << std::endl;
    std::cout << "day - ";
    std::cin >> tmp.day.d;
    std::cout << "month - ";
    std::cin >> tmp.day.m;
    std::cout << "year - ";
    std::cin >> tmp.day.y;
    request.insert(std::pair<std::string, Request>(Destination, tmp));
}

void AirTickets::remove()
{

}

void AirTickets::output_num()
{

}

void AirTickets::output_date()
{

}

void AirTickets::print_place()
{
    for(auto it = request.begin(); it != request.end(); it++) {
        std::cout << it->first << " " << it->second << std::endl;
    }

}

void AirTickets::print_date()
{
    std::sort(request.begin(), request.end(), [](const Request&a, const Request&b) {
        return a.day < b.day;
    });
    for(auto it = request.begin(); it != request.end(); it++) {
        std::cout << it->first << " " << it->second << std::endl;
    }
}






