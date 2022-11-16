/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "cuerpo.h"
#include<cmath>

using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_cuerpo::_cuerpo()
{
}

void _cuerpo::draw_fill() {
    glMatrixMode(GL_MODELVIEW) ;

    glPushMatrix() ;
        glScalef(0.75, 0.75, 0.75) ;
        glColor3fv((GLfloat *) &GRAY) ;
        cube.draw_fill() ;
    glPopMatrix() ;
}



