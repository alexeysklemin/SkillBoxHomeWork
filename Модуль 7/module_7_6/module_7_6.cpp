// module_7_6.cpp : Восклицательные знаки всегда располагаются по центру строки, причём в зависимости от важности объявления количество восклицательных знаков может быть разным. 
// Напишите программу, которая спрашивает у пользователя сначала общую длину колонтитула в символах, потом желаемое количество восклицательных знаков, после чего выводит на экран готовую строку. 
// Обеспечьте контроль ввода.
//Solved~

#include <iostream>

int main()
{
    int lineSize = 0;
    int exclamationSign = 0;
    
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "This is not a number!" << std::endl;
    }
    else {
        std::cout << "Input full size of line\t";
        std::cin >> lineSize;
        //Check for numeric datas input
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "This is not a number!" << std::endl;
        }
        else {
            std::cout << "Input quantity of exclamation singns\t";
            std::cin >> exclamationSign;
        }
    }

    if (lineSize < 0)
    {
        std::cout << "The length of line can't be a negative. Input correct size of line\t";
        std::cin >> lineSize;
    }

    if (lineSize < exclamationSign)
    {
        std::cout << "Quantity of exclamation signs can't be less than length of string. Input correct quantity of exclamation singns\t";
        std::cin >> exclamationSign;
    }

    int i = 0;
    int j = 0;
    int tildaSign = 0;

    tildaSign = (lineSize - exclamationSign) / 2;

    while (j < tildaSign)
    {
        std::cout << "~";
        j++;
    }

    while (i < exclamationSign)
    {
        std::cout << "!";
        i++;
    }
    int k = (lineSize-(lineSize-(j + i)));
    
    while (k<lineSize)
    {
        k++;
        std::cout << "~";
        
    }

}


