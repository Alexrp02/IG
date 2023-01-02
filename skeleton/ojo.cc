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
            GLfloat material_diffuse[] = { 1, 1, 1, 1.0 };
            GLfloat material_specular[] = { 0.2, 0.2, 0.2, 1.0 };
            GLfloat material_ambient[] = {0.5, 0.5, 0.5, 1} ;
            GLfloat material_emission[] = {0, 0, 0, 1} ;
            GLfloat material_shininess = 128;
            glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
            glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
            glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
            glMaterialfv(GL_FRONT, GL_EMISSION, material_emission);
            glMaterialf(GL_FRONT, GL_SHININESS, material_shininess);
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
            GLfloat material_diffuse2[] = { 0.8, 0.8, 0.8, 1.0 };
            GLfloat material_specular2[] = { 0.5, 0.5, 0.5, 1.0 };
            GLfloat material_ambient2[] = {0.2, 0.2, 0.2, 1} ;
            GLfloat material_emission2[] = {0, 0, 0, 1} ;
            GLfloat material_shininess2 = 64;
            glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse2);
            glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular2);
            glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient2);
            glMaterialfv(GL_FRONT, GL_EMISSION, material_emission2);
            glMaterialf(GL_FRONT, GL_SHININESS, material_shininess2);
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



