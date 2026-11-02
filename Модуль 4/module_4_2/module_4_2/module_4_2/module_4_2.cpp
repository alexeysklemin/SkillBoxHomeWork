// Напишите программу которая проверяет то, как вы умеете складывать два числа в уме. 
// Программа должна выводить два разных сообщения на верный и неверный ответ пользователя. 
//В последнем случае надо показывать правильный результат.
//Решено

#include <iostream>

int main()
{
    std::cout << "Input first number\n";
    int first;
    int second;
    int sum = 0;
    int idea;
    std::cin >> first;

    std::cout << "Input first number\n";
    std::cin >> second;

    sum = first + second;
    std::cout << "Input your idea ";
    std::cin >> idea;
    idea == sum ? std::cout << "You are correct" : std::cout << "You are wrong";
}
