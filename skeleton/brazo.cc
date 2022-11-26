/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "brazo.h"
#include<cmath>

using namespace _colors_ne;

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_brazo::_brazo()
{
    angle = -30 ;
}

void _brazo::draw(string mode) {
    glMatrixMode(GL_MODELVIEW) ;

    glPushMatrix() ;
    glRotatef(angle, 1, 0, 0) ;
    glPushMatrix() ;
    glRotatef(-90, 0, 0, 1) ;
    glTranslatef(-0.125, 0.125, 0) ;
    glPushMatrix() ;
        glScalef(1, 0.25, 0.25) ;
        glTranslatef(0.5, 0, 0) ;
        glColor3fv((GLfloat *) &GRAY) ;
        if(mode=="FILL"){
            cube.draw_fill() ;
        }else if(mode=="LINE"){
            cube.draw_line() ;
        }else if(mode=="CHESS"){
            cube.draw_chess() ;
        }else if (mode=="POINT"){
            cube.draw_point();
        }
    glPopMatrix();

    glPushMatrix() ;
        glTranslatef(1, 0, 0) ;
        antebrazo.draw(mode) ;
    glPopMatrix();
    glPopMatrix() ;
    glPopMatrix() ;
}



