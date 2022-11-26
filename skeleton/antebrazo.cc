/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "antebrazo.h"
#include<cmath>

using namespace _colors_ne;

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_antebrazo::_antebrazo()
{
    translacion=0 ;
}

void _antebrazo::draw(string mode) {
    glMatrixMode(GL_MODELVIEW) ;

//    glPushMatrix() ;
//    glRotatef(45, 0, 0, 1) ;
    glPushMatrix() ;
        glTranslatef(translacion, 0 ,0)  ;
        glPushMatrix() ;
            glTranslatef(0.5 , 0, 0) ;
            glPushMatrix() ;
                glScalef(1, 0.15, 0.15) ;
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
        glPopMatrix() ;

        glPushMatrix() ;
            glTranslatef(1.05, 0 ,0) ;
            glRotatef(-90, 0, 0, 1) ;
            mano.draw(mode) ;
        glPopMatrix();
    glPopMatrix() ;
//    glPopMatrix() ;
}



