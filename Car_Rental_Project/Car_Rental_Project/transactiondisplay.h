#ifndef TRANSACTIONDISPLAY_H
#define TRANSACTIONDISPLAY_H

#include <QDialog>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

namespace Ui {
class TransactionDisplay;
}

class TransactionDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit TransactionDisplay(QWidget *parent = nullptr);
    ~TransactionDisplay();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TransactionDisplay *ui;
    QStandardItemModel *model;
    void populateModel();
};

#endif // TRANSACTIONDISPLAY_H
