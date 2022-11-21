/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "rueda.h"
#include<cmath>

using namespace _colors_ne;



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_rueda::_rueda()
{
}

void _rueda::draw_fill() {
    glMatrixMode(GL_MODELVIEW) ;


    glPushMatrix() ;
    glTranslatef(-0.28, 0, 0);
    glPushMatrix() ;
        glRotatef(90,0,0,1) ;
        glColor3fv((GLfloat *) &BLACK) ;
        cylinder.draw_fill() ;

        glPushMatrix() ;
            glScalef(0.2, 2, 0.2) ;
            glTranslatef(0,-0.04,0) ;
            glColor3fv((GLfloat *) &GRAY) ;
            cylinder.draw_fill() ;
        glPopMatrix();
    glPopMatrix();
    glPopMatrix() ;
}



