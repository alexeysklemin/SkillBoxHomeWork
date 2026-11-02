// screenMachine.h
#pragma once
#include "coffeeMachine.h"

class screenMachine {
public:
    screenMachine(HINSTANCE hInstance, HWND parentWindow, CoffeeLogic& logic);
    ~screenMachine();

    void Show();
    void Hide();
    HWND GetHandle() const;

private:
    static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    void CreateControls(HWND hwnd);
    void OnCommand(WPARAM wParam, LPARAM lParam);
    void OnPaint(HWND hwnd);
    void DrawLiquid(HDC hdc, int x, int y, int width, int height, int current, int max, COLORREF color);

    HINSTANCE hInstance;
    HWND hwndMain;
    HWND hParent;
    HWND hAmericano;
    HWND hLatte;
    HWND hCappuccino;

    CoffeeLogic& m_logic;

    // Графические ресурсы
    HBITMAP hBmpBackground;  // CoffeeMachine.bmp
    HBITMAP hBmpGlass;       // ingridients.bmp
};

