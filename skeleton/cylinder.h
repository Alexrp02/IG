/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef CYLINDER_H
#define CYLINDER_H

#include "object3d.h"



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _cylinder:public _object3D
{
public:
    _cylinder(int n, float Radius, float Height);
};

#endif
