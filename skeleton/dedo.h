/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef DEDO_H
#define DEDO_H

#include "cube.h"
#include "object3d.h"



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _dedo:public _object3D
{
protected:
    _cube cube1 ;
    _cube cube2 ;
public:
    _dedo();
    float x ;
    void draw_fill();
};

#endif
