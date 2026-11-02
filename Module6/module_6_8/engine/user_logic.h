// user_logic.h
#ifndef USER_LOGIC_H
#define USER_LOGIC_H

#include <QString>

class user_logic
{
public:

    virtual ~user_logic() = default;
    // Когда мы вызываем computer->question(),
    //C++ смотрит: «А у компьютера есть свой question?
    //Нет? Тогда беру у родителя (user_logic)».
    QString question()
    {
        return QString("Загаданное число больше %1?").arg(m_currentGuess);
    }
    virtual int getCurrentGuess() const { return m_currentGuess; }
    virtual int answer(int value) = 0;
protected:
    int m_left = 0;
    int m_right = 63;
    int m_currentGuess = 0;
};

#endif // USER_LOGIC_H
