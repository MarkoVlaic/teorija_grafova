#include "window.h"

#include <stdio.h>

Window::Window(QWidget *parent) : QWidget(parent)
{
    setFixedSize(640, 480);

    welcome = new WelcomeWidget(this);
    manualInputPanel = new ManualInput(this);
    manualDialog = new ManualDialog(this);

    manualInputPanel->setVisible(false);
    manualDialog->setVisible(false);
}

void Window::displayManualDialog()
{
    /*manualInputPanel->setFragmentNumber(10);
    manualInputPanel->setVisible(true);*/
    welcome->setVisible(false);
    manualDialog->setVisible(true);

    connect(manualDialog, SIGNAL(submitDialog(int)), this, SLOT(displayManualForm(int)));
}

void Window::displayManualForm(int n)
{
    manualDialog->setVisible(false);

    manualInputPanel->setFragmentNumber(n);

    manualInputPanel->setVisible(true);
}
