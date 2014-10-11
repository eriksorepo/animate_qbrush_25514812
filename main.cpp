#include <QApplication>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDialog>
#include <QGridLayout>
#include <QPropertyAnimation>
#include <QGraphicsRectItem>

#include <iostream>

#include "cell.h"



QVariant myColorInterpolator(const QBrush &start, const QBrush &end, qreal progress)
{
  QColor cstart = start.color();
  QColor cend = end.color();
  int sh = cstart.hsvHue();
  int eh = cend.hsvHue();
  int ss = cstart.hsvSaturation();
  int es = cend.hsvSaturation();
  int sv = cstart.value();
  int ev = cend.value();
  int hr = qAbs( sh - eh );
  int sr = qAbs( ss - es );
  int vr = qAbs( sv - ev );
  int dirh =  sh > eh ? -1 : 1;
  int dirs =  ss > es ? -1 : 1;
  int dirv =  sv > ev ? -1 : 1;
  
  return QBrush(QColor::fromHsv( sh + dirh * progress * hr,
				 ss + dirs * progress * sr,
				 sv + dirv * progress * vr), progress > 0.5 ? Qt::SolidPattern : Qt::Dense6Pattern  );
  
  
}


int main(int argc, char** argv)
{
  QApplication app(argc,argv);
  QGraphicsView *view = new QGraphicsView;
  QGraphicsScene *scene = new QGraphicsScene;
  QDialog *dialog = new QDialog;
  QGridLayout *layout = new QGridLayout;
  layout->addWidget(view);
  view->setScene(scene);
  scene->setSceneRect(-500,-500,1000,1000);
  dialog->setLayout(layout);
  dialog->show();
  
  Cell *selectedCell = new Cell;
  scene->addItem(selectedCell);

  //selectedCell->setBrush(QBrush(QColor(255,0,0)));

  qRegisterAnimationInterpolator<QBrush>(myColorInterpolator);
  QPropertyAnimation* animation = new QPropertyAnimation(selectedCell, "color");
  animation->setDuration(10000);
  animation->setStartValue(QBrush(Qt::blue));
  animation->setEndValue(QBrush(Qt::red));
  animation->start();

  return app.exec();
}



