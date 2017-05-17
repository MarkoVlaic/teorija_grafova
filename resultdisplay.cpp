#include "resultdisplay.h"

ResultDisplay::ResultDisplay(QWidget *parent) : QWidget(parent)
{
    first = new QLabel(this);
    second = new QLabel(this);

    layout = new QFormLayout;
    layout->addRow(first, second);
}

void ResultDisplay::setDisplayData(std::pair<std::string, std::string> displayData)
{
    this->displayData = make_pair(displayData.first, displayData.second);

    printf("Got %s and %s\n", displayData.first, displayData.second);

    QString firstDisplay = QString::fromStdString(displayData.first);
    QString secondDisplay = QString::fromStdString(displayData.second);

    printf("Casted %s and %s", firstDisplay.toLatin1().data(), secondDisplay.toLatin1().data());

    first->setText(firstDisplay.toLatin1().data());
    second->setText(secondDisplay.toLatin1().data());
}
