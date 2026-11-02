// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calculate.h"
#include "codeinputwidget.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onCalculate();  // Слот обработки расчёта

private:
    // UI-компоненты
    CodeInputWidget* m_inputWidget;
    QLabel*          m_resultLabel;
    QPushButton*     m_calcButton;

    // Бизнес-логика
    calculate        m_calculator;
};

#endif // MAINWINDOW_H
