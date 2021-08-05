#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QAbstractButton>
#include <QObject>

class clickableLabel : public QAbstractButton

{
      Q_OBJECT
public:
    clickableLabel();
public slots:
   void click();
};

#endif // CLICKABLELABEL_H
