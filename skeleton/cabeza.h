/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef CABEZA_H
#define CABEZA_H
#include "cylinder.h"
#include "ojo.h"
#include "object3d.h"



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _cabeza:public _object3D
{
protected:

    _cylinder cylinder = _cylinder(50, 0.08, 0.5) ;
    _ojo ojo = _ojo () ;
public:
    _cabeza();
    void draw_fill();
};

#endif
