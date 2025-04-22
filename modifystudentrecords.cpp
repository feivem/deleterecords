#include "modifystudentrecords.h"
#include "ui_modifystudentrecords.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>

ModifyStudentRecordsWindow::ModifyStudentRecordsWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::ModifyStudentRecordsWindow)
{
    ui->setupUi(this);
    connect(ui->Modify, &QPushButton::clicked, this, &ModifyStudentRecordsWindow::onModifyRecordsClicked);
}

ModifyStudentRecordsWindow::~ModifyStudentRecordsWindow()
{
    delete ui;
}

void ModifyStudentRecordsWindow::onModifyRecordsClicked()
{
    QString studentIdInput = ui->StudentID->text().trimmed();
    QString courseInput = ui->Course->text().trimmed();
    QString newGradeInput = ui->NewGrade->text().trimmed();
    QString newAttendanceInput = ui->attendance->text().trimmed();

    // Validation
    if (studentIdInput.isEmpty() || courseInput.isEmpty() || newGradeInput.isEmpty() || newAttendanceInput.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }

    QString filePath = "C:/Users/user/Documents/StudentManagementSystem/QtStudentManagementSyetm-main";

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Cannot open file for reading.");
        return;
    }

    QTextStream in(&file);
    QStringList lines;
    bool found = false;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(",");

        if (parts.size() == 4 && parts[0] == studentIdInput && parts[1] == courseInput) {
            parts[2] = newGradeInput;
            parts[3] = newAttendanceInput;
            found = true;
        }

        lines.append(parts.join(","));
    }
    file.close();

    if (!found) {
        QMessageBox::information(this, "Not Found", "Student record not found.");
        return;
    }

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QMessageBox::warning(this, "Error", "Cannot open file for writing.");
        return;
    }

    QTextStream out(&file);
    for (const QString &line : lines) {
        out << line << "\n";
    }
    file.close();

    QMessageBox::information(this, "Success", "Student record updated successfully.");
}
