//// Задание 2. Слишком большие числа
//Напишите программу, которая считала бы, сколько цифр(знаков) во вводимом числе.
//Пример выполнения
//Введите число : 10
//Цифр в числе : 2
//Solved

#include <iostream>

class Solution
{
public:
    int count(int number)
    {
        int countVar = 0;
        int tempDivision = 0;
        int temDiv = 0;
        while (number > 0)
        {
            number = number / 10;
            countVar++;
          
        }
        return countVar;
    }
};

int main()
{
    int number = 1111;

    Solution solution;

    std::cout << solution.count(number)<<"\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
