/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef PLY_OBJECT_H
#define PLY_OBJECT_H

#include "file_ply_stl.h"
#include "object3d.h"



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _ply_object:public _object3D
{
public:
    vector<float> Coordinates;
    vector<unsigned int> Positions;
  _ply_object(const string &file_name);
  _file_ply reader= _file_ply() ;
  void draw_line();
};

#endif
