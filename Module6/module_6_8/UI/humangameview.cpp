#include "humangameview.h"
#include <QVBoxLayout>
#include <QIntValidator>

HumanGameView::HumanGameView(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Человек угадывает");
    setFixedSize(320, 240);

    m_humanGuessField = new QLineEdit(this);
    m_computerAnswerField = new QLabel(this);

    QIntValidator *validator = new QIntValidator(1, 63, this); // Только числа от 1 до 63
    m_humanGuessField->setValidator(validator);

    auto* central = new QWidget(this);
    auto* layout = new QVBoxLayout(central);

    layout->addWidget(m_humanGuessField);
    layout->addWidget(m_computerAnswerField);
}

void HumanGameView::onAnswerHumam()
{

}

