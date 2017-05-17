#include "window.h"

#include <stdio.h>

Window::Window(QWidget *parent) : QWidget(parent)
{
    setFixedSize(640, 480);

    welcome = new WelcomeWidget(this);
    manualInputPanel = new ManualInput(this);
    manualDialog = new ManualDialog(this);
    fileDialog = new FileDialog(this);
    resultDisplay = new ResultDisplay(this);

    manualInputPanel->setVisible(false);
    manualDialog->setVisible(false);
    fileDialog->setVisible(false);
    resultDisplay->setVisible(false);
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

void Window::displayFileDialog()
{
    welcome->setVisible(false);
    fileDialog->setVisible(true);
}

void Window::processFileData()
{
    printf("Started reading a file\n");

    std::vector<std::vector<char>> snpMat;
    std::vector<std::vector<char>> fragMat;

    QFile snpFile(fileDialog->matFile);

    if(!snpFile.open(QIODevice::ReadOnly | QIODevice::Text))return;

    printf("SNP file opened\n");

    QTextStream snpin(&snpFile);
    int ind=0;
    while(!snpin.atEnd()){
        QString line = snpin.readLine();
        std::vector<char> vec;
        snpMat.push_back(vec);

        std::string normalLine = line.toUtf8().constData();

        for(int i=0;i<normalLine.size();i++){
            snpMat[ind].push_back(normalLine[i]);
        }

        ind++;
    }

    QFile fragFile(fileDialog->fragFile);

    if(!fragFile.open(QIODevice::ReadOnly | QIODevice::Text))return;

    printf("Fragment file opened\n");

    QTextStream fragin(&fragFile);
    ind=0;
    while(!fragin.atEnd()){
        QString line = fragin.readLine();
        std::vector<char> vec;
        fragMat.push_back(vec);

        std::string normalLine = line.toUtf8().constData();
        printf("Normalline: %s\n", normalLine.c_str());
        for(int i=0;i<normalLine.size();i++){
            fragMat[ind].push_back(normalLine[i]);
        }

        ind++;
    }

    printf("Starting to process\n");

    snpHandler.setRowNumber(snpMat.size());
    snpHandler.setColNumber(snpMat[0].size());
    snpHandler.setSnpMat(snpMat);
    snpHandler.setFragmentMat(fragMat);

    this->resultData = snpHandler.purify();

    printf("%s %s", resultData.first.c_str(), resultData.second.c_str());
    resultDisplay->setDisplayData(resultData);
    fileDialog->setVisible(false);
    resultDisplay->setVisible(true);
}
