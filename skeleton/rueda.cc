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

void _rueda::draw(string mode) {
    glMatrixMode(GL_MODELVIEW) ;


    glPushMatrix() ;
    glTranslatef(-0.28, 0, 0);
    glPushMatrix() ;
        glRotatef(90,0,0,1) ;
        glColor3fv((GLfloat *) &BLACK) ;
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
            glScalef(0.2, 2, 0.2) ;
            glTranslatef(0,-0.04,0) ;
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
        glPopMatrix();
    glPopMatrix();
    glPopMatrix() ;
}



