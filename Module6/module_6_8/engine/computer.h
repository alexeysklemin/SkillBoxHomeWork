// computer.h
#ifndef COMPUTER_H
#define COMPUTER_H
#include "user_logic.h"

class computer : public user_logic
{
    int m_numbers[64];
     unsigned int numericGenerate();
     bool is_greater(int current_number, int target);
     bool corect_number(int number, int target);
     int make_guess(int* arr, int target, int left, int right);

public:
    computer();
    virtual ~computer();
    int answer (int value) override;
    int makeGuess();
    int answer_question(int target, int home_answer);  //1-Да, 0-Нет, -1-Угадал
};

#endif // COMPUTER_H
