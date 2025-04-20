#include "mainwindow.h"
#include "studentloginwindow.h"
#include "adminloginwindow.h"  // Include AdminLoginWindow header
#include <QVBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), studentWindow(nullptr), adminWindow(nullptr) {

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    usertype = new QLabel("Select type of user to log in", this);

    adminorstud = new QComboBox(this);
    adminorstud->setObjectName("adminorstud");
    adminorstud->addItem("Admin");
    adminorstud->addItem("Student");

    continue_ = new QPushButton("Continue", this);
    continue_->setObjectName("continue");

    layout->addWidget(usertype);
    layout->addWidget(adminorstud);
    layout->addWidget(continue_);

    connect(continue_, &QPushButton::clicked, this, &MainWindow::onContinueClicked);

    setCentralWidget(centralWidget);
    setWindowTitle("Main Window");
    resize(300, 150);
}

MainWindow::~MainWindow() {}

void MainWindow::onContinueClicked() {
    QString selected = adminorstud->currentText();

    if (selected == "Student") {
        if (!studentWindow) {
            studentWindow = new StudentLoginWindow();
        }
        studentWindow->show();
        this->hide();  // optional: hides main window while login is shown
    } else if (selected == "Admin") {
        if (!adminWindow) {
            adminWindow = new AdminLoginWindow();  // Create the AdminLoginWindow
        }
        adminWindow->show();
        this->hide();  // optional: hides main window while login is shown
    }
}
