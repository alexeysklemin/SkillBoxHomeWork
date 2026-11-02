//Задание 4. Банкомат — 2
//Что нужно сделать
//Напишите программу для банкомата.
//Условие:
//Однажды Вася подошёл к банкомату и захотел обналичить N рублей.
//В банкомате есть купюры достоинством 100, 200, 500, 1 000, 2 000 и 5 000 рублей.Банкомат хочет выдать Васе запрошенную сумму, обойдясь как можно меньшим числом купюр.
//Напишите программу для банкомата, которая по заданному числу N :
//решает, сколько купюр каждого номинала нужно выдать(4 по 200, 1 по 1 000) для получения суммы ровно N рублей;
//либо говорит, что выдать ровно N рублей невозможно, например если N не делится на 100.
//Учтите, что банкомат не может выдать за один раз более 150 000 рублей.
//При попытке запросить такую сумму должно быть выдано сообщение об ошибке.Например, 800 рублей нужно выдать как 1 по 500, 1 по 200 и ещё 1 по 100.
//Solved

#include <iostream>

enum
{
    banknote100 = 100,
    banknote200 = 200,
    banknote500 = 500,
    banknote1000=1000,
    banknote2000=2000,
    banknote5000=5000
};

struct CashDispenser
{
    int reqSumm = 0;
    int banknote[6] = { banknote5000, banknote2000, banknote1000, banknote500, banknote200, banknote100 };
     int count = 0;

    void countBanknotes(int reqSumm)
    {
        if (reqSumm > 150000 || ((reqSumm % 100) != 0))
        {
            std::cout << "Your summ is abnormal \n";
        }else
        {
            for (int i = 0; i < 6; ++i)
            {
                count = 0;

                count = reqSumm / banknote[i];

                if (count != 0)
                {
                    std::cout << "You will get " << banknote[i] << " " << count << " items\n";
                }

                reqSumm = reqSumm - (count * banknote[i]);
            }
        }
    }
};

int main()
{
    int N = 0;
    std::cin >> N;
    
    CashDispenser cashDispenser;

    cashDispenser.countBanknotes(N);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"


