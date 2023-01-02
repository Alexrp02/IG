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
        GLfloat ambient_diffuse [] = {0.1,0.1,0.1,1};
        GLfloat specular [] = {0,0,0,0} ;
        glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE, ambient_diffuse) ;
        glMaterialfv(GL_FRONT,GL_SPECULAR, specular) ;
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
            GLfloat material_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
            GLfloat material_specular[] = { 0.5, 0.5, 0.5, 1.0 };
            GLfloat material_ambient[] = {0.2, 0.2, 0.2, 1} ;
            GLfloat material_emission[] = {0, 0, 0, 1} ;
            GLfloat material_shininess = 64;
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
    glPopMatrix() ;
}



