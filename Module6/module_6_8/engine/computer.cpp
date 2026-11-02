#include "computer.h"
#include <random>

// computer.cpp
computer::computer()
{

    m_left = 0;
    m_right = 63;
    m_currentGuess = 0;


    for (int i = 0; i < 64; ++i) {
        m_numbers[i] = i;
    }
}

computer::~computer()
{

}

// Метод для одного шага угадывания
bool computer::is_greater(int current_number, int target)
{
    return current_number > target;
}

// Метод для проверки угадал ли число
bool computer::corect_number(int number, int target)
{
    return number == target;
}

// Один шаг бинарного поиска
int computer::make_guess(int* arr, int target, int left, int right)
{
    int mid = left + (right - left) / 2;

    return mid;
}

unsigned int computer::numericGenerate()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,63); // distribution in range [1, 63]

    return dist6(rng);
}

int computer::answer(int value)
{
    return value;
}

int computer::answer_question(int target, int home_answer)
{
    if (corect_number(home_answer, target))
    {
        return -1; // угадали
    }

    // Выносим логику "больше/меньше" в отдельный вызов
    if (is_greater(home_answer, target))
    {
        return 0; // сигнал: число меньше (ищем в левой половине)
    } else
    {
        return 1; // сигнал: число больше (ищем в правой половине)
    }
}
