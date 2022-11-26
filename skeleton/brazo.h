/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef BRAZO_H
#define BRAZO_H
#include "antebrazo.h"
#include "cube.h"
#include "object3d.h"



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _brazo:public _object3D
{
protected:

    _cube cube = _cube() ;
public:
    float angle ;
    _antebrazo antebrazo = _antebrazo() ;
    _brazo();
    void draw(string mode);
};

#endif
