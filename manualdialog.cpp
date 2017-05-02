#include "manualdialog.h"

ManualDialog::ManualDialog(QWidget *parent) : QWidget(parent)
{
    layout = new QFormLayout();

    label = new QLabel("Input number of fragments");
    input = new QLineEdit();
    submit = new QPushButton("Enter");

    layout->addRow(label, input);
    layout->addWidget(submit);

    setLayout(layout);
    connect(submit, SIGNAL(clicked()), this, SLOT(slotSubmit()));
}

void ManualDialog::slotSubmit()
{
    int n = input->text().toInt();
    emit submitDialog(n);
}
