/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "brazo.h"
#include<cmath>



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_brazo::_brazo()
{
}

void _brazo::draw_fill() {
    glMatrixMode(GL_MODELVIEW) ;

    glPushMatrix() ;
        glScalef(1, 0.25, 0.25) ;
        glTranslatef(0.5, 0, 0) ;
        cube.draw_chess() ;
    glPopMatrix();

    glPushMatrix() ;
        glTranslatef(1, 0, 0) ;
        antebrazo.draw_fill() ;
    glPopMatrix();
}



