#include "transactiondisplay.h"
#include "ui_transactiondisplay.h"





TransactionDisplay::TransactionDisplay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransactionDisplay)
{
    ui->setupUi(this);
    this->setWindowTitle("Rented Cars Transactions");
    model = new QStandardItemModel(this);
    model->clear();
    /*
     * Creating the header of the table view
     */
    QStringList headers;
    headers.append("ID");
    headers.append("Name");
    headers.append("Address");
    headers.append("Phone Number");
    headers.append("Vehicle type");
    headers.append("Make");
    headers.append("Model");
    headers.append("Year");
    headers.append("Insurance Included");
    headers.append("Total");
    headers.append("rented on");
    headers.append("return date");
    model->setColumnCount(12);
    model->setHorizontalHeaderLabels(headers);
    populateModel();
}

TransactionDisplay::~TransactionDisplay()
{
    delete ui;
}

void TransactionDisplay::populateModel()
{
    QString path = "C:/Users/zouma/OneDrive/Bureau/Car_Rental_Project/rental_transactions.txt";
    QFile sourceFile(path);
    sourceFile.open(QIODevice::ReadOnly);
    if(!sourceFile.isOpen()){
        //  qDebug() << "Unable to open the file"<<endl;
        QMessageBox::information(this,"error",sourceFile.errorString());
    }
    QTextStream in(&sourceFile);
    int row =0;
    while(!in.atEnd()){

        QString line = in.readLine();
        QStringList fields = line.split(",");
        for(size_t i = 0;i<fields.length();i++){
            QStandardItem *item = new QStandardItem(fields.at(i));
            model->setItem(row,i,item);
        }

        row++;
    }
    sourceFile.close();
    ui->transactionTable->setModel(model);
    ui->transactionTable->setAlternatingRowColors(true);
}

void TransactionDisplay::on_pushButton_clicked()
{
    static_cast<QDialog*>(this->parent())->show();
    this->close();
}

