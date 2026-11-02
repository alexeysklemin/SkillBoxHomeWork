//calculate.h
#ifndef CALCULATE_H
#define CALCULATE_H

#include<QString>

class calculate
{
public:
    calculate();
    int gcd(int a, int b);
    std::optional<QString> calculates(int N, int M);
};

#endif // CALCULATE_H
