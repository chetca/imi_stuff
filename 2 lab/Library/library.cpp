#include "library.h"

Library::Library() {
    std::cout << "Welcome to the Super-Puper " <<
                 "programm from Library!" << std::endl;

    std::cout << "Please, enter a number: " << std::endl;
    std::cout << "1 from added book " << std::endl;
    std::cout << "2 from remove book " << std::endl;
    std::cout << "3 from print all books by name" << std::endl;
    std::cout << "4 from print all books by year" << std::endl;
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
            print_surname();
            break;
        case 4:
            print_year();
            break;
        default:
            std::cout << "Syntax error. Please try again" << std::endl;
            break;
        }
    }
}

void Library::add() {
    std::cout << "Enter Author, Name of Book, Year and Sum" << std::endl;
    Book tmp;
    std::cin >> tmp.Author;
    std::cin >> tmp.Name;
    std::cin >> tmp.Year;
    std::cin >> tmp.Sum;
    book.push_back(tmp);
}

void Library::remove() {

}

void Library::print_surname() {
    for(auto i = book.begin(); i != book.end(); i++) {
        std::cout << (*i) << std::endl;
    }

}

void Library::print_year() {

}

std::ostream& operator<<(std::ostream& os, const Book& bk)
{
    os << bk.Author << " " << bk.Name << " " << bk.Year << bk.Sum;
    return os;
}

//bool Library::Compare(const std::string &left, const std::string &right) {
//        for (auto i = left, j = right; i < left.length(), j < right.length(); i++, j++){
//            if (left[i] < right[j])
//                return true;
//            if (left[i] > right[j])
//                return false;
//            if ((i + 1 == left.length()) && (j + 1 < right.length()))
//                return true;
//            if ((i + 1 < left.length()) && (j + 1 == right.length()))
//                return false;
//            if ((i + 1 == left.length()) && (j + 1 == right.length()))
//                return true;
//        }
//        return true;
//}
