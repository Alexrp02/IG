/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include <QApplication>
#include <QAction>
#include <QMenuBar>
#include <QFrame>
#include <QLabel>
#include <QSlider>

#include "window.h"
#include "glwidget.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_window::_window()
{

  QSizePolicy Q(QSizePolicy::Expanding,QSizePolicy::Expanding);

  QWidget *Central_widget = new QWidget(this);

  QFrame *Framed_widget= new QFrame(Central_widget);
  Framed_widget->setSizePolicy(Q);
  Framed_widget->setFrameStyle(QFrame::Panel);
  Framed_widget->setLineWidth(3);


  GL_widget = new _gl_widget(this);
  GL_widget->setSizePolicy(Q);

  QHBoxLayout *Horizontal_frame = new QHBoxLayout();
  Horizontal_frame->setContentsMargins(1,1,1,1);

  Horizontal_frame->addWidget(GL_widget);
  Framed_widget->setLayout(Horizontal_frame);

  // Create the side menu widget and add it to a vertical layout
  QWidget *sideMenuWidget = new QWidget();
  QVBoxLayout *sideMenuLayout = new QVBoxLayout(sideMenuWidget);
  // Create a horizontal slider and connect it to a slot
      QSlider *slider = new QSlider(Qt::Horizontal);
      slider->setMinimum(0) ;
      slider->setMaximum(1000) ;
      slider->setFixedWidth(100) ;
      slider->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
      QObject::connect(slider, &QSlider::valueChanged, [&](int value){
          // This lambda function will be called whenever the slider value changes
          // Update the variable with the new value
          GL_widget->light_angle = (float)value/1000*2*M_PI;
          GL_widget->Light_position[0] = cos((float)value/1000*2*M_PI);
          GL_widget->Light_position[2] = sin((float)value/1000*2*M_PI);
          std::cout << (float)value/1000*2*M_PI << endl ;
      });
  //Now create the label for the slider
  QLabel *label = new QLabel("Light position:");

  //Set the side menu to align the content to the top
  sideMenuLayout->setAlignment(Qt::AlignTop	);

  // Set the border of the side menu layout to a black line and background to be white
  sideMenuWidget->setStyleSheet(".QWidget{border: 2px solid black;"
                                "background-color:white;}");

  //Add the two components to the side menu
  sideMenuLayout->addWidget(label) ;
  sideMenuLayout->addWidget(slider) ;

  QHBoxLayout *Horizontal_main = new QHBoxLayout(Central_widget);

  Horizontal_main->addWidget(Framed_widget);
  Horizontal_main->addWidget(sideMenuWidget) ;

  Central_widget->setLayout(Horizontal_main);
  setCentralWidget(Central_widget);

  // actions for file menu
  QAction *Exit = new QAction(QIcon("./icons/exit.png"), tr("&Exit..."), this);
  Exit->setShortcut(tr("Ctrl+Q"));
  Exit->setToolTip(tr("Exit the application"));
  connect(Exit, SIGNAL(triggered()), this, SLOT(close()));

  // menus
  QMenu *File_menu=menuBar()->addMenu(tr("&File"));
  File_menu->addAction(Exit);
  File_menu->setAttribute(Qt::WA_AlwaysShowToolTips);

  setWindowTitle(tr("Práctica 1"));

  resize(800,800);
}
