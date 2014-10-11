#include "cell.h"

float Scale = 100.0;

Cell::Cell(QGraphicsItem *parent)
    : QObject(), QGraphicsRectItem(parent) 
{
    this->setRect(0, 0, Scale, Scale); 
}

