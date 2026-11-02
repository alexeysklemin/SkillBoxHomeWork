/*Задание 6. Улучшим барберов
Что нужно сделать
Помните задачу про барберов из видео 4.3? Кстати, именно оператор % мог помочь нам с барберами.
Перепишите программу про них с его использованием для проверки на проблему с целочисленным делением.
Напишите программу, которая отвечает на вопрос хватает ли барберов в данном
городе если задано число людей и число барберов, а так же указано, что
один барбер работает 8 часов в день, на одного клиента тратит 1 час
а каждый клиент приходит раз в месяц.*/
//Решено

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int burbers=0;
    int citizens=0;
    std::cout<<"Input quantity of burbers ";
    std::cin>>burbers;
    std::cout<<"How much people live in your city ";
    std::cin>>citizens;
    int result=(burbers*(8*30));
    std::string Result= (result%citizens==0) ? "Enough" : "Not enough";
    cout << Result << endl;
    return 0;
}
