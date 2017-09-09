#include <iostream>
#include <string>

int a = 15;
const int n = 3;

struct Vedomost
{
    int number;
    std::string name;
    int mark;
};

void input (Vedomost *v)
{
    for (int i = 0; i < n; i++) {
        std::cin >> v[i].number;
        std::cin >> v[i].name;
        std::cin >> v[i].mark;
    }
}

void AllStudent(Vedomost *v)
{
    std::cout << "All student" << std::endl << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Group: " << v[i].number << std::endl;
        std::cout << "Name: " << v[i].name << std::endl;
        std::cout << "Mark: " << v[i].mark << std::endl << std::endl;
    }
}

void GoodStudent(Vedomost *v)
{
    std::cout << "Good Student" << std::endl << std::endl;
    for (int i = 0; i < n; i++)
    {
        if (v[i].mark >= 4)
        {
            std::cout << "Group: " << v[i].number << std::endl;
            std::cout << "Name: " << v[i].name << std::endl;
            std::cout << "Mark: " << v[i].mark << std::endl << std::endl;
        }
    }
}
int main()
{
    int a = 2;
    std::cout << "First commit: ";
    std::cout << "'\"" << std::endl;

    //Второе задание
    std::cout << "Second commit: ";
    std::cout << ::a << std::endl;

    //Третье задание
    std::cout << "Third commit: ";
    Vedomost student[n];

    input(student);

    AllStudent(student);
    GoodStudent(student);
    return 0;
}
