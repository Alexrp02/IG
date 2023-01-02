/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qcombobox.h"
#include "qspinbox.h"
#include <QMainWindow>
#include <QStandardPaths>
#include <QFileDialog>
#include <QDialog>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QGuiApplication>


class _gl_widget;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _window : public QMainWindow
{
    Q_OBJECT

public:
    _window();
    QComboBox* comboBox ;
    QCheckBox* checkbox ;
    QCheckBox* gouradCheckbox ;
    QCheckBox* textureCheckbox ;
    QCheckBox* lightingCheckbox ;
    QSlider * handsSlider ;
    QSlider * armsSlider ;
    QSlider * angleSlider ;
    QSlider * lightSlider ;
    QDoubleSpinBox *armsNumber ;
    QDoubleSpinBox *armsTranslationNumber ;
    QDoubleSpinBox *handsNumber ;
    QDoubleSpinBox *headNumber ;

private:
  _gl_widget *GL_widget;
  void setSliders() ;
};

#endif
