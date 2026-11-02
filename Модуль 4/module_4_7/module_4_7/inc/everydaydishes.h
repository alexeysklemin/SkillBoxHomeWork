#ifndef EVERYDAYDISHES_H
#define EVERYDAYDISHES_H
#include <string>
#include "common.h"

class everydayDishes
{
    int weekDayNumber=0;
    std::string dishes[7][4] = {"Харчо", "Салат «Оливье»", "Баварские колбаски с капустой", "Морс",
                                "Гороховый суп", "Салат «Цезарь» с креветками ", "Куриная ножка с пюре", "Морс",
                                "Суп", "Салат «Цезарь» с мидиями ", "Баварские колбаски с картошкой", "Морс",
                                "Борщ", "Овощной салат", "Жаркое с картошкой", "Морс",
                                "Солянка", "Салат", "Вермишель с куриным мясом","Морс",
                                "Суп", "Фруктовый салат", "Макароны по флотски","Морс",
                                "Окрошка", "Фруктовый салат", "Фруктовый смузи", "Морс",

                                };
public:
    everydayDishes();
    virtual~everydayDishes();
  //  weekDay week_Day();
    const std::string* getMenu() const;
};

#endif // EVERYDAYDISHES_H
