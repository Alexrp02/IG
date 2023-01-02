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
//    glEnable(GL_COLOR_MATERIAL);
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
    GLfloat material_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat material_specular[] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat material_ambient[] = {0.5, 0.5, 0.5, 1} ;
    GLfloat material_emission[] = {0, 0, 0, 1} ;
    GLfloat material_shininess = 0;
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT, GL_EMISSION, material_emission);
    glMaterialf(GL_FRONT, GL_SHININESS, material_shininess);
    glTranslatef(0.375, 0.350, 0) ;
    glPushMatrix() ;
        glScalef(0.4, 0.5, 0.5) ;
        brazo.draw(mode) ;
    glPopMatrix() ;
    glPopMatrix() ;

    //Brazo izquierdo
    glPushMatrix() ;
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT, GL_EMISSION, material_emission);
    glMaterialf(GL_FRONT, GL_SHININESS, material_shininess);
    glTranslatef(-0.475, 0.350, 0) ;
    glPushMatrix() ;
        glScalef(0.4, 0.5, 0.5) ;
        brazo.draw(mode) ;
    glPopMatrix() ;
    glPopMatrix() ;

    GLfloat material_diffuse2[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat material_specular2[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat material_ambient2[] = {0.5, 0.5, 0.5, 1} ;
    GLfloat material_emission2[] = {0, 0, 0, 1} ;
    GLfloat material_shininess2 = 64;
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse2);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular2);
    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient2);
    glMaterialfv(GL_FRONT, GL_EMISSION, material_emission2);
    glMaterialf(GL_FRONT, GL_SHININESS, material_shininess2);
    //Rueda derecha
    glPushMatrix() ;
        glTranslatef(-0.375, -0.25, 0) ;
        glPushMatrix() ;
            glScalef(0.5, 0.5, 0.5) ;
            rueda.draw(mode) ;
        glPopMatrix() ;
    glPopMatrix() ;

    //Rueda izquierda
    glPushMatrix() ;
        glTranslatef(0.375, -0.25, 0) ;
        glRotatef(180, 0, 0, 1) ;
        glPushMatrix() ;
            glScalef(0.5, 0.5, 0.5) ;
            rueda.draw(mode) ;
        glPopMatrix() ;
    glPopMatrix() ;
    glDisable(GL_COLOR_MATERIAL);
}



