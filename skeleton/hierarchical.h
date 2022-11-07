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
#include "object3d.h"
#include "sphere.h"



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _hierarchical:public _object3D
{
protected:
    _cube cube ;
    _sphere sphere = _sphere(50, 1.0, 80);
public:
    _hierarchical();
    float x ;
    void draw_fill();
    void patadraw() ;
};

#endif
