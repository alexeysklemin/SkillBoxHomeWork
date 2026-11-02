// module_8_6.cpp : Известно, что амплитуда качающегося маятника с каждым разом затухает на 8,4% от амплитуды прошлого колебания. 
// Если качнуть маятник, он, строго говоря, никогда не остановится: его амплитуда будет уменьшаться до тех пор, пока мы не сочтём такой маятник остановившимся. 
// Напишите программу, определяющую, сколько раз качнётся маятник, прежде чем он, по нашему мнению, остановится. 
// Программа получает на вход начальную амплитуду колебания в сантиметрах и конечную амплитуду его колебаний, которая считается остановкой маятника. 
// Обеспечьте контроль ввода
//Решено
//Важно! десятичная точка а не запятая

#include <iostream>

int main()
{
    float amplitude = 0;
    float stopPoint = 0;
    int counter = 0;

    std::cout << "Input begining amplitude ";
    std::cin >> amplitude;
    std::cout << "Input your stop point ";
    std::cin >> stopPoint;

    //Check numeric datas
    while (std::cin.fail())
    {
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());

            std::cout << "Input begining amplitude ";
            std::cin >> amplitude;
            std::cout << "Input your stop point ";
            std::cin >> stopPoint;
        }
    }
    amplitude = 100.1;
    stopPoint = 1.7;

    while (amplitude > stopPoint)
    {
        amplitude = amplitude - (amplitude / 8.4);
        counter++;
        std::cerr << counter << "\t" << amplitude << "\n";
    }
    std::cout << counter;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

