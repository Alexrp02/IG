/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "dedo.h"
#include "cube.h"
#include<cmath>

using namespace _colors_ne;

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_dedo::_dedo()
{
    x = 0;
}

void _dedo::draw_fill() {
    glMatrixMode(GL_MODELVIEW) ;

    glPushMatrix () ;
//        glTranslatef(0, 0.05, 0) ;
        glRotatef(x, 0,0,1) ;
        glPushMatrix() ;
            glTranslatef(0.22, -0.05 ,0) ;
            glPushMatrix() ;
                glRotatef(35, 0, 0, 1) ;
            glPushMatrix() ;
                glTranslatef(0.125, 0.05, 0) ;
                glScalef(0.25, 0.1, 0.1) ;
                glColor3fv((GLfloat *) &GRAY) ;
                cube.draw_fill() ;
            glPopMatrix() ;
            glPopMatrix() ;
        glPopMatrix() ;

        glPushMatrix() ;
            glTranslatef(0.125, 0 ,0) ;
            glPushMatrix() ;
                glScalef(0.25, 0.1, 0.1) ;
                glColor3fv((GLfloat *) &GRAY) ;
                cube.draw_fill() ;
            glPopMatrix() ;
        glPopMatrix() ;
    glPopMatrix() ;
}



