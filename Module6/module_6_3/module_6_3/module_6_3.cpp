// module_6_3.cpp : Задание 3. Коллекторы
//Что нужно сделать
//Напишите робота для коллекторов.В самом начале он спрашивает имя должника и сумму долга, а затем начинает требовать у него погашения долга до тех пор, пока тот не будет погашен полностью.
// Сумма долга должна уменьшаться, если пользователь ввёл сумму, меньшую чем сумма долга.Если пользователь внёс большую сумму, чем требуется для погашения, 
//выведите сообщение о том, какой у него остаток на счету после такой операции. Обеспечьте контроль ввода.
//Рекомендации по выполнению
//При полной выплате долга необходимо учитывать остаток на счету, если он имеется.
//Что оценивается
//• Правильно считается остаток после полного погашения долга.
//• Программа прекращает выполнение после того, как долг полностью погашен.
//• При задании отрицательного долга программа выводит предупреждение и прекращает выполнение.
//Solved

#include <iostream>
#include <string>
#include <exception>
#include <algorithm>





int main()
{

	int dept;
	int payment;
	int deposite = 0;

	std::cout << "Input your dept" << std::endl;
	std::cin >> dept;

	//Check for numeric datas input
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "This is not a number!" << std::endl;
	}
	else
	{
		while (dept >= 0)
		{
			std::cout << "How much you can pay now" << std::endl;
			std::cin >> payment;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				std::cout << "This is not a number!" << std::endl;
			}
			else
			{
				std::cerr << dept<<"\t"<<payment;
				std::cout << std::endl;
				dept = dept-payment;
			}
		}



		std::cout << "Your debt is " << abs(dept);
		return 0;
	}
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"


