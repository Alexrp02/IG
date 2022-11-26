/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef MANO_H
#define MANO_H

#include "sphere.h"
#include "dedo.h"
#include "object3d.h"



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _mano:public _object3D
{
protected:
    _dedo dedo ;
    _sphere sphere = _sphere(50, 1, 50) ;
public:
    _mano();
    float apertura ;
    void draw(string mode);
};

#endif
