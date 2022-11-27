/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "object3d.h"
#include<cmath>

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
    glColor3fv(color) ;
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
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL) ;
  glBegin(GL_TRIANGLES) ;
  for(unsigned int i=0 ; i<Triangles.size() ; i++) {
      Vertex_1 = Triangles[i]._0  ;
      Vertex_2 = Triangles[i]._1  ;
      Vertex_3 = Triangles[i]._2  ;
      glNormal3f(faceNormals[i].x, faceNormals[i].y, faceNormals[i].z) ;
      glMaterialf(GL_FRONT_FACE,GL_SHININESS, 1) ;
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
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL) ;
    glBegin(GL_TRIANGLES) ;
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

_vertex3f _object3D::calculate_normalized_normal(_vertex3f v1, _vertex3f v2, _vertex3f v3) {
    _vertex3f vertex1 = _vertex3f(v2.x-v1.x, v2.y-v1.y, v2.z-v1.z);
    _vertex3f vertex2 = _vertex3f(v3.x-v1.x, v3.y-v1.y, v3.z-v1.z);
    float x = vertex1.y*vertex2.z - vertex1.z*vertex2.y ;
    float y = -vertex1.x*vertex2.z + vertex1.z*vertex2.x ;
    float z = vertex1.x*vertex2.y - vertex1.y*vertex2.x ;
    _vertex3f sol = _vertex3f(x,y,z);
    float module = calculate_module(sol) ;

    sol.x = sol.x/module ;
    sol.y = sol.y/module ;
    sol.z = sol.z/module ;
    return sol ;
}

float _object3D::calculate_module(_vertex3f v) {
    return (sqrt(pow(v.x, 2) + pow(v.y,2) + pow(v.z,2))) ;
}
