// computergameview.cpp
#include "computergameview.h"
#include <QVBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QStatusBar>

// Конструктор: ТОЛЬКО инициализация каркаса
ComputerGameView::ComputerGameView(QWidget *parent)
    : QWidget(parent)
{
    // 1. Базовые настройки окна
    setWindowTitle("Компьютер угадывает");
    setFixedSize(320, 240);

    m_computer = new computer();

    // 2. Создание виджетов (родитель = this)
    m_answerCombo = new QComboBox(this);
    m_answerCombo->addItems({"ДА", "НЕТ", "Ты угадал"});

    m_checkBtn = new QPushButton(this);
    m_checkBtn->setText("Подтвердить");

    // 1. Создаем поле ввода
    m_computerGuessField = new QLineEdit(this);
    // 2. Делаем его недоступным для редактирования (только для чтения)
    m_computerGuessField->setReadOnly(true);
    m_computerGuessField->setEnabled(false);
    // 3. Выравниваем текст по центру (чтобы было красиво)
    m_computerGuessField->setAlignment(Qt::AlignCenter);

    // 3. Сборка лейаута
    auto* central = new QWidget(this);
    auto* layout = new QVBoxLayout(central);
    layout->addWidget(m_computerGuessField);
    layout->addWidget(new QLabel("Выберите ответ на предположение компьютера:", this));
    layout->addWidget(m_answerCombo);
    layout->addWidget(m_checkBtn);
    layout->addStretch();


    // 4. Подключение сигналов
    connect(m_answerCombo, &QComboBox::currentTextChanged, this, &ComputerGameView::onAnswerSelected);

    // 5. Статус-бар (пока пустой, наполнится позже)
    // statusBar() уже существует в QMainWindow, создавать вручную не нужно

    connect(m_checkBtn, &QPushButton::clicked, this, &ComputerGameView::onAnswerSelected);

    m_computer->getCurrentGuess();

}

//ComputerGameView::~ComputerGameView() = default; - Если = default в .h то в .cpp не ставим

// Слот реакции на выбор пользователя
void ComputerGameView::onAnswerSelected()
{
    // 1. Читаем выбор пользователя
    QString answerText = m_answerCombo->currentText();
    int responseCode = 0;

    // Конвертируем текст в код для Engine
    if (answerText == "ДА") {
        responseCode = 1;
    } else if (answerText == "НЕТ") {
        responseCode = 0;
    } else if (answerText == "Угадал") {
        responseCode = -1;
    }

    // 2. Передаем ответ в Engine (в объект m_computer)
    m_computer->answer(responseCode);

    // 3. Обновляем поле с числом (берем новое предположение из Engine)
    // Если у тебя есть метод getCurrentGuess(), используй его.
    // Если нет, можно вызвать makeGuess(), если он возвращает новое число.
    int newNumber = m_computer->getCurrentGuess();
    m_computerGuessField->setText(QString::number(newNumber));

    // 4. Отправляем новый вопрос в статус-бар главного окна через СИГНАЛ
    emit requestStatusMessage(m_computer->question());
}
