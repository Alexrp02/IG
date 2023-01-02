/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "object3d.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _dashboard:public _object3D
{
public:
  _dashboard(int);
  void draw_texture() ;
  void draw_line() ;
};

#endif
