////Напишите программу для бармена, который не умеет считать.
//Посетитель пришёл в бар и попросил кружку пива.
//Напишите программу для бармена, который не умеет считать, чтобы по заданной дате рождения посетителя и текущей дате определить, можно ему продавать алкоголь или нет.
//Программа должна попросить ввести сегодняшнюю дату и дату рождения покупателя, после чего ответить : «можно» или «нельзя».
//Учтите, что в день восемнадцатилетия алкоголь продавать посетителю ещё нельзя, а вот на следующий день после этого — уже можно.
//Solved

#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

int main() {
    std::string input;
    std::cout << "Input your bith date format YYYY-MM-DD: ";
    std::getline(std::cin, input);

    // Разделяем строку на год, месяц и день
    int year, month, day;
    char dash1, dash2; // для разделителей '-'
    std::istringstream iss(input);

    if (iss >> year >> dash1 >> month >> dash2 >> day && dash1 == '-' && dash2 == '-') {
        // Создаем введенную дату
        std::chrono::year_month_day input_date{ std::chrono::year{year}, std::chrono::month{static_cast<unsigned>(month)}, std::chrono::day{static_cast<unsigned>(day)} };

        // Преобразуем введенную дату в time_point
        auto input_sys_days = std::chrono::sys_days(input_date);

        // Получаем сегодняшнюю дату
        auto today = std::chrono::system_clock::now();
        auto today_sys_days = std::chrono::time_point_cast<std::chrono::days>(today);

        // Вычисляем разницу в годах
        auto years_difference = (today_sys_days - input_sys_days).count() / 365; // Примерно, без учета високосных годов

        // Выводим результаты
        std::time_t input_time = std::chrono::system_clock::to_time_t(input_sys_days);
        std::tm local_tm;
        localtime_s(&local_tm, &input_time); // для Windows
        std::cout << "You put date as your birhday: " << std::put_time(&local_tm, "%Y-%m-%d") << std::endl;
        std::cout << "Today is: " << std::put_time(&local_tm, "%Y-%m-%d") << std::endl; // Здесь нужно получить сегодняшнюю дату
        std::cout << "Your age is: " << years_difference << " years old." << std::endl;
        
        if (years_difference < 18) {
            std::cout << "You might not buy th alchogol\n";
        }
        else {
            std::cout << "It's OK\n";
        }
    }
    else {
        std::cerr << "Abnormal format!" << std::endl;
    }

    

    return 0;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"


