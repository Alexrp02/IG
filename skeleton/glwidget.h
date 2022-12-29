/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/gl.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <iostream>
#include "antebrazo.h"
#include "brazo.h"
#include "cabeza.h"
#include "cube.h"
#include "cone.h"
#include "cuerpo.h"
#include "cylinder.h"
#include "dashboard.h"
#include "dedo.h"
#include "mano.h"
#include "ojo.h"
#include "robot.h"
#include "rueda.h"
#include "sphere.h"
#include "vertex.h"
#include "colors.h"
#include "hierarchical.h"
#include "axis.h"
#include "tetrahedron.h"
#include "file_ply_stl.h"
#include "ply_object.h"


namespace _gl_widget_ne {

  const float X_MIN=-.1;
  const float X_MAX=.1;
  const float Y_MIN=-.1;
  const float Y_MAX=.1;
  const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
  const float BACK_PLANE_PERSPECTIVE=1000;
  const float DEFAULT_DISTANCE=2;
  const float ANGLE_STEP=1;

  typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _mode_draw;
  typedef enum {OBJECT_TETRAHEDRON,OBJECT_CUBE,OBJECT_PLY, OBJECT_CONE, OBJECT_CYLINDER, OBJECT_SPHERE, OBJECT_HIERARCHICAL, OBJECT_DASHBOARD} _object;
}

class _window;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget
{
Q_OBJECT
public:
  _gl_widget(_window *Window1);

  float x_size ;
  float y_size ;
  float light_angle;
  GLfloat Light_position [4] = {1.0, 1.0, 0.0, 0} ;
  void clear_window();
  void change_projection();
  void change_observer();
  void change_light();

  void draw_axis();
  void draw_objects();
  bool giro ;

public slots:
  void idle_event() ;

protected:
  void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void initializeGL() Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;


private:
  _window *Window;
  bool animation;
  bool GOURAD;
  bool translacion ;
  bool apertura ;
  QTimer* timer ;
  _axis Axis;
  _tetrahedron Tetrahedron;
  _cube Cube;
  _ply_object Ply  = _ply_object("../skeleton/ply_models/cow.ply");
  _cone Cone = _cone(100, 0.5, 1.0);
  _cylinder Cylinder = _cylinder(100, 1.0, 1.0) ;
  _sphere Sphere = _sphere(50, 1.0, 100) ;
//  _hierarchical Hierarchical = _hierarchical() ;
  _dedo Dedo = _dedo() ;
  _mano Mano = _mano() ;
  _antebrazo Antebrazo = _antebrazo() ;
  _brazo Brazo = _brazo() ;
  _ojo Ojo = _ojo() ;
  _cabeza Cabeza = _cabeza() ;
  _cuerpo Cuerpo = _cuerpo() ;
  _rueda Rueda = _rueda() ;
  _robot Robot = _robot() ;
  _dashboard Tablero = _dashboard(5) ;
  _gl_widget_ne::_object Object;

  bool Draw_point;
  bool Draw_line;
  bool Draw_fill;
  bool Draw_chess;

  float Observer_angle_x;
  float Observer_angle_y;
  float Observer_distance;
};

#endif
