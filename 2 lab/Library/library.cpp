#include "library.h"

Library::Library() {
    book = {{"Pushkin", "Kapitanskaya dochka", 2004, 16},
            {"Lermontov", "Demon", 2010, 20},
            {"Tolstoy", "Voyna i mir", 2008, 18},
            {"Dostoevsky", "Idiot", 2016, 4}};

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
    std::cout << "Enter the name of the book to be deleted" << std::endl;
    std::string tmp;
    std::cin >> tmp;
    for(auto i = book.begin(); i != book.end(); i++) {
        if(i->Name == tmp) {
            book.erase(i);
            std::cout << "Done" << std::endl;
        }
    }

}

void Library::print_surname() {
    std::sort(book.begin(), book.end(), [](const Book&a, const Book&b) {
        if (a.Author == b.Author) {
            return a.Name < b.Name;
        }
        return a.Author < b.Author;
    });
    for(auto i : book) {
        std::cout << i << std::endl;
    }
}

void Library::print_year() {
    std::sort(book.begin(), book.end(), [](const Book&a, const Book&b) {
        return a.Year < b.Year;
    });
    for(auto i : book) {
        std::cout << i << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Book& bk)
{
    os << bk.Author << " " << bk.Name << " " << bk.Year << " " << bk.Sum;
    return os;
}

