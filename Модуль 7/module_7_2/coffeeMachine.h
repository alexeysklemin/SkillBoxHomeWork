// coffeeMachine.h
#pragma once
#include <windows.h>
#include <functional>

// Тип для уведомлений (GUI, MessageBox и т.д.)
using NotifyCallback = std::function<void(const std::wstring&)>;

class CoffeeLogic {
public:
    // Конструктор: передаём коллбэк для сообщений
    explicit CoffeeLogic(NotifyCallback notify);

    // Основные действия
    bool MakeAmericano();
    bool MakeLatte();
    bool MakeCappuccino();

    // Заправка (вызывается при "Залить")
    void Refill(int water, int milk);

    // Получение текущих значений (для отображения)
    int GetWater() const { return m_water; }
    int GetMilk() const { return m_milk; }

private:
    // Ингредиенты
    int m_water;
    int m_milk;
    int m_coffee;  // условно, не используется в задании

    // Коллбэк для уведомлений
    NotifyCallback m_notify;

    // Проверка, хватает ли на напиток
    bool HasEnough(const std::string& drink) const;
};

