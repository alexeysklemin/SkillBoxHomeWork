/* Задание 3. Майские — усложнение
Что нужно сделать
В предыдущем задании вы написали программу - календарь для мая.Теперь добавьте возможность начать месяц с любого дня недели.
Для этого нужно ввести число — номер дня недели, с которого начинается месяц.Убедитесь, что введённое число корректнo*/
//Solved

#include <iostream>
#include <string>

int main()
{
    int testDay = 18;
    int countDay = 5;

    bool weekends=false;

    if (((testDay - countDay) % 6 == 0) || ((testDay - countDay) % 7 == 0))
    {
        weekends = true;
    }

    if ((testDay >= 1 && testDay <= 5) || (testDay >= 8 && testDay <= 10))
    {
        weekends = true;
    }

    std::string result = (weekends) ? "weekends" : "work day";

    std::cout << result<<"\n";

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"