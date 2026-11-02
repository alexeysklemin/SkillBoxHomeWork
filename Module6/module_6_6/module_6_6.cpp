// Задание 6. Вклады
//Что нужно сделать:
//Вклад в банке составляет X рублей.Ежегодно он увеличивается на P процентов, после чего дробная часть копеек отбрасывается.
// Определите, через сколько лет вклад составит не менее Y рублей.Напишите программу, которая по данным числам X, Y, P определяет, сколько лет пройдёт, прежде чем сумма достигнет значения Y.
//Рекомендации по выполнению
//• Расчёты проводятся в целых числах.
//• У вклада есть капитализация процентов(проценты начисляются на весь остаток на счёте).
//Что оценивается: Программа аварийно не завершается и не зависает при подсчёте вклада.
//Solved

#include <iostream>
#include <exception>


int main()
{
    int X = 0; //deposit
    int P = 0; //percent of deposit
    int Y = 0; //result of deposit. the goal
    int years = 0; //period of deposit

    std::cout << "Input sum of deposit\t";
    std::cin >> X;
    //Check for numeric datas input
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "This is not a number!" << std::endl;
    }
    else {
        std::cout << "Input percent witch bank gives you\t";
        std::cin >> P;
        //Check for numeric datas input
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "This is not a number!" << std::endl;
        }
        else {
            std::cout << "Input your goal in result summ\t";
            std::cin >> Y;
        }
    }
    while (X < Y) {
        X = X + (X / 100) * P;
    }
    std::cout << "You waited " << Y << " You'll get " << X;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

