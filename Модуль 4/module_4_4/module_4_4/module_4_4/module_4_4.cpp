// Напишите программу, которая определяет уровень персонажа в компьютерной игре. 
// Пользователь вводит число «очков опыта», а программа вычисляет уровень. 
// Новый уровень даётся при достижении 1000, 2500 и 5000 «очков опыта». 
// Начальный уровень равен 1.Напишите программу, которая определяет уровень персонажа в компьютерной игре. 
// Пользователь вводит число «очков опыта», а программа вычисляет уровень. 
// Новый уровень даётся при достижении 1000, 2500 и 5000 «очков опыта». 
// Начальный уровень равен 1.
//Решено

#include <iostream>

int main(){
    enum level {
        FIRST,
        SECOND,
        THIRD
    };

    int skillMeager = 0;
    uint32_t skill  = 0;

    std::cout << "Input skill level of the hero\n";
    std::cin >> skillMeager;

    if (skillMeager < 1000) {
        skill=FIRST;
    }else{
        if (skillMeager > 1000 && skillMeager < 2500) {
            skill = SECOND;
        }
        else {
            if (skillMeager > 5000) {
                skill = THIRD;
            }
        }
    }
    std::cout << "The hero has level " << skill;
}


