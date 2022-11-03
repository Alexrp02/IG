/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "object3d.h"

using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_line()
{
    int Vertex1;
    int Vertex2;
    glBegin(GL_LINES) ;
    for (unsigned int i = 0; i < Edges.size(); i++) {
        Vertex1 = Edges[i]._0 ;
        Vertex2 = Edges[i]._1 ;
        glVertex3f(Vertices[Vertex1].x, Vertices[Vertex1].y, Vertices[Vertex1].z);
        glVertex3f(Vertices[Vertex2].x, Vertices[Vertex2].y, Vertices[Vertex2].z);
    }
    glEnd();
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_fill()
{
  int Vertex_1,Vertex_2,Vertex_3;
  glBegin(GL_TRIANGLES) ;
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL) ;
  for(unsigned int i=0 ; i<Triangles.size() ; i++) {
      Vertex_1 = Triangles[i]._0  ;
      Vertex_2 = Triangles[i]._1  ;
      Vertex_3 = Triangles[i]._2  ;
      glVertex3f(Vertices[Vertex_1].x, Vertices[Vertex_1].y, Vertices[Vertex_1].z);
      glVertex3f(Vertices[Vertex_2].x, Vertices[Vertex_2].y, Vertices[Vertex_2].z);
      glVertex3f(Vertices[Vertex_3].x, Vertices[Vertex_3].y, Vertices[Vertex_3].z);
  }
  glEnd();
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_chess()
{
    int Vertex_1,Vertex_2,Vertex_3;
    bool color = true;
    glBegin(GL_TRIANGLES) ;
    glPolygonMode(GL_BACK, GL_FILL) ;
    for(unsigned int i=0 ; i<Triangles.size() ; i++) {
        color ? glColor3fv((GLfloat *) &RED) : glColor3fv((GLfloat *) &GREEN);
        Vertex_1 = Triangles[i]._0  ;
        Vertex_2 = Triangles[i]._1  ;
        Vertex_3 = Triangles[i]._2  ;
        glVertex3f(Vertices[Vertex_1].x, Vertices[Vertex_1].y, Vertices[Vertex_1].z);
        glVertex3f(Vertices[Vertex_2].x, Vertices[Vertex_2].y, Vertices[Vertex_2].z);
        glVertex3f(Vertices[Vertex_3].x, Vertices[Vertex_3].y, Vertices[Vertex_3].z);
        color = !color ;
    }
    glEnd();
}
