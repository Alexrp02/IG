/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef HIERARCHICAL_H
#define HIERARCHICAL_H

#include "cube.h"
#include "cube.cc"
#include "object3d.h"



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _hierarchical:public _object3D
{
public:
    _hierarchical();
    _cube Cube = _cube(1.0) ;
    void draw_fill();
};

#endif
