// module_9_2.cpp : Вы решили разработать программу-калькулятор, которая складывает числа сколько угодно большой длины. 
// Первая проблема, с которой вы столкнулись, — по данной строке нужно понять, является она корректной записью вещественного числа или нет.
//Решена

#include <iostream>
#include <string>

int main()
{
    std::string number = {};
    std::cout << "Input your number ";
    std::cin >> number;
    number = "1.5";
    bool check = false;

   
    for (int i=0; i < number.length(); i++)
    {
        if (number[i] > 48 && number[i] < 57)
        {
            check = true;
        }
    }
    
    check = false;

    if ((number.find("+") == std::string::npos) && (number.find("e") == std::string::npos))
    {
        check = true;
    }

    

    size_t first = number.find('.');

    check = false;

    if (number.find(".", first+1) == std::string::npos)
    {
          check = true;

    }

    std::string result = (check==true) ? "Yes" : "No";
    std::cout << result;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

