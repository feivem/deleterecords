#ifndef DELETERECORDWINDOW_H
#define DELETERECORDWINDOW_H

#include <QDialog>
#include "ui_deleterecordwindow.h"  // Automatically generated by uic

namespace Ui {
class deleterecordwindow;  // Forward declaration
}

class DeleteRecordWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteRecordWindow(QWidget *parent = nullptr);
    ~DeleteRecordWindow();

private:
    Ui::deleterecordwindow *ui;  // Pointer to the UI object
    void deleteStudentByIdFromBlockFile(const QString &studentId);
};

#endif // DELETERECORDWINDOW_H
