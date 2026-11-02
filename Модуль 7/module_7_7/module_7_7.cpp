// module_7_7.cpp : В чашку Петри исследователи кладут N бактерий и добавляют X капель антибиотика. 
// Известно, что число коринебактерий в чашке Петри увеличивается в два раза каждый час, а каждая капля антибиотика в первый час убивает 10 бактерий, во второй час — 9 бактерий, 
// в следующий — 8 и так далее, пока антибиотик не перестанет действовать. 
// Заметьте, что сначала число коринебактерий увеличивается, а затем действует антибиотик. 
// Пользователь вашей программы вводит N и X, а программа печатает на экране, сколько бактерий останется в чашке Петри в конце каждого часа, 
// до тех пор, пока не закончатся бактерии или антибиотик не перестанет действовать.
//Solved

#include <iostream>
#include <algorithm>

int main()
{
    int quantityBacteria = 12;
    int quatityAntibiotic = 1;
    int powerAntibiotic = 10;
    int hourCounter = 0;

    std::cout << "Input quantity of antibiotic and bacteries ";

    std::cin >> quantityBacteria >> quatityAntibiotic;

    while (std::cin.fail())
    {

        //Check nymeric datas input
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "This is not a number!" << std::endl;
        }
        std::cout << "Input quantity of antibiotic and bacteries ";

        std::cin >> quantityBacteria >> quatityAntibiotic;

    }

    //The algorithm
    while (powerAntibiotic != 0 || quantityBacteria != 0)
    {
        quantityBacteria = quantityBacteria * 2;

        quantityBacteria -=((powerAntibiotic-hourCounter)*quatityAntibiotic);
       
        std::cout << "Quantity bacteries\t" << quantityBacteria << "\n";
        hourCounter++;
        //powerAntibiotic -= hourCounter;
        if ((powerAntibiotic -hourCounter)< 0) break;
    }
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"


