/*Задание 3. Время, время!
Что нужно сделать
Напишите программу для ресторана быстрого питания «Крылышки и ножки».Компания хочет знать, какое количество клиентов успеет обслужить один кассир за рабочую смену.Время на обслуживание складывается из времени, за которое клиент делает заказ, и времени, за которое кассир собирает заказ и выдаёт его клиенту.Все расчёты проводите в минутах.Все значения сохраните в переменные и выводите в нужных местах, имитируя ввод данных.

Пример работы программы :
Эта программа рассчитает, сколько клиентов успеет обслужить кассир за смену.
Введите длительность смены в минутах : 480
Сколько минут клиент делает заказ ? 2
Сколько минут кассир собирает заказ ? 4
---- - Считаем---- -
За смену длиной 480 минут кассир успеет обслужить 80 клиентов.*/
//Solved


#include <iostream>

int main() {
	int change = 0;
	int clientTime = 0;
	int cashierTime = 0;
	int orderTimeTotal = 0;
	int clientsPerChange = 0;


	std::cout << "Input shift legth of cashier ";
	std::cin >> change;
	std::cout << "How much minutes client spends per order ";
	std::cin >> clientTime;
	std::cout << "How much minutes cashier spends per order ";
	std::cin >> cashierTime;
	clientsPerChange = change / (clientTime + cashierTime);
	std::cout << "through 1 change " << change << " long minutes cashier can serve " << clientsPerChange << " clients";
}
