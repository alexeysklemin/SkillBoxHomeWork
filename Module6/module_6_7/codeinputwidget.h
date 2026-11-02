// codeinputwidget.h
#ifndef CODEINPUTWIDGET_H
#define CODEINPUTWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>

QT_BEGIN_NAMESPACE
class QRegularExpressionValidator;
QT_END_NAMESPACE

class CodeInputWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString code READ code WRITE setCode NOTIFY codeChanged)

public:
    explicit CodeInputWidget(QWidget *parent = nullptr);

    QString code() const;
    void setCode(const QString &code);

    bool isValid() const;

signals:
    void codeEntered();      // пользователь нажал Enter
    void codeChanged(const QString &newCode); // текст изменился
    void validationFailed(); // ввод не прошёл валидацию (опционально)

private:
    QLineEdit* m_lineEditN;
    QLineEdit* m_lineEditM;
    QLabel*    m_slashLabel;
    QRegularExpressionValidator* m_validator;
    void validateCurrent();
};

#endif // CODEINPUTWIDGET_H
