/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "cuerpo.h"
#include<cmath>

using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_cuerpo::_cuerpo()
{
}

void _cuerpo::draw(string mode) {
    glMatrixMode(GL_MODELVIEW) ;

    glPushMatrix() ;
        glScalef(0.75, 0.75, 0.75) ;
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
    glPopMatrix() ;
}



