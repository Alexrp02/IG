/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "robot.h"
#include<cmath>

using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_robot::_robot()
{
}

void _robot::draw_fill() {
    glMatrixMode(GL_MODELVIEW) ;

    //Cuerpo
    cuerpo.draw_fill() ;

    //Cabeza
    glPushMatrix() ;
        glTranslatef(0, 0.375, 0) ;
        glScalef(0.8, 0.8, 0.8) ;
        cabeza.draw_fill() ;
    glPopMatrix() ;
\
    //Brazo derecho
    glPushMatrix() ;
    glTranslatef(0.375, 0.350, 0) ;
    glPushMatrix() ;
        glScalef(0.4, 0.5, 0.5) ;
        brazo.draw_fill() ;
    glPopMatrix() ;
    glPopMatrix() ;

    //Brazo izquierdo
    glPushMatrix() ;
    glTranslatef(-0.375, 0.350, 0) ;
    glPushMatrix() ;
        glScalef(0.4, 0.5, 0.5) ;
        glRotatef(180, 0, 0, 1) ;
        brazo.draw_fill() ;
    glPopMatrix() ;
    glPopMatrix() ;

    glPushMatrix() ;
        glTranslatef(-0.375, -0.25, 0) ;
        glPushMatrix() ;
            glScalef(0.5, 0.5, 0.5) ;
            rueda.draw_fill() ;
        glPopMatrix() ;
    glPopMatrix() ;

    glPushMatrix() ;
        glTranslatef(0.375, -0.25, 0) ;
        glRotatef(180, 0, 0, 1) ;
        glPushMatrix() ;
            glScalef(0.5, 0.5, 0.5) ;
            rueda.draw_fill() ;
        glPopMatrix() ;
    glPopMatrix() ;

}



