// module_9_5.cpp : Напишите программу, которая переводит данное пользователем число в римскую запись. Например, 19 в римской записи — XIX.
//

#include <iostream>
#include <string>
#include <sstream>
#include <map>

std::string convertNumericToRomeNumber(int numeric)
{

}

int main()
{
    int baseData = 0;
    std::map <char, int> Distionary
    {
        { 'I', 1 },
        { 'V', 5 },
        { 'X', 10 },
        { 'L', 50 },
        { 'C', 100 },
        { 'D', 500 },
        { 'M', 1000 }
    };

    baseData = 1294;
    std::cout << convertNumericToRomeNumber(baseData)<<"\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

