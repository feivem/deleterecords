#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include "studentloginwindow.h"
#include "adminloginwindow.h"  // Add the header file for AdminLoginWindow

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onContinueClicked();

private:
    QComboBox *adminorstud;
    QPushButton *continue_;
    QLabel *usertype;

    // This ensures studentWindow and adminWindow stay alive
    StudentLoginWindow *studentWindow;
    AdminLoginWindow *adminWindow;  // Add AdminLoginWindow pointer
};

#endif // MAINWINDOW_H
