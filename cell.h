#ifndef MYCELL_H
#define MYCELL_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>

class Cell : public QObject, public QGraphicsRectItem
{
  Q_OBJECT
  Q_PROPERTY(QBrush color READ brush WRITE setBrush)
  Q_PROPERTY(QRectF geometry READ rect WRITE setRect )
  Q_PROPERTY(QPen line READ pen WRITE setPen )
  public:
  Cell(QGraphicsItem *parent = 0); //конструктор
};


#endif










