#ifndef PRINTER_H
#define PRINTER_H

#include <QObject>
#include <QStandardItemModel>
#include<QPrinter>
#include<QPrintDialog>


class Printer : public QObject
{
    Q_OBJECT
public:
    explicit Printer(QObject *parent = nullptr);
    QString printModel(QStandardItemModel *);

signals:

};

#endif // PRINTER_H
