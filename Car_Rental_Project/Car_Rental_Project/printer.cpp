#include "printer.h"

#include <QTextDocument>

Printer::Printer(QObject *parent) : QObject(parent)
{


}

QString Printer::printModel(const QStandardItemModel *model)
{
    /*
     * Using html format to generate a table to be printed in the document.
     * using the Raw String format
     */
    QString htmlHead = R"(<html><head>
                         <style>
                             table {
                             font-family: arial, sans-serif;
                             border-collapse: collapse;
                             width: 100%;
                             }
                             td, th {
                             border: 3px solid #dddddd;
                             text-align: left;
                             padding: 8px;
                             }
                             tr:nth-child(even) {
                             background-color: #dddddd;
                             }
                         </style>\
                    </head>\n)";
    QString html;
    html = htmlHead;
    html+= R"(
     <body><h1 style=\"text-align:center\"> Inventory of Vehicles</h1> <table  border=\"1\" cellspacing=\"0\" cellpadding=\"0\" width=\"200\" text-align=\"center\">";
     <td><h3> type</h3></td>
     <td><h3> Make</h3></td>
     <td><h3> Model</h3></td>
     <td><h3> Year</h3></td>
     <td><h3> Color</h3></td>
     <td><h3> WheelDrive</h3></td>
     <td><h3> Mileage</h3></td>
     <td><h3> Fare</h3></td>
            )";

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

