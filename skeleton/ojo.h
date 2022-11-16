/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef OJO_H
#define OJO_H
#include "cylinder.h"
#include "object3d.h"



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _ojo:public _object3D
{
protected:

    _cylinder cylinder = _cylinder(50, 0.2, 0.4) ;
public:
    _ojo();
    void draw_fill();
};

#endif
