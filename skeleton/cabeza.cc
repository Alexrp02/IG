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
    rotacion = 0 ;
}

void _cabeza::draw(string mode) {
    glMatrixMode(GL_MODELVIEW) ;

    glPushMatrix();
    glRotatef(rotacion,0,1,0) ;
    glTranslatef(0, 0.25, 0) ;
    glColor3fv((GLfloat *) &GRAY) ;
    if(mode=="FILL"){
        cylinder.draw_fill() ;
    }else if(mode=="LINE"){
        cylinder.draw_line() ;
    }else if(mode=="CHESS"){
        cylinder.draw_chess() ;
    }else if (mode=="POINT"){
        cylinder.draw_point();
    }

    glPushMatrix() ;
        glTranslatef(-0.21, 0.3, 0) ;
        ojo.draw(mode) ;
    glPopMatrix() ;

    glPushMatrix() ;
        glTranslatef(0.21, 0.3, 0) ;
        glPushMatrix() ;
            glRotatef(270, 0, 0, 1) ;
            ojo.draw(mode) ;
        glPopMatrix() ;
    glPopMatrix() ;
    glPopMatrix() ;
}



