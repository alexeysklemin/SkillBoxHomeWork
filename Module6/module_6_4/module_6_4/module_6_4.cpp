// Задание 4. Счастливый билетик
//Что нужно сделать
//В старину, когда даже в столице билеты в общественном транспорте выдавали контролёры, существовало поверье : 
//если на билете сумма первых трёх цифр в номере билета равна сумме трёх последних, то это к удаче.
//Напишите программу, которая получала бы на вход шестизначный номер билета и выводила, счастливый это билет или нет.
//Рекомендации по выполнению
//• Программу необходимо сделать так, чтобы можно было увеличить количество цифр в билете без особых изменений в коде.
//Solved

#include <iostream>
#include <string>
#include <exception>
#include <algorithm>


// Вспомогательная функция: сумма цифр числа
int sumDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;  // берём последнюю цифру
        n /= 10;        // убираем последнюю цифру
    }
    return sum;
}

bool luckyticket(int ticketNumber, int digits = 6)
{
    // Проверка: число должно иметь ровно 'digits' цифр
    int minVal = 1;
    for (int i = 1; i < digits; ++i) minVal *= 10;  // 10^(digits-1)
    int maxVal = minVal * 10 - 1;                    // 10^digits - 1

    if (ticketNumber < minVal || ticketNumber > maxVal)
        return false;

    int halfDigits = digits / 2;

    // Вычисляем делитель для разделения номера на две половины
    // Для 6 цифр: divider = 1000, для 8 цифр: 10000 и т.д.
    int divider = 1;
    for (int i = 0; i < halfDigits; ++i)
        divider *= 10;

    // Разделяем номер: первая и вторая половина
    int firstHalf = ticketNumber / divider;   // старшие цифры
    int secondHalf = ticketNumber % divider;  // младшие цифры

    // Сравниваем суммы цифр половин
    return sumDigits(firstHalf) == sumDigits(secondHalf);
}


int main()
{
	int ticketNumber = 0;
	std::cout << "Input your ticket number ";
	std::cin >> ticketNumber;

	//Check for numeric datas input
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //Определяем число ли внесено

		std::cout << "This is not a number!" << std::endl;
	}
	else
	{
		std::string result = (!(luckyticket(ticketNumber))) ? "false":"true";
		std::cout << result;
	}
    
	
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

