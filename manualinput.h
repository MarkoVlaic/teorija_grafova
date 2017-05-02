#ifndef MANUALINPUT_H
#define MANUALINPUT_H

#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <string>
#include <QPushButton>

class ManualInput : public QWidget
{
    Q_OBJECT
    public:
        explicit ManualInput(QWidget *parent = 0);
        void setFragmentNumber(unsigned int fragmentNumber);
        void displayInputs();
    private:
        QFormLayout* layout;
        unsigned int fragmentNumber;
        QLineEdit** inputs;
};

#endif // MANUALINPUT_H
