// computregameview.h
#ifndef COMPUTERGAMEVIEW_H
#define COMPUTERGAMEVIEW_H
#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include "../engine/computer.h"

class ComputerGameView : public QWidget
{
    Q_OBJECT
public:
    explicit ComputerGameView(QWidget *parent = nullptr);
    ~ComputerGameView() = default;

signals:
    // Этот сигнал будет отправлять текст в MainWindow
    void requestStatusMessage(const QString &msg);

private slots:
    void onAnswerSelected();

private:
    QComboBox *m_answerCombo;
    QPushButton *m_checkBtn;
    computer *m_computer;
    QLineEdit *m_computerGuessField;

};

#endif // COMPUTERGAMEVIEW_H
