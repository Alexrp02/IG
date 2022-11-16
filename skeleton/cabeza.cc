/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "cabeza.h"
#include<cmath>

using namespace _colors_ne;



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_cabeza::_cabeza()
{
}

void _cabeza::draw_fill() {
    glMatrixMode(GL_MODELVIEW) ;

    glColor3fv((GLfloat *) &GRAY) ;
    cylinder.draw_fill() ;

    glPushMatrix() ;
        glTranslatef(-0.21, 0.3, 0) ;
        ojo.draw_fill() ;
    glPopMatrix() ;

    glPushMatrix() ;
        glTranslatef(0.21, 0.3, 0) ;
        glPushMatrix() ;
            glRotatef(270, 0, 0, 1) ;
            ojo.draw_fill() ;
        glPopMatrix() ;
    glPopMatrix() ;
}



