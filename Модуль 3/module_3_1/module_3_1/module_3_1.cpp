/* Задача 1. Симулятор маршрутки
Что нужно сделать
Напишите программу, которая симулирует работу маршрутки.Она умеет объявлять остановки и узнавать у пользователя, сколько человек вышло и зашло на остановке.Пассажиры оплачивают проезд при входе.Работать она должна примерно так :
Прибываем на остановку «Улица программистов».В салоне пассажиров : 0
Сколько пассажиров вышло на остановке ? 0
Сколько пассажиров зашло на остановке ? 3
Отправляемся с остановки «Улица программистов».В салоне пассажиров : 3
---------- - Едем-------- -
Прибываем на остановку «Проспект алгоритмов».В салоне пассажиров : 3
…
…

Маршрут состоит из четырёх остановок.Напишите программу так, чтобы в конце она выводила, сколько денег мы заработали при условии, что билет стоит 20 руб., а расходы следующие :
•	четверть — на зарплату водителю;
•	пятая часть — на топливо;
•	пятая часть — на налоги;
•	пятая часть — на ремонт машины.
Формат вывода(после прибытия на последнюю остановку) :
	Всего заработали : 100 руб.
	Зарплата водителя : 25 руб.
	Расходы на топливо : 20 руб.
	Налоги : 20 руб.
	Расходы на ремонт машины : 20 руб.
	Итого доход : 15 руб.*/
//Solved

#include <iostream>
#include <string>

int main() {
	int leavPassangers = 0;
	int comPassangers = 0;
	int insPassangers = 0;
	int ticket = 0;
	double salaryDriver = 0;
	double fuel = 0;
	double repaire = 0;
	double tax = 0;

	std::string busStopArray[] = { "programmer street", "algorithm avenue", "computer lane", "deadline deadend", "commandline passage"};

	for (int i = 0; i < 5; ++i) {
		std::cout << "The busstop is " << busStopArray[i] << std::endl;

		std::cout << "How many passagers are leaving the bus ";
		std::cin >> leavPassangers;
		if (leavPassangers > insPassangers) {
			insPassangers = 0;
		}
		else {
			insPassangers = insPassangers - leavPassangers;
		}

		std::cout << "How many passangers are coming the bus ";
		std::cin >> comPassangers;
		insPassangers = insPassangers + comPassangers;
		ticket = ticket + (comPassangers * 20);
		
	}

	std::cout << "Total profit is " << ticket << std::endl;
	std::cout << std::endl;
	
	salaryDriver = (double)ticket/4;
	std::cout << "The salary of the driver is " << salaryDriver << std::endl;
	std::cout << std::endl;

	fuel= (double)ticket /5;
	std::cout << "The cost of fuel is " << fuel << std::endl;
	std::cout << std::endl;

	tax= (double)ticket /5;
	std::cout << "The tax is " << tax << std::endl;
	std::cout << std::endl;

	repaire= (double)ticket /5;
	std::cout << "The repair costs is " << repaire << std::endl;
	std::cout << std::endl;
	std::cout<<std::endl;

	ticket = ticket - salaryDriver - fuel - tax - repaire;

	std::cout << "Final profit is " << ticket << std::endl;


}