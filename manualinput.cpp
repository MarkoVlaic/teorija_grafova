#include "manualinput.h"

ManualInput::ManualInput(QWidget *parent) : QWidget(parent)
{
    layout = new QFormLayout;

    fragmentNumber = 0;
}

void ManualInput::setFragmentNumber(unsigned int n)
{
    fragmentNumber = n;
    this->displayInputs();
}

void ManualInput::displayInputs()
{
    inputs = new QLineEdit*[fragmentNumber];

    for(int i=0;i<fragmentNumber;i++){
        inputs[i] = new QLineEdit(this);
        QString inText = QStringLiteral("Fragment %1").arg(i+1);
        QLabel* label = new QLabel((QString)inText);

        layout->addRow(label, inputs[i]);
    }

    QPushButton* process = new QPushButton("Process data");
    layout->addWidget(process);

    /*QLabel* fragment1 = new QLabel("Fragment 1");
    QLabel* fragment2 = new QLabel("Fragment 2");
    QLabel* fragment3 = new QLabel("Fragment 3");

    QLineEdit* edit1 = new QLineEdit();
    QLineEdit* edit2 = new QLineEdit();
    QLineEdit* edit3 = new QLineEdit();

    layout->addRow(fragment1, edit1);
    layout->addRow(fragment2, edit2);
    layout->addRow(fragment3, edit3);*/

    setLayout(layout);
}


