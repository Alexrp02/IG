/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "mano.h"
#include<cmath>



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_mano::_mano()
{
    apertura = 40;
}

void _mano::draw_fill() {
    glMatrixMode(GL_MODELVIEW) ;

    glPushMatrix() ;
        glScalef(0.1, 0.1, 0.1) ;
        sphere.draw_chess() ;
    glPopMatrix() ;

    glPushMatrix() ;
        glRotatef(0, 0, 1, 0) ;
        glPushMatrix() ;
            glTranslatef(0.05, 0, 0) ;
            glRotatef(apertura, 0, 0, 1) ;
            dedo.draw_fill();
        glPopMatrix() ;
    glPopMatrix() ;

    glPushMatrix() ;
        glRotatef(120, 0, 1, 0) ;
        glPushMatrix() ;
            glTranslatef(0.05, 0, 0) ;
            glRotatef(apertura, 0, 0, 1) ;
            dedo.draw_fill();
        glPopMatrix() ;
    glPopMatrix() ;

    glPushMatrix() ;
        glRotatef(240, 0, 1, 0) ;
        glPushMatrix() ;
            glTranslatef(0.05, 0, 0) ;
            glRotatef(apertura, 0, 0, 1) ;
            dedo.draw_fill();
        glPopMatrix() ;
    glPopMatrix() ;
}



