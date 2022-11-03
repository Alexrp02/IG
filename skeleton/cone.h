/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef CONE_H
#define CONE_H

#include "object3d.h"



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _cone:public _object3D
{
public:
    _cone(int n, float Radius, float Height);
};

#endif
