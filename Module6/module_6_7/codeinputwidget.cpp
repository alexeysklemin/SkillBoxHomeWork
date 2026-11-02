// codeinputwidget.cpp
#include "codeinputwidget.h"
#include <QRegularExpressionValidator>
#include <QVBoxLayout>
#include <QRegularExpression>

#include "codeinputwidget.h"
#include <QHBoxLayout>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

CodeInputWidget::CodeInputWidget(QWidget *parent)
    : QWidget(parent)
    , m_lineEditN(new QLineEdit(this))
    , m_lineEditM(new QLineEdit(this))
    , m_slashLabel(new QLabel("/", this))
{
    // Настройка визуала
    m_slashLabel->setAlignment(Qt::AlignCenter);
    m_slashLabel->setStyleSheet("QLabel { font-size: 20px; font-weight: bold; margin: 0 4px; }");

    m_lineEditN->setPlaceholderText("N");
    m_lineEditM->setPlaceholderText("M");
    m_lineEditN->setAlignment(Qt::AlignCenter);
    m_lineEditM->setAlignment(Qt::AlignCenter);

    // Валидатор: только целые числа (опциональный минус)
    QRegularExpression intRx(R"(^-?\d*$)");
    m_validator = new QRegularExpressionValidator(intRx, this);
    m_lineEditN->setValidator(m_validator);
    m_lineEditM->setValidator(m_validator);

    // Лейаут: [Поле_N] / [Поле_M]
    auto* layout = new QHBoxLayout(this);
    layout->setContentsMargins(5, 5, 5, 5);
    layout->setSpacing(2);
    layout->addWidget(m_lineEditN, 1);
    layout->addWidget(m_slashLabel);
    layout->addWidget(m_lineEditM, 1);

    // Сигналы
    auto emitChanged = [this]() {
        emit codeChanged(code());
        validateCurrent();
    };

    connect(m_lineEditN, &QLineEdit::textChanged, this, emitChanged);
    connect(m_lineEditM, &QLineEdit::textChanged, this, emitChanged);
    connect(m_lineEditN, &QLineEdit::returnPressed, this, &CodeInputWidget::codeEntered);
    connect(m_lineEditM, &QLineEdit::returnPressed, this, &CodeInputWidget::codeEntered);
}

QString CodeInputWidget::code() const
{
    return m_lineEditN->text() + "/" + m_lineEditM->text();
}

void CodeInputWidget::setCode(const QString &code)
{
    auto parts = code.split('/');
    if (parts.size() == 2) {
        m_lineEditN->setText(parts[0]);
        m_lineEditM->setText(parts[1]);
    }
}

bool CodeInputWidget::isValid() const
{
    int pos = 0;
    QString nText = m_lineEditN->text();
    QString mText = m_lineEditM->text();

    if (nText.isEmpty() || mText.isEmpty()) return false;

    // Твоя точная строка, исправленная под 2 поля:
    QString tmpN = nText;
    QString tmpM = mText;
    bool nOk = (m_validator->validate(tmpN, pos) == QValidator::Acceptable);
    bool mOk = (m_validator->validate(tmpM, pos) == QValidator::Acceptable);

    return nOk && mOk;
}

void CodeInputWidget::validateCurrent()
{
    if (!isValid()) {
        emit validationFailed();
    }
}
