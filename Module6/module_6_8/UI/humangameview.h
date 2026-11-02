// humangameview.h
#ifndef HUMANGAMEVIEW_H
#define HUMANGAMEVIEW_H
#include <QWidget>
#include <QObject>
#include <QLineEdit>
#include <QLabel>
#include "../engine/human.h"

class HumanGameView : public QWidget
{
    Q_OBJECT
public:
    explicit HumanGameView(QWidget *parent = nullptr);
    ~HumanGameView() = default;




signals:
    void requestStatusMessage(const QString &msg);

private slots:
    void onAnswerHumam();

private:
    human *m_human;
    QLineEdit *m_humanGuessField;
    QLabel *m_computerAnswerField;

};

#endif // HUMANGAMEVIEW_H
