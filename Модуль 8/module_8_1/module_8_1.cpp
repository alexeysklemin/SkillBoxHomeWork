// module_8_1.cpp : Вы пишете симулятор космических полётов. Ваш звездолёт массой m килограмм включает двигатель с силой тяги F ньютонов на t секунд. 
// Напишите программу, которая по заданным F, m и t покажет, на каком расстоянии от первоначального положения окажется космический корабль через t секунд. 
// Обеспечьте контроль ввода.
//Решено

#include <iostream>
#include <algorithm>
#include <limits>

int main()
{
    int m = 0;
    float F = 0;
    int t = 0;
    float a = 0;

    // Функция для безопасного ввода числового значения
    auto safeInput = [](auto& var, const std::string& prompt) {
        while (true) {
            std::cout << prompt;
            std::cin >> var;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "It's not a numeric data. Please try again.\n";
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }
        };

    // Ввод данных с проверкой
    safeInput(m, "Input mass of your cosmoship: ");
    safeInput(F, "Input force of your cosmoship: ");
    safeInput(t, "What's time you are interesting: ");

    // The algorithm
    a = F / m;

    std::cout << "From " << t << " you will stay on ";
    std::cout << (a * (std::pow(t, 2))) / 2 << "\n";

    return 0;
}