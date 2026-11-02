/*Задание 5. Кратность числа
Что нужно сделать
Напишите программу, которая проверяет, делится ли одно число на другое без остатка.*/
//Решено


#include <iostream>

using namespace std;

int main()
{
    int firstVar, secondVar;
    std::cin>>firstVar>>secondVar;
    cout << ((firstVar%secondVar==0) ? "Yes":"No") << endl;
    return 0;
}
