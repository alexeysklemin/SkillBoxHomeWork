// coffeeMachine.cpp
#include "coffeeMachine.h"
#include <functional>  
#include <iostream>   

CoffeeLogic::CoffeeLogic(NotifyCallback notify)
    : m_water(0), m_milk(0), m_coffee(200),  // кофе не участвует в задании
    m_notify(std::move(notify))
{
}

void CoffeeLogic::Refill(int water, int milk) {
    m_water = water;
    m_milk = milk;
    if (m_notify) {
        m_notify(L"Кофемашина заправлена!");
    }
}

bool CoffeeLogic::HasEnough(const std::string& drink) const {
    if (drink == "americano") {
        return m_water >= 300;
    }
    if (drink == "latte") {
        return m_water >= 30 && m_milk >= 270;
    }
    return false;
}

bool CoffeeLogic::MakeAmericano() {
    if (!HasEnough("americano")) {
        if (m_notify) m_notify(L"Не хватает воды для американо!");
        return false;
    }

    m_water -= 300;
    if (m_notify) m_notify(L"Готовится американо...");
    return true;
}

bool CoffeeLogic::MakeLatte() {
    if (!HasEnough("latte")) {
        if (m_notify) m_notify(L"Не хватает воды или молока для латте!");
        return false;
    }

    m_water -= 30;
    m_milk -= 270;
    if (m_notify) m_notify(L"Готовится латте...");
    return true;
}

bool CoffeeLogic::MakeCappuccino() {
    if (!HasEnough("latte")) {
        if (m_notify) m_notify(L"Не хватает ингредиентов для капучино!");
        return false;
    }

    m_water -= 30;
    m_milk -= 270;
    if (m_notify) m_notify(L"Готовится капучино...");
    return true;
}