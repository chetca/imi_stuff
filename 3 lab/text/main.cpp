#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");
    if (argc > 1) {
        std::string str = argv[1];
        if(str == "/d" || str == "-d") {
            WIN32_FIND_DATA FindFileData;
            HANDLE hf;
            hf=FindFirstFile(".\\*.*", &FindFileData);
            if (hf!=INVALID_HANDLE_VALUE) {
                do {
                    std::cout << FindFileData.cFileName << std::endl;
                }
                while (FindNextFile(hf,&FindFileData)!=0);
                FindClose(hf);
            }
        }
        if(str == "/s" || str == "-s") {
            std::ofstream out("myfile.txt");
            out << argv[0];
            out.close(); //Закрываем файл
           }
        } else {
            std::cout << "Not arguments" << std::endl;
           }
        return 0;
}
