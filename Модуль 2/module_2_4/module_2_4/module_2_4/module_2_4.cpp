/*Задание 4. Непонятная квитанция
Что нужно сделать
Управляющая компания рассылает странные квитанции : в них указана только полная стоимость ремонта многоквартирного дома, а сколько должна платить конкретная квартира — непонятно.Напишите программу, с помощью которой жители квартир смогут посчитать, какую сумму им надо заплатить.Сумма делится на все квартиры вне зависимости от площади, количества жильцов и комнат.Все значения сохраните в переменные и выводите в нужных местах, имитируя ввод данных.

Пример работы программы :
Приветствуем вас в калькуляторе квартплаты!

Введите сумму, указанную в квитанции : 4000000
Сколько подъездов в вашем доме ? 10
Сколько квартир в каждом подъезде ? 40
----Считаем---- -
Каждая квартира должна платить по 10 000 руб.*/
//Solved


#include <iostream>

int main() {
	int paymentSlip = 0;
	double apartmentArea = 0;
	int entrance = 0;
	int apartmentQuantity = 0;

	std::cout << "What is payment slip for hause ";
	std::cin >> paymentSlip;
	std::cout << "How many entrance in your house ";
	std::cin >> entrance;
	std::cout << "How many apartments in each entrance ";
	std::cin >> apartmentQuantity;
	std::cout << "What is area of your apartment ";
	std::cin >> apartmentArea;

	std::cout << "Your check is "<<(paymentSlip/entrance/apartmentQuantity)*(apartmentArea/10);
}
