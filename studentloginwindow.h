#ifndef STUDENTLOGINWINDOW_H
#define STUDENTLOGINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class StudentLoginWindow : public QWidget {
    Q_OBJECT

public:
    explicit StudentLoginWindow(QWidget *parent = nullptr);

private slots:
    void handleLogin();

private:
    QLabel *IDplaceholder;
    QLabel *PINplaceholder;
    QLabel *statusLabel;
    QLineEdit *studentIdInput;
    QLineEdit *pinInput;
    QPushButton *studentlogin;

    bool validateCredentials(const QString &id, const QString &pin);
};

#endif // STUDENTLOGINWINDOW_H
