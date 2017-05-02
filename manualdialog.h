#ifndef MANUALDIALOG_H
#define MANUALDIALOG_H

#include <QWidget>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class ManualDialog : public QWidget
{
    Q_OBJECT
    public:
        explicit ManualDialog(QWidget *parent = 0);
    private:
        QFormLayout* layout;
        QLabel* label;
        QLineEdit* input;
        QPushButton* submit;
    signals:
        void submitDialog(int);
    private slots:
        void slotSubmit();
};

#endif // MANUALDIALOG_H
