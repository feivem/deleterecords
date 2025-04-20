#include "deleterecordwindow.h"
#include "ui_deleterecordwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

DeleteRecordWindow::DeleteRecordWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleterecordwindow)
{
    ui->setupUi(this);

    connect(ui->deleteButton, &QPushButton::clicked, this, [=]() {
        QString studentId = ui->studentIdLineEdit->text().trimmed();
        if (!studentId.isEmpty()) {
            deleteStudentByIdFromBlockFile(studentId);
        } else {
            QMessageBox::warning(this, "Input Error", "Please enter a student ID.");
        }
    });
}

DeleteRecordWindow::~DeleteRecordWindow()
{
    delete ui;
}

void DeleteRecordWindow::deleteStudentByIdFromBlockFile(const QString &studentId)
{
    QString filePath = "C:/Users/User/OneDrive/Documents/QtStudentManagementSyetm-main/student.txt";
    QFile file(filePath);
    QFile tempFile("temp.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text) || !tempFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not open file.");
        return;
    }

    QTextStream in(&file);
    QTextStream out(&tempFile);

    bool skipBlock = false;
    bool found = false;

    while (!in.atEnd()) {
        QString line = in.readLine();

        if (line.startsWith("Student ID:")) {
            if (line.contains(studentId)) {
                skipBlock = true;
                found = true;
                continue;
            }
        }

        if (skipBlock) {
            if (line.trimmed() == "----------------------------------------") {
                skipBlock = false;
            }
            continue;
        }

        out << line << "\n";
    }

    file.close();
    tempFile.close();

    if (found) {
        file.remove();
        tempFile.rename(filePath);
        QMessageBox::information(this, "Success", "Student record deleted successfully.");
    } else {
        tempFile.remove();
        QMessageBox::information(this, "Not Found", "Student ID not found.");
    }
}
