#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QMainWindow>
#include "common.h"

// Qt-классы: forward declaration (best ptacties)
// Суть: «Где-то есть класс с таким именем. Верь мне. Позже я расскажу подробности».
class QTextEdit;
class QPushButton;
class QVBoxLayout;
class QComboBox;
class QMenuBar;

// Мои классы: forward declaration
class everydayDishes;

class myWidget: public QMainWindow
{
    Q_OBJECT
public:
    myWidget(QWidget *parent = nullptr);
    virtual~myWidget();

private slots:
   // void updateMenu(int day);
    void onPrintClicked();
    void saveToJson();          // Сохранить в Json
    void saveToWord();          // Сохранить в Word
    void exitApp();             // Выход из приложения

private:
    myWidget(const myWidget &W);
    const myWidget &operator =(const myWidget &W);
    void setupWindow();
    void createWidgets();
    void setupLayouts();
    void setupConnections();
    // А вот тут уже чистота! Никаких int, только перечисление будет вызываться что бы сработал слот
    // void updateMenuByDay();


    QTextEdit *editForm;
    QPushButton *btnPrint;
    QComboBox *daySelector;
    QMenuBar *sysmenu;
    QAction *actionSaveJson;
    QAction *actionSaveWord;
    QAction *actionExit;
    QAction *actionAbout;
    everydayDishes *dishes;

};

#endif // MYWIDGET_H
