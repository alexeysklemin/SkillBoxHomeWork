/* Задание 8. Зарплата(дополнительное задание)
Что нужно сделать
В отделе маркетинга работают три сотрудника.Их зарплаты могут быть как разными, так и одинаковыми.Напишите программу, которая вычисляет разницу между самой высокой и самой низкой зарплатами
сотрудников, а также среднее арифметическое зарплат всех сотрудников отдела.

Пример

Введите зарплату первого сотрудника : 45 рублей
Введите зарплату второго сотрудника : 45 рублей
Введите зарплату третьего сотрудника : 45 рублей
---- - Считаем---- -
Самая высокая зарплата в отделе : 45 рублей
Разница между самой высокой и самой низкой зарплатой в отделе : 0 рублей
Средняя зарплата в отделе : 45 рублей
*/

//Solved

#include <iostream>
#include <string>
#include <vector>

struct Emploer
{
    std::string name;
    int sallary;
};

int main()
{
    std::vector <Emploer> salary;
    Emploer temp;                       //Без временной структуры не работает ибо нельзя записывать в вектор через "cin" или "="
    int hi_salary = 0;
    int av_salary = 0;
    int lo_salary = 0;
    int dif_salary = 0;

    for (int a = 0; a<3; a++)
    {
        std::cin >> temp.name;
        std::cin >> temp.sallary;
        salary.push_back(temp);
    }

    for (int j = 0; j < 3; ++j)
    {
        if (hi_salary < salary[j].sallary)
        {
            hi_salary = salary[j].sallary;
       }
    }

    lo_salary = salary[0].sallary;

    for (int k = 0; k < 3; ++k)
    {
        if (lo_salary > salary[k].sallary)
        {
            lo_salary = salary[k].sallary;
        }
    }

    for (int h = 0; h < 3; ++h)
    {
        av_salary = av_salary + salary[h].sallary;
    }

    av_salary = av_salary/3;

    dif_salary = hi_salary - lo_salary;

    std::cout << "Hierst salary is " << hi_salary << "\n";
    std::cout << "Different between hierst and lowest salary is " << dif_salary << "\n";
    std::cout << "Avarage salary is " << av_salary << "\n";

}

/* Запуск программы : CTRL + F5 или меню "Отладка" > "Запуск без отладки"
 Отладка программы: F5 или меню "Отладка" > "Запустить отладку"*/

