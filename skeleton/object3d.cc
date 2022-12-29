/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "object3d.h"
#include "qimagereader.h"
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
    glDisable(GL_LIGHTING) ;
    glBegin(GL_LINES) ;
    for (unsigned int i = 0; i < Edges.size(); i++) {
        Vertex1 = Edges[i]._0 ;
        Vertex2 = Edges[i]._1 ;
        glVertex3f(Vertices[Vertex1].x, Vertices[Vertex1].y, Vertices[Vertex1].z);
        glVertex3f(Vertices[Vertex2].x, Vertices[Vertex2].y, Vertices[Vertex2].z);
    }
    glEnd();
    glEnable(GL_LIGHTING) ;
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
//  // Set the material properties
//  GLfloat mat_ambient[] = {0.7, 0.7, 0.7, 1.0};
//  GLfloat mat_diffuse[] = {0.8, 0.8, 0.8, 1.0};
//  GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
//  GLfloat mat_shininess[] = {128.0};

//  // Set the material properties for the front face
//  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
//  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
//  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//  glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
  glBegin(GL_TRIANGLES) ;
//  glColor3fv((GLfloat *) &WHITE) ;
  for(unsigned int i=0 ; i<Triangles.size() ; i++) {
      Vertex_1 = Triangles[i]._0  ;
      Vertex_2 = Triangles[i]._1  ;
      Vertex_3 = Triangles[i]._2  ;
      glNormal3f(faceNormals[i].x, faceNormals[i].y, faceNormals[i].z) ;

      glNormal3f(pointNormals[Vertex_1].x, pointNormals[Vertex_1].y, pointNormals[Vertex_1].z) ;
      glVertex3f(Vertices[Vertex_1].x, Vertices[Vertex_1].y, Vertices[Vertex_1].z);
      glNormal3f(pointNormals[Vertex_2].x, pointNormals[Vertex_2].y, pointNormals[Vertex_2].z) ;
      glVertex3f(Vertices[Vertex_2].x, Vertices[Vertex_2].y, Vertices[Vertex_2].z);
      glNormal3f(pointNormals[Vertex_3].x, pointNormals[Vertex_3].y, pointNormals[Vertex_3].z) ;
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
    glDisable(GL_LIGHTING) ;
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
    glEnable(GL_LIGHTING) ;
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

void _object3D::averageNormal () {
    for (int i=0 ; i< pointNormals.size() ; i++) {
        pointNormals[i].x /= numberOfNormals[i];
        pointNormals[i].y /= numberOfNormals[i] ;
        pointNormals[i].z /= numberOfNormals[i] ;
    }
}

void _object3D::read_texture (QString texture_name) {
    QImageReader Reader(texture_name);
    Reader.setAutoTransform(true);
    Image = Reader.read();
    if (Image.isNull()) {
      std::cerr << "Couldn't load the image " + texture_name.toStdString() << endl ;
      exit(-1);
    }
    Image=Image.mirrored();
    Image=Image.convertToFormat(QImage::Format_RGB888);
    glBindTexture(GL_TEXTURE_2D, textureID);
    // Code to control the application of the texture
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    // Code to pass the image to OpenGL to form a texture 2D
    glTexImage2D(GL_TEXTURE_2D,0,3,Image.width(),Image.height(),0,GL_RGB,GL_UNSIGNED_BYTE,Image.bits());
}
