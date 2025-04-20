#include "admindashboard.h"
#include "viewallrecordswindow.h"  // Include the new header for ViewAllRecordsWindow
#include <QMessageBox>
#include "mainwindow.h" // for returning to login
#include "deleterecordwindow.h"

AdminDashboard::AdminDashboard(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Admin Dashboard");
    resize(350, 300);

    // 🏷️ Title Label
    titleLabel = new QLabel("🛠️ Admin Dashboard\n", this);
    titleLabel->setStyleSheet("font-size: 18px; font-weight: bold; text-align: center;");
    titleLabel->setAlignment(Qt::AlignCenter);

    // 🔘 Buttons
    viewAllRecordsBtn = new QPushButton("View All Student Records", this);
    modifyRecordsBtn = new QPushButton("Modify Student Records", this);
    deleteRecordsBtn = new QPushButton("Delete Student Records", this);
    viewGradesAttendanceBtn = new QPushButton("View Grades & Attendance Logs", this);
    logoutBtn = new QPushButton("Logout", this);

    // 📦 Layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(titleLabel);
    layout->addSpacing(10);
    layout->addWidget(viewAllRecordsBtn);
    layout->addWidget(modifyRecordsBtn);
    layout->addWidget(deleteRecordsBtn);
    layout->addWidget(viewGradesAttendanceBtn);
    layout->addWidget(logoutBtn);
    setLayout(layout);

    // 🔗 Connections
    connect(viewAllRecordsBtn, &QPushButton::clicked, this, &AdminDashboard::onViewAllRecordsClicked);
    connect(modifyRecordsBtn, &QPushButton::clicked, this, &AdminDashboard::onModifyRecordsClicked);
    connect(deleteRecordsBtn, &QPushButton::clicked, this, &AdminDashboard::onDeleteRecordsClicked);
    connect(viewGradesAttendanceBtn, &QPushButton::clicked, this, &AdminDashboard::onViewGradesAttendanceClicked);
    connect(logoutBtn, &QPushButton::clicked, this, &AdminDashboard::onLogoutClicked);
}

AdminDashboard::~AdminDashboard() {}

void AdminDashboard::onViewAllRecordsClicked() {
    // Open ViewAllRecordsWindow when the button is clicked
    ViewAllRecordsWindow *viewAllWindow = new ViewAllRecordsWindow();
    viewAllWindow->show();
}

void AdminDashboard::onModifyRecordsClicked() {
    QMessageBox::information(this, "Modify Records", "✏️ Modify student record functionality here.");
}

void AdminDashboard::onDeleteRecordsClicked() {
    DeleteRecordWindow *deleteWindow = new DeleteRecordWindow(this);
    deleteWindow->setModal(true);  // Optional: to make it block other windows
    deleteWindow->show();
}

void AdminDashboard::onViewGradesAttendanceClicked() {
    QMessageBox::information(this, "Grades & Attendance", "📊 Viewing all grades and attendance logs.");
}

void AdminDashboard::onLogoutClicked() {
    int confirm = QMessageBox::question(this, "Logout", "Are you sure you want to log out?",
                                        QMessageBox::Yes | QMessageBox::No);
    if (confirm == QMessageBox::Yes) {
        this->close();
        MainWindow *login = new MainWindow();
        login->show();
    }
}
