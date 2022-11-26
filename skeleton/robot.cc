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

void _robot::draw(string mode) {
    glMatrixMode(GL_MODELVIEW) ;

    //Cuerpo
    cuerpo.draw(mode) ;

    //Cabeza
    glPushMatrix() ;
        glTranslatef(0, 0.375, 0) ;
        glScalef(0.8, 0.8, 0.8) ;
        cabeza.draw(mode) ;
    glPopMatrix() ;

    //Brazo derecho
    glPushMatrix() ;
    glTranslatef(0.375, 0.350, 0) ;
    glPushMatrix() ;
        glScalef(0.4, 0.5, 0.5) ;
        brazo.draw(mode) ;
    glPopMatrix() ;
    glPopMatrix() ;

    //Brazo izquierdo
    glPushMatrix() ;
    glTranslatef(-0.475, 0.350, 0) ;
    glPushMatrix() ;
        glScalef(0.4, 0.5, 0.5) ;
        brazo.draw(mode) ;
    glPopMatrix() ;
    glPopMatrix() ;

    glPushMatrix() ;
        glTranslatef(-0.375, -0.25, 0) ;
        glPushMatrix() ;
            glScalef(0.5, 0.5, 0.5) ;
            rueda.draw(mode) ;
        glPopMatrix() ;
    glPopMatrix() ;

    glPushMatrix() ;
        glTranslatef(0.375, -0.25, 0) ;
        glRotatef(180, 0, 0, 1) ;
        glPushMatrix() ;
            glScalef(0.5, 0.5, 0.5) ;
            rueda.draw(mode) ;
        glPopMatrix() ;
    glPopMatrix() ;

}



