#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>

#include "welcomewidget.h"
#include "manualinput.h"
#include "manualdialog.h"

class Window : public QWidget
{
    Q_OBJECT
    public:
        explicit Window(QWidget *parent = 0);
    private:
        WelcomeWidget* welcome;
        ManualInput* manualInputPanel;
        ManualDialog* manualDialog;
    public slots:
        void displayManualDialog();
        void displayManualForm(int);
};

#endif // WINDOW_H
