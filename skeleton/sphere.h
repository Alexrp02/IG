/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef SPHERE_H
#define SPHERE_H

#include "object3d.h"



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _sphere:public _object3D
{
public:
    _sphere(int n, float Radius, int revolutions);
    vector<float> textureX;
    void draw_fill() ;
};

#endif
