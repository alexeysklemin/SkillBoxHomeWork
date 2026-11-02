// module_0_1.cpp : Создайте новый проект на языке С++.
//Напишите три варианта программ, которые выводят текст на экран.
// Используйте для создания только символы « = », « | » и пробелы.
// Размер окна может быть любым
//Solved


#include <iostream>

int main()
{
    for (int i = 0; i < 26; ++i) {
        std::cout << "=";
     }
    std::cout << std::endl;
    for (int j = 0; j < 7; ++j) {
        for (int i = 0; i < 26; ++i) {


            if (i == 0 || i == 1) {
                std::cout << "|";
            }
            else {
                if (j == 2 && i == 10) {
                    std::cout << "Hello,";
                }
                if (j == 3 && i == 10) {
                    std::cout << "World";
                }
                else {
                    std::cout << " ";
                }
                

            }
            if (i == 24 || i == 25) {
                std::cout << "|";
            }
            if (i == 25) std::cout << std::endl;

        }
    }
    for (int i = 0; i < 26; ++i) {
        std::cout << "=";
    }

    
}


