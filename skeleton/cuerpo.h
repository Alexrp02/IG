/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef CUERPO_H
#define CUERPO_H

#include "cube.h"
#include "object3d.h"



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _cuerpo:public _object3D
{
protected:

    _cube cube = _cube() ;
public:
    _cuerpo();
    void draw(string mode);
};

#endif
