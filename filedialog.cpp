#include "filedialog.h"
#include <algorithm>

FileDialog::FileDialog(QWidget *parent) : QWidget(parent)
{
    layout = new QFormLayout();

    selectedFragFile = new QLabel("No file selected");
    selectedMatFile = new QLabel("No file selected");

    chooseFragFile = new QPushButton("Choose fragment file");
    chooseMatFile = new QPushButton("Choose SNP matrix file");
    process = new QPushButton("Process data");

    layout->addRow(selectedFragFile, chooseFragFile);
    layout->addRow(selectedMatFile, chooseMatFile);
    layout->addWidget(process);

    setLayout(layout);

    connect(chooseFragFile, SIGNAL(clicked()), this, SLOT(slotChooseFragFile()));
    connect(chooseMatFile, SIGNAL(clicked()), this, SLOT(slotChooseMatFile()));
    connect(process, SIGNAL(clicked()), parent, SLOT(processFileData()));
}

void FileDialog::slotChooseFragFile()
{
    QString filename = QFileDialog::getOpenFileName(this, "Choose file", "/home");

    QString displayString = "";

    int i=filename.size();

    while(filename[--i] != '/'){
        displayString += filename[i];
    }

    std::reverse(displayString.begin(), displayString.end());

    selectedFragFile->setText(displayString);
    fragFile = filename;
}

void FileDialog::slotChooseMatFile()
{
    QString filename = QFileDialog::getOpenFileName(this, "Choose file", "/home");

    QString displayString = "";

    int i=filename.size();

    while(filename[--i] != '/'){
        displayString += filename[i];
    }

    std::reverse(displayString.begin(), displayString.end());

    selectedMatFile->setText(displayString);
    matFile = filename;
}
