#include "welcomewidget.h"

WelcomeWidget::WelcomeWidget(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout;

    titleLabel = new QLabel("Welcome to sample cleaner!");

    QFont titleFont("Cantarell Regular", 25);
    titleLabel->setFont(titleFont);

    manualInput = new QPushButton("Input data mannualy");
    fileInput = new QPushButton("Input data from file");

    QFont buttonFont("Cantarell Regular", 10);

    manualInput->setFont(buttonFont);
    fileInput->setFont(buttonFont);

    layout->addWidget(titleLabel);
    layout->addWidget(manualInput);
    layout->addWidget(fileInput);

    setLayout(layout);

    connect(manualInput, SIGNAL(clicked()), parent, SLOT(displayManualDialog()));
}
