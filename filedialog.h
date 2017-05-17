#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include <QWidget>
#include <QFileDialog>
#include <QLabel>
#include <QPushButton>
#include <QFormLayout>

class FileDialog : public QWidget
{
    Q_OBJECT
    public:
        explicit FileDialog(QWidget *parent = 0);
        QLabel *selectedFragFile, *selectedMatFile;
        QPushButton *process, *chooseFragFile, *chooseMatFile;
        QFormLayout* layout;
        QString fragFile, matFile;
    signals:

    private slots:
        void slotChooseFragFile();
        void slotChooseMatFile();
};

#endif // FILEDIALOG_H
