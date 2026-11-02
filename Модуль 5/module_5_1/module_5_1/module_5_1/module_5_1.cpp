/* Полёт нормальный!
Что нужно сделать
Напишите программу для аэропорта, проверяющую, правильным ли эшелоном летит самолёт. \
скорость самолёта должна быть в диапазоне от 750 до 850 км/ч;
высота — в диапазоне от 9 000 до 9 500 метров.
*/
//Solved

#include <iostream>
#include <vector>
#include <string>

class Airplane
{
    std::string airplaneName;
    int elevation = 0;
    int speed = 0;
public:
    void setParametrs(std::string aiplane, int elevation_value, int speed_value)
    {
        if (elevation_value > 0)
        {
            elevation = elevation_value;
        }
        if (speed_value > 0)
        {
            speed = speed_value;
        }
        if (speed_value == 0 || elevation_value == 0)
        {
            std::cout << "airplan is staing on aerodrom\n";
        }
        if (speed_value < 0 || elevation_value < 0)
        {
            std::cout << "That's nonsence\n";
        }
        airplaneName = aiplane;             //Важно что бы мы все параметры передавали в класс через сеттер!!!
    }
    int getElevation() const
    {
        return elevation;
    }
    int getSpeed() const
    {
        return speed;
    }

    std::string getAirplaneName() const
    {
        return airplaneName;
    }
};

int main()
{
    int defaultElevation[] = {9000, 9500};
    int defaultSpeed[] = {750, 850};

    std::vector<Airplane>flyTable;
    
    std::string name;
    int elevation=0;
    int speed = 0;

    Airplane airplane;

    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Input name of airplane ";
        std::cin >> name;
        std::cout << "Input elevation of airplane ";
        std::cin >> elevation;
        std::cout << "Input speed of airplane ";
        std::cin >> speed;

        // Пример добавления самолета и установки параметров
        
        airplane.setParametrs(name, elevation, speed);
        flyTable.push_back(airplane);
    }

    
    for (auto &plane : flyTable)
    {
        if ((plane.getElevation() > defaultElevation[0] && plane.getElevation() < defaultElevation[1]) && (plane.getSpeed() > defaultSpeed[0] && plane.getSpeed() < defaultSpeed[1]))
        {
            std::cout<< plane.getAirplaneName()<<" has normal parametrs\n";
        }
        else
        {
            if(plane.getElevation() > defaultElevation[1] && (plane.getSpeed() > defaultSpeed[0] && plane.getSpeed() < defaultSpeed[1]))
            {
                std::cout << plane.getAirplaneName() << " has too high elevation\n";
            }
            if (((plane.getElevation() > defaultElevation[0] && plane.getElevation() < defaultElevation[1]) && (plane.getSpeed() > defaultSpeed[1])))
            {
                std::cout << plane.getAirplaneName() << " is too low\n";
            }
            if ((plane.getElevation() < defaultElevation[0]) && (plane.getSpeed() < defaultSpeed[0]))
            {
                std::cout << plane.getAirplaneName() << " BOWNG!!!\n";
            }
        }
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
