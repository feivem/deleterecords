#ifndef MODIFYSTUDENTRECORDSWINDOW_H
#define MODIFYSTUDENTRECORDSWINDOW_H

#include <QDialog>  // Changed from QMainWindow to QDialog

namespace Ui {
class ModifyStudentRecordsWindow;
}

class ModifyStudentRecordsWindow : public QDialog  // Changed QWidget to QDialog
{
    Q_OBJECT

public:
    explicit ModifyStudentRecordsWindow(QWidget *parent = nullptr);
    ~ModifyStudentRecordsWindow();

private slots:
    void onModifyRecordsClicked();

private:
    Ui::ModifyStudentRecordsWindow *ui;  // Ensure this matches with the auto-generated 'ui' object in your cpp file
};

#endif // MODIFYSTUDENTRECORDSWINDOW_H
