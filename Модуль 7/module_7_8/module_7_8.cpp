// module_7_8.cpp : Напишите программу, которая выводит на экран равнобедренный треугольник, заполненный символами решётки «#». 
// Пусть высота треугольника вводится пользователем. 
// Обеспечьте контроль ввода.
// Есть решение. Нет понимаания.

#include <iostream>

int main()
{
    const char symbol = '#';
    


    // Объявляем переменные:
    int num_triangles = 5;  // Высота треугольника (количество строк)
    int num_lines;      // Количество строк в текущем треугольнике (дублирует num_triangles)
    int num_points;     // Количество символов в текущей строке
    int width;          // Ширина отступа для текущей строки
    int offset;         // Вспомогательная переменная для отступов (не используется в выводе)
    std::cout << "Enter high of Chrismas-tree: " << std::endl;
    std::cin >> num_triangles;

    //Check numeric datas
    while (std::cin.fail())
    {
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());

            std::cout << "Input height of el";
            std::cin >> num_triangles;
        }
    }

    //The algorithm
    width = num_lines = num_triangles;  // Начальные значения для ширины и количества строк

    // Основной цикл построения треугольника
    // line - номер текущей строки (от 1 до num_lines)
    // width уменьшается на 1 после каждой итерации
    for (int line = 1; line <= num_lines; line++, width--) {
        // Рассчитываем количество символов в строке:
        // Для 1-й строки: (1*2)-1 = 1 символ
        // Для 2-й строки: (2*2)-1 = 3 символа и т.д.
        num_points = (line * 2) - 1;

        // Отступ перед символами = текущая ширина
        offset = width;

        // Установка отступа (пробелы перед символами)
        std::cout.width(offset);

        // Вывод символов в текущей строке
        for (int point = 0; point < num_points; point++) {
            std::cout << symbol;
        }

        // Этот расчет offset не влияет на вывод,
        // так как после него сразу идет перевод строки
        offset = (num_lines - line + 1) * 2;

        // Переход на новую строку после вывода всех символов
        std::cout << std::endl;
    }

    system("pause");  // Пауза для просмотра результата (для Windows)
    return 0;         // Завершение программы
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

