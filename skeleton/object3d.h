/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "basic_object3d.h"
#include "qimage.h"
#include <QString>


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _object3D:public _basic_object3D
{
  public:
  vector<_vertex2i> Edges;
  vector<_vertex3ui> Triangles;
  vector<_vertex3f> faceNormals;
  vector<_vertex3f> pointNormals;
  vector<int> numberOfNormals;
  QString texture_name;
  QImage Image ;
  GLuint textureID ;
  GLfloat* color = (GLfloat *) &_colors_ne::GREEN ;

  void draw_line();
  void draw_fill();
  void draw_chess() ;
  void read_texture(QString) ;
  _vertex3f calculate_normalized_normal(_vertex3f, _vertex3f, _vertex3f) ;
  float calculate_module(_vertex3f) ;
  void averageNormal () ;

};

#endif // OBJECT3D_H
