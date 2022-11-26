/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "mano.h"
#include<cmath>

using namespace _colors_ne;

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_mano::_mano()
{
    apertura = 40;
}

void _mano::draw(string mode) {
    glMatrixMode(GL_MODELVIEW) ;

    glPushMatrix() ;
        glScalef(0.1, 0.1, 0.1) ;
        glColor3fv((GLfloat *) &GRAY) ;
        if(mode=="FILL"){
            sphere.draw_fill() ;
        }else if(mode=="LINE"){
            sphere.draw_line() ;
        }else if(mode=="CHESS"){
            sphere.draw_chess() ;
        }else if (mode=="POINT"){
            sphere.draw_point();
        }
    glPopMatrix() ;

    glPushMatrix() ;
        glRotatef(0, 0, 1, 0) ;
        glPushMatrix() ;
            glTranslatef(0.05, 0, 0) ;
            glRotatef(apertura, 0, 0, 1) ;
            dedo.draw(mode) ;
        glPopMatrix() ;
    glPopMatrix() ;

    glPushMatrix() ;
        glRotatef(120, 0, 1, 0) ;
        glPushMatrix() ;
            glTranslatef(0.05, 0, 0) ;
            glRotatef(apertura, 0, 0, 1) ;
            dedo.draw(mode) ;
        glPopMatrix() ;
    glPopMatrix() ;

    glPushMatrix() ;
        glRotatef(240, 0, 1, 0) ;
        glPushMatrix() ;
            glTranslatef(0.05, 0, 0) ;
            glRotatef(apertura, 0, 0, 1) ;
            dedo.draw(mode) ;
        glPopMatrix() ;
    glPopMatrix() ;
}



