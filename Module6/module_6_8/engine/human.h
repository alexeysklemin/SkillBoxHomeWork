// human.h
#ifndef HUMAN_H
#define HUMAN_H
#include <QString>
#include "user_logic.h"

class human: public user_logic
{
public:
    human();
    virtual ~human();
    QString question();
    int answer(int assumption);
};

#endif // HUMAN_H
