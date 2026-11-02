// mainwindow.cpp
#include "mainwindow.h"
#include "user_logic.h"
#include "computergameview.h"
#include "humangameview.h"
#include "QStatusbar.h"
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(480, 320);

    // 1. Центральный виджет и ГЛАВНЫЙ layout
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Создаем главный layout
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->setSpacing(20);

    // 2. ЛЕВАЯ часть
    QVBoxLayout *leftLayout = new QVBoxLayout();

    QLabel *labelMode = new QLabel("Кто угадывает?");
    chooseCombo = new QComboBox();
    chooseCombo->addItem("Компьютер");
    chooseCombo->addItem("Человек");

    leftLayout->addWidget(labelMode);
    leftLayout->addWidget(chooseCombo);
    leftLayout->addStretch(); // Чтобы элементы были сверху

    // Добавляем левую часть в главную
    mainLayout->addLayout(leftLayout);

    // 3. Создаем ИГРОВЫЕ ВИДЫ (Сначала создаем, потом добавляем в стек!)
    m_computerGameView = new ComputerGameView();
    m_humanGameView = new HumanGameView();

    // Важно: у видов не должно быть своих layout'ов с родителем this,
    // если они добавляются в стек. Лучше использовать setLayout внутри них.

    // 4. ПРАВАЯ часть (Stack)
    QStackedWidget *gameStack = new QStackedWidget();
    gameStack->addWidget(m_computerGameView); // Индекс 0
    gameStack->addWidget(m_humanGameView);    // Индекс 1

    // Добавляем стек в главную форму
    mainLayout->addWidget(gameStack);

    // Настраиваем пропорции: Левая часть узкая (1), Правая широкая (3)
    mainLayout->setStretch(0, 1);
    mainLayout->setStretch(1, 3);

    // 5. Подключаем переключение (ТОЛЬКО ОДИН connect!)
    connect(chooseCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, [gameStack](int index) {
        gameStack->setCurrentIndex(index);
    });

    // В конструкторе MainWindow, после setCentralWidget
  /*  QStatusBar *sb = statusBar();
    sb->showMessage("Задуманное число больше чем?");*/

    connect(m_computerGameView, &ComputerGameView::requestStatusMessage,
            this, [this](const QString &msg) {
        statusBar()->showMessage(msg);
    });

    // То же самое можно сделать для HumanGameView, если нужно

}

MainWindow::~MainWindow()
{

}
