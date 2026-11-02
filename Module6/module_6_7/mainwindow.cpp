// mainwindow.cpp
#include "mainwindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Сокращение дробей");
    setFixedSize(320, 240);

    // === Центральный виджет и лейаут ===
    auto* centralWidget = new QWidget(this);
    auto* layout = new QVBoxLayout(centralWidget);
    layout->setContentsMargins(20, 20, 20, 20);
    layout->setSpacing(15);

    // === 1. CodeInputWidget ===
    m_inputWidget = new CodeInputWidget(this);

    // Адаптируем валидатор под ввод дробей (контекст использования)
    if (auto* lineEdit = m_inputWidget->findChild<QLineEdit*>()) {
        // Паттерн: опциональный минус, цифры, слэш, цифры
        QRegularExpression fractionRx(R"(^-?\d+/\d+$)");
        lineEdit->setValidator(new QRegularExpressionValidator(fractionRx, this));
        lineEdit->setPlaceholderText("Введите дробь (напр. 12/45)");
        lineEdit->setMaxLength(15); // защита от слишком длинного ввода
    }

    // === 2. Кнопка ===
    m_calcButton = new QPushButton("Сократить", this);

    // === 3. Результат ===
    m_resultLabel = new QLabel("Ожидание ввода...", this);
    m_resultLabel->setAlignment(Qt::AlignCenter);
    m_resultLabel->setWordWrap(true);

    // === Сборка ===
    layout->addWidget(m_inputWidget);
    layout->addWidget(m_calcButton);
    layout->addWidget(m_resultLabel);
    layout->addStretch();

    setCentralWidget(centralWidget);

    // === Сигналы ===
    connect(m_calcButton, &QPushButton::clicked, this, &MainWindow::onCalculate);
    connect(m_inputWidget, &CodeInputWidget::codeEntered, this, &MainWindow::onCalculate);
}

MainWindow::~MainWindow() = default;

void MainWindow::onCalculate()
{
    // 1. Получаем ввод из виджета
    const QString input = m_inputWidget->code().trimmed();

    // 2. Парсинг (подготовка данных для бизнес-логики)
    auto parts = input.split('/');
    if (parts.size() != 2) {
        m_resultLabel->setText("<font color='red'>Формат: Числитель/Знаменатель</font>");
        return;
    }

    bool okN = false, okM = false;
    int N = parts[0].toInt(&okN);
    int M = parts[1].toInt(&okM);

    if (!okN || !okM) {
        m_resultLabel->setText("<font color='red'>Ошибка: введите целые числа</font>");
        return;
    }

    // 3. Вызов бизнес-логики (твой класс и метод)
    // calculate::calculates(int N, int M) -> std::optional<QString>
    auto result = m_calculator.calculates(N, M);

    // 4. Обработка результата (презентационный слой)
    if (result.has_value()) {
        m_resultLabel->setText(QString("Результат: <b>%1</b>").arg(result.value()));
    } else {
        // Логика вернула nullopt -> UI отображает ошибку
        m_resultLabel->setText("<font color='red'>Ошибка: деление на ноль</font>");
    }
}
