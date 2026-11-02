/*Задание 2. Майские!
Что нужно сделать
Напишите программу-календарь для мая. Она должна проверять введённый номер дня и сообщать, выходной этот день или рабочий.*/
//Решено

#include <iostream>

int main()
{
    int TestDay = 13;
    bool weekends = false;

    if (((TestDay %6) == 0) || ((TestDay % 7) == 0))
    {
        weekends = true;
    }
    if (((TestDay >= 1) && (TestDay <= 5)) || ((TestDay >= 8) && (TestDay <= 10)))
    {
        weekends=true;
    }
    
    std::cout << weekends << "\n";

}

