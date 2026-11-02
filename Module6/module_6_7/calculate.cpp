//calculate.cpp
#include <QString>
#include "calculate.h"
#include <qmath.h> // для qAbs в старых Qt, или <cmath> + std::abs

calculate::calculate()
{

}



int calculate::gcd(int a, int b)
{
    a = qAbs(a);  // работаем с модулями
    b = qAbs(b);

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

std::optional<QString> calculate::calculates(int N, int M)
{
    // Обработка краевых случаев
    if (M == 0) {

        return std::nullopt; //"Ошибка: деление на ноль";
    }
    if (N == 0) {
        return "0";
    }
    if(M<0)
    {
        N=N*-1;
        M=qAbs(M);
    }


    int N_result=0;
    int M_result={};
    int divisor = gcd(N, M);

    N_result = N / divisor;
    M_result = M / divisor;



    QString result = QString::number(N_result)+'/'+QString::number(M_result);

    return result;
}
