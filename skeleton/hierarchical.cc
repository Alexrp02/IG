/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "hierarchical.h"
#include "cube.h"
#include<cmath>
#include <QTimer>



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_hierarchical::_hierarchical()
{
    x=0;
}

void _hierarchical::patadraw() {

}

void _hierarchical::draw_fill() {
    glMatrixMode(GL_MODELVIEW) ;
    glPushMatrix();
    glScalef(0.5,0.1,0.1) ;
    glTranslatef(0.25,0,0) ;
    cube.draw_chess();
    glPopMatrix();

    glPushMatrix() ;
    glTranslatef(0.5,-0.14,0) ;
    glPushMatrix();
    glRotatef(/*-35*/x,0,0,1) ;
    glScalef(0.5,0.1,0.1) ;
    glTranslatef(0,0,0) ;
    cube.draw_chess() ;
    glPopMatrix() ;
    glPopMatrix();
}



