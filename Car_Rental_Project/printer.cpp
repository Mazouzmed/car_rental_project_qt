#include "printer.h"

#include <QTextDocument>

Printer::Printer(QObject *parent) : QObject(parent)
{


}

QString Printer::printModel(QStandardItemModel *model)
{
    /*
     * Using html format to generate a table to be printed in the document.
     */
    QString htmlHead = "<html><head>\n"
                         "<style>\n"
                             "table {\n"
                             "font-family: arial, sans-serif;\n"
                             "border-collapse: collapse;\n"
                             "width: 100%;\n"
                             "}\n"
                             "td, th {\n"
                             "border: 3px solid #dddddd;\n"
                             "text-align: left;\n"
                             "padding: 8px;\n"
                             "}\n"
                             "tr:nth-child(even) {\n"
                             "background-color: #dddddd;\n"
                             "}\n"
                         "</style>\n"
                    "</head>\n";
    QString html;
    html = htmlHead;
    html+= "<body><h1 style=\"text-align:center\"> Inventory of Vehicles</h1> <table  border=\"1\" cellspacing=\"0\" cellpadding=\"0\" width=\"200\" text-align=\"center\">";
    html+= "<td><h3> type</h3></td>";
    html+= "<td><h3> Make</h3></td>";
    html+= "<td><h3> Model</h3></td>";
    html+= "<td><h3> Year</h3></td>";
    html+= "<td><h3> Color</h3></td>";
    html+= "<td><h3> WheelDrive</h3></td>";
    html+= "<td><h3> Mileage</h3></td>";
    html+= "<td><h3> Fare</h3></td>";

    for(int row = 0; row < model->rowCount(); row++) {
      html += "<tr>";
      for(int column = 0; column < model->columnCount(); column++) {
        QString data = model->data(model->index(row, column), Qt::DisplayRole).toString();
        html += "<td> " + data + "</td>";
      }
      html += "$/day</tr>";
    }
    html += "</table></body></html>";

   return html;
}

