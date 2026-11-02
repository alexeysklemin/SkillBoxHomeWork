/*Задание 2. Калькулятор стоимости товара
Что нужно сделать
Напишите калькулятор для расчёта полной стоимости товара.Она рассчитывается так : стоимость товара + стоимость доставки – скидка.
Все значения сохраните в переменные и выводите в нужных местах, имитируя ввод данных(речь про cout).*/
//Solved

#include <iostream>
#include <string>

int main() {
	int price = 0;
	int delivery = 0;
	int discont = 0;
	std::string food;

	std::cout << "What is food ";
	std::getline(std::cin, food);
	std::cin >> price >> delivery >> discont;

	price = (price + delivery) - discont;

	std::cout << "Total price of " << food << " " << price;
}
