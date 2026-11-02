// screenMachine.cpp
#include "screenMachine.h"
#include <string>

screenMachine::screenMachine(HINSTANCE hInstance, HWND parentWindow, CoffeeLogic& logic)
    : hInstance(hInstance), hParent(parentWindow), hwndMain(nullptr), m_logic(logic),
    hBmpBackground(nullptr), hBmpGlass(nullptr)
{
    // 🔹 Загружаем изображения с диска
    hBmpBackground = (HBITMAP)LoadImage(NULL, L"CoffeeMachine.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    hBmpGlass = (HBITMAP)LoadImage(NULL, L"ingridients.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

    if (!hBmpBackground) {
        MessageBox(nullptr, L"Не загружено: CoffeeMachine.bmp", L"Ошибка", MB_ICONERROR);
    }
    if (!hBmpGlass) {
        MessageBox(nullptr, L"Не загружено: ingridients.bmp", L"Ошибка", MB_ICONERROR);
    }

    // 🔹 Регистрируем класс окна
    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"ScreenMachineClass";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&wc);

    // 🔹 Создаём дочернее окно
    hwndMain = CreateWindow(
        L"ScreenMachineClass",
        L"Кофемашина",
        WS_CHILD | WS_VISIBLE,
        20, 20, 400, 300,
        parentWindow,
        nullptr,
        hInstance,
        this
    );

    if (hwndMain) {
        SetWindowLongPtr(hwndMain, GWLP_USERDATA, (LONG_PTR)this);
        CreateControls(hwndMain);
    }
}

screenMachine::~screenMachine() {
    if (hwndMain) DestroyWindow(hwndMain);
    if (hBmpBackground) DeleteObject(hBmpBackground);
    if (hBmpGlass) DeleteObject(hBmpGlass);
    UnregisterClass(L"ScreenMachineClass", hInstance);
}

void screenMachine::Show() {
    if (hwndMain) ShowWindow(hwndMain, SW_SHOW);
}

void screenMachine::Hide() {
    if (hwndMain) ShowWindow(hwndMain, SW_HIDE);
}

HWND screenMachine::GetHandle() const {
    return hwndMain;
}

LRESULT CALLBACK screenMachine::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    screenMachine* pThis = (screenMachine*)GetWindowLongPtr(hwnd, GWLP_USERDATA);

    switch (msg) {
    case WM_NCCREATE:
        pThis = (screenMachine*)((CREATESTRUCT*)lParam)->lpCreateParams;
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pThis);
        break;

    case WM_COMMAND:
        pThis->OnCommand(wParam, lParam);
        break;

    case WM_PAINT:
        pThis->OnPaint(hwnd);
        break;

    case WM_CTLCOLORBTN:
        SetBkMode((HDC)wParam, TRANSPARENT);
        return (LRESULT)GetStockObject(NULL_BRUSH);

    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

void screenMachine::CreateControls(HWND hwnd) {
    hAmericano = CreateWindow(
        L"BUTTON", L"Американо",
        WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        50, 250, 100, 30,
        hwnd, (HMENU)1002, hInstance, nullptr
    );

    hLatte = CreateWindow(
        L"BUTTON", L"Латте",
        WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        150, 250, 100, 30,
        hwnd, (HMENU)1003, hInstance, nullptr
    );

    hCappuccino = CreateWindow(
        L"BUTTON", L"Капучино",
        WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        250, 250, 100, 30,
        hwnd, (HMENU)1004, hInstance, nullptr
    );
}

void screenMachine::OnCommand(WPARAM wParam, LPARAM lParam) {
    int id = LOWORD(wParam);

    if (id == 1002) m_logic.MakeAmericano();
    else if (id == 1003) m_logic.MakeLatte();
    else if (id == 1004) m_logic.MakeCappuccino();

    // После изменения — перерисовать
    if (hwndMain) {
        InvalidateRect(hwndMain, nullptr, FALSE);
    }
}

void screenMachine::OnPaint(HWND hwnd) {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);
    HDC hMemDC = CreateCompatibleDC(hdc);

    // 1. Фон — CoffeeMachine.bmp
    if (hBmpBackground) {
        HBITMAP hOld = (HBITMAP)SelectObject(hMemDC, hBmpBackground);
        BitBlt(hdc, 0, 0, 400, 300, hMemDC, 0, 0, SRCCOPY);
        SelectObject(hMemDC, hOld);
    }

    // 2. Стаканы — ingridients.bmp
    if (hBmpGlass) {
        HBITMAP hOld = (HBITMAP)SelectObject(hMemDC, hBmpGlass);
        BitBlt(hdc, 100, 150, 80, 120, hMemDC, 0, 0, SRCCOPY);
        SelectObject(hMemDC, hOld);
    }

    // 3. Вода (голубая)
    DrawLiquid(hdc, 110, 160, 25, 100, m_logic.GetWater(), 300, RGB(0, 160, 255));

    // 4. Молоко (белое)
    DrawLiquid(hdc, 155, 160, 25, 100, m_logic.GetMilk(), 270, RGB(255, 255, 255));

    DeleteDC(hMemDC);
    EndPaint(hwnd, &ps);
}

void screenMachine::DrawLiquid(HDC hdc, int x, int y, int width, int height, int current, int max, COLORREF color) {
    if (current <= 0) return;

    int fillHeight = (current * height) / max;
    HBRUSH hBrush = CreateSolidBrush(color);
    HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);

    Rectangle(hdc, x, y + height - fillHeight, x + width, y + height);

    SelectObject(hdc, hOldBrush);
    DeleteObject(hBrush);
}