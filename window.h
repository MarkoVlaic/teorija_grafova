#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QTextStream>
#include <QFile>

#include <vector>

#include "welcomewidget.h"
#include "manualinput.h"
#include "manualdialog.h"
#include "filedialog.h"
#include "resultdisplay.h"

#include "snphandler.h"

class Window : public QWidget
{
    Q_OBJECT
    public:
        explicit Window(QWidget *parent = 0);
    private:
        WelcomeWidget* welcome;
        ManualInput* manualInputPanel;
        ManualDialog* manualDialog;
        FileDialog* fileDialog;
        ResultDisplay* resultDisplay;
        SnpHandler snpHandler;
        std::pair<std::string, std::string> resultData;
    public slots:
        void displayManualDialog();
        void displayManualForm(int);
        void displayFileDialog();
        void processFileData();
};

#endif // WINDOW_H
