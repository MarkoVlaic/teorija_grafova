#ifndef WELCOMEWIDGET_H
#define WELCOMEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include <QVBoxLayout>

class WelcomeWidget : public QWidget
{
    Q_OBJECT
    public:
        explicit WelcomeWidget(QWidget *parent = 0);
    private:
        QVBoxLayout* layout;
        QLabel* titleLabel;

        QPushButton* manualInput, *fileInput;
};

#endif // WELCOMEWIDGET_H
