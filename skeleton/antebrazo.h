/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef ANTEBRAZO_H
#define ANTEBRAZO_H

#include "mano.h"
#include "cube.h"
#include "object3d.h"



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _antebrazo:public _object3D
{
protected:
    _mano mano = _mano() ;
    _cube cube = _cube() ;
public:
    _antebrazo();
    float apertura ;
    float translacion ;
    void draw_fill();
};

#endif
