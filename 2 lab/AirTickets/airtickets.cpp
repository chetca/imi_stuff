#include "airtickets.h"

AirTickets::AirTickets()
{
    Request tmp1, tmp2, tmp3;
    tmp1.Number = 815;
    tmp1.day.d = 11;
    tmp1.day.m = 04;
    tmp1.day.y = 2004;
    tmp1.Name = "Shepard";
    tmp2.Number = 815;
    tmp2.day.d = 15;
    tmp2.day.m = 04;
    tmp2.day.y = 2004;
    tmp2.Name = "Austen";
    tmp3.Number = 411;
    tmp3.day.d = 5;
    tmp3.day.m = 04;
    tmp3.day.y = 2004;
    tmp3.Name = "Ford";
    request = {{"Los Angeles", tmp1},
               {"Las Vegas", tmp2},
               {"Los Santos", tmp3}};

    std::cout << "Welcome to the " <<
                 "programm from Air Tickets!" << std::endl;

    std::cout << "Please, enter a number: " << std::endl;
    std::cout << "1 from added air ticket order " << std::endl;
    std::cout << "2 from remove order " << std::endl;
    std::cout << "3 from withdrawal of an order by number and date " << std::endl;
    std::cout << "4 from print all orders by destination " << std::endl;
    std::cout << "5 from print all orders by date " << std::endl;
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
            print_place();
            break;
        case 5:
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
    std::cout << "Enter the name of the passenger " << std::endl;
    std::string Tmp;
    Date tmp;
    std::cin >> Tmp;
    std::cout << "Enter the departure date:" << std::endl;
    std::cout << "day - ";
    std::cin >> tmp.d;
    std::cout << "month - ";
    std::cin >> tmp.m;
    std::cout << "year - ";
    std::cin >> tmp.y;
    for(auto it = request.begin(); it != request.end(); it++) {
        if(it->second.Name == Tmp && it->second.day == tmp) {
            request.erase(it);
            std::cout << "Done" << std::endl;
        }
    }
}

void AirTickets::output_num()
{
    std::cout << "Enter the flight number " << std::endl;
    int Tmp;
    Date tmp;
    std::cin >> Tmp;
    std::cout << "Enter the departure date:" << std::endl;
    std::cout << "day - ";
    std::cin >> tmp.d;
    std::cout << "month - ";
    std::cin >> tmp.m;
    std::cout << "year - ";
    std::cin >> tmp.y;
    for(auto it = request.begin(); it != request.end(); it++) {
        if(it->second.Number == Tmp && it->second.day == tmp) {
            std::cout << it->first << " " << it->second << std::endl;
        }
    }
}

void AirTickets::print_place()
{
    for(auto it = request.begin(); it != request.end(); it++) {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

void AirTickets::print_date()
{
    std::vector<std::pair<std::string, Request> > vec;
    for(auto it = request.begin(); it != request.end(); it++) {
        std::pair<std::string, Request> tmp;
        tmp.first = it->first;
        tmp.second = it->second;
        vec.push_back(tmp);
    }
    std::sort(vec.begin(), vec.end(), [](const std::pair<std::string, Request> &a, const std::pair<std::string, Request> &b) {
        return a.second.day < b.second.day;
    });
    for(auto it : vec) {
        std::cout << it.first << " " << it.second << std::endl;
    }
}






