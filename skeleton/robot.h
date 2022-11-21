/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef ROBOT_H
#define ROBOT_H

#include "brazo.h"
#include "cabeza.h"
#include "cuerpo.h"
#include "object3d.h"
#include "rueda.h"



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _robot:public _object3D
{
protected:

    _cuerpo cuerpo = _cuerpo () ;
    _rueda rueda = _rueda() ;
public:
    _robot();
    _cabeza cabeza = _cabeza() ;
    _brazo brazo = _brazo () ;
    void draw_fill();
};

#endif
