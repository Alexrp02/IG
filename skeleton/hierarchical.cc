/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "hierarchical.h"
#include<cmath>



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_hierarchical::_hierarchical()
{

}

void _hierarchical::draw_fill() {
    glMatrixMode(GL_MODELVIEW) ;
    glLoadIdentity() ;
    glPushMatrix() ;
    glRotatef(10,0,0.01,0) ;
    Cube.draw_fill() ;
    glPopMatrix() ;
}

