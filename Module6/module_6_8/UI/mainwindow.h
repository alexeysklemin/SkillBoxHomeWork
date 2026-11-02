// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "computergameview.h"
#include "humangameview.h"

#include <QMainWindow>
#include <QComboBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    ComputerGameView* m_computerGameView;
    HumanGameView* m_humanGameView;
    QComboBox* chooseCombo;
};
#endif // MAINWINDOW_H
