#ifndef RESULTDISPLAY_H
#define RESULTDISPLAY_H

#include <QWidget>
#include <QFormLayout>
#include <QLabel>

class ResultDisplay : public QWidget
{
    Q_OBJECT
    public:
        explicit ResultDisplay(QWidget *parent = 0);
        void setDisplayData(std::pair<std::string, std::string> displayData);
    private:
        QFormLayout* layout;
        QLabel *first, *second;
        std::pair<std::string, std::string> displayData;
};

#endif // RESULTDISPLAY_H
