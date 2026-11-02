// Напишите программу, которая проверяет, чётное ли число ввел пользователь.
//Решено

#include <iostream>

int main(){
    int num;

    std::cout << "Input your number\n";
    std::cin >> num;

    (num % 2) == 0 ? std::cout << "Number is even" : std::cout << "Number is not even";

}

