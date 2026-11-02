/* Напишите программу, которая ищет минимальное значение из двух чисел.
*/
//Решено

#include <iostream>

int main(){
    int firstNumber;
    int secondNumber;

    
    std::cout << "Input first number\n";
    std::cin >> firstNumber;

    std::cout << "Input second number\n";
    std::cin >> secondNumber;
    
    if (firstNumber == secondNumber) {
        std::cout << "The numbers are equil";
        
    }
    else {
        firstNumber>secondNumber ? std::cout << "First number is more than second one\n\n" : std::cout << "Second number is more than first one\n\n";

        
    }

    


}


