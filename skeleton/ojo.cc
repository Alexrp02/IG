/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "ojo.h"
#include<cmath>

using namespace _colors_ne;



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_ojo::_ojo()
{
}

void _ojo::draw(string mode) {
    glMatrixMode(GL_MODELVIEW) ;

    glPushMatrix() ;
        glRotatef(90, 1, 0, 0) ;
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
    glPopMatrix() ;

    glPushMatrix() ;
        glTranslatef(0, 0, 0.01) ;
        glPushMatrix();
            glRotatef(90, 1, 0, 0) ;
            glScalef(0.7, 1, 0.7) ;
            glColor3fv((GLfloat *) &WHITE) ;
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

    glPushMatrix();
        glTranslatef(0.03, -0.03, 0.02) ;
        glPushMatrix() ;
            glRotatef(90, 1, 0, 0) ;
            glScalef(0.25, 1, 0.25) ;
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
        glPopMatrix();
    glPopMatrix();
}



