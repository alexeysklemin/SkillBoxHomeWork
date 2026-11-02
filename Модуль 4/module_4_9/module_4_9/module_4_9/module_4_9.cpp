/*Задание 9. Прогрессивный налог (дополнительное задание)
Что нужно сделать
В последнем видео мы писали программу, вычисляющую сумму налога по прогрессивной шкале в зависимости от полученного заработка: 13% — на доход до 10 000, 20% — на доход от 10 000 до 50 000, 
30% — на доход выше 50 000.

Однако во многих странах, использующих такую шкалу, эта сумма вычисляется более сложным способом: налоговая ставка 30% на доход выше 50 000 означает, что 30% уплачивается не со всей суммы, 
а лишь с той её части, которая превосходит 50 000. 
Аналогично: ставка 20% на доход от 10 000 до 50 000 обязывает уплатить 20% лишь с той части суммы, которая превосходит 10 000, но не превосходит 50 000.
Так, например, с дохода 100 000 придётся заплатить такой налог: 30% * (100 000 – 50 000) + 20% * (50 000 – 10 000) + 13% * 10 000 = 15 000 + 8000 + 1300 = 24 300.
С дохода 30 000: 20% * (30 000 – 10 000) + 13% * 10 000 = 4000 + 1300 = 5300.

Напишите программу, которая спрашивает у пользователя его доход и рассчитывает сумму налога для него по вышеописанным правилам.
*/
//Solved

#include <iostream>


enum Boarder
{
    firstBoard = 50000,
    lastBoard = 10000
};


int main()
{
    const int highestPersent = 30;
    const int midddlPersent = 20;
    const int lowestPersent = 13;

    int salary = 0;
    int totalTax = 0;

    std::cout << "Input your salary ";
    std::cin >> salary;


    if (salary > 50000)
    {
        int tmp = 0;
        tmp = salary;

            salary = salary-50000;
            totalTax = salary * highestPersent / 100;
          
            
            salary = salary -10000;
            totalTax = totalTax + salary*midddlPersent / 100;
            
            
            salary = (tmp - firstBoard)- salary;
            totalTax = totalTax+( salary * lowestPersent / 100);
          
            salary = tmp;
    }
    else
    {
        if (salary > 10000)
        {
                    totalTax = ((salary-10000)*midddlPersent/100)+((salary-(salary-10000))*lowestPersent/100);
        }
    }
    if (salary <= 10000)
    {
        totalTax = salary * lowestPersent/100;
    }
    

    
    std::cout << "Total tax is "<<totalTax<< "\n";
}



