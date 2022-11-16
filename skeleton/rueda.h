/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef RUEDA_H
#define RUEDA_H

#include "cylinder.h"
#include "object3d.h"



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _rueda:public _object3D
{
protected:

    _cylinder cylinder = _cylinder(50, 0.4, 0.2) ;
public:
    _rueda();
    void draw_fill();
};

#endif
