/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "dashboard.h"
#include <GL/gl.h>


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_dashboard::_dashboard(int iterations)
{
    texture_name = "../textures/mapamundi.jpg" ;
    Vertices.resize((iterations+1)*(iterations+1)) ;
    Triangles.resize(iterations*iterations*2) ;
    faceNormals.resize(Vertices.size()) ;
    pointNormals.resize(Vertices.size()) ;
    numberOfNormals.resize(Vertices.size()) ;

    int pos = 0 ;
    for (int i=0 ; i<iterations+1 ; i++) {
        for (int j=0 ; j<iterations+1 ; j++) {
            float x = -0.5+((float)1/iterations)*j;
            float y = -0.5+((float)1/iterations)*i;
            Vertices[pos] = _vertex3f(x, y, 0) ;
            pos++ ;
        }
    }

    pos = 0 ;
    for (int j=0 ; j<iterations ; j++) {
        for (int i=0 ; i<iterations ; i++) {
            int x = i+(iterations+1)*j ;
            int y = x+1 ;
            int z = (iterations+1)*(j+1)+i;
            Triangles[pos] = _vertex3ui(x,y,z) ;
            pos++;
            Triangles[pos] = _vertex3ui(x+1,y+3,z) ;
            pos ++ ;
        }
    }

//    Vertices[0] = _vertex3f(-0.5,-0.5,0) ;
//    Vertices[1] = _vertex3f(0.5,-0.5,0) ;
//    Vertices[2] = _vertex3f(-0.5,0.5,0) ;
//    Vertices[3] = _vertex3f(0.5,0.5,0) ;

//    Triangles[0] = _vertex3ui(0,1,2) ;
//    Triangles[1] = _vertex3ui(1,3,2) ;

//    Edges[0] = _vertex2i(0,1) ;
//    Edges[1] = _vertex2i(1,3) ;
//    Edges[2] = _vertex2i(3,2) ;
//    Edges[3] = _vertex2i(2,0) ;

    for (int i=0 ; i<Triangles.size() ; i++) {
        faceNormals[i] = calculate_normalized_normal(Vertices[Triangles[i].x], Vertices[Triangles[i].y], Vertices[Triangles[i].z]) ;
    }


    for (int i=0 ; i<Triangles.size() ; i++) {
        pointNormals[Triangles[i].x] += faceNormals[i] ;
        pointNormals[Triangles[i].y] += faceNormals[i] ;
        pointNormals[Triangles[i].z] += faceNormals[i] ;
        numberOfNormals[Triangles[i].x] += 1;
        numberOfNormals[Triangles[i].y] += 1;
        numberOfNormals[Triangles[i].z] += 1;
    }


}

void _dashboard::draw_fill() {
    int Vertex_1,Vertex_2,Vertex_3;
//    std::cout << "Texture ID in function is:" << textureID << endl;
//    std::cout << "The image width in function is: " << Image.width() << endl ;
//    glDisable(GL_LIGHTING) ;
    glBindTexture(GL_TEXTURE_2D, textureID);
//    glEnable(GL_TEXTURE_2D) ;
    glEnable(GL_LIGHTING) ;

    GLfloat material_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat material_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat material_specular[] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat material_shininess[] = { 50.0 };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, material_shininess);

    glPolygonMode(GL_FRONT, GL_FILL) ;
    glBegin(GL_TRIANGLES) ;
//    glColor3fv((GLfloat *) &_colors_ne::WHITE) ;
    for(unsigned int i=0 ; i<Triangles.size() ; i++) {
        Vertex_1 = Triangles[i]._0  ;
        Vertex_2 = Triangles[i]._1  ;
        Vertex_3 = Triangles[i]._2  ;
        glNormal3f(faceNormals[i].x, faceNormals[i].y, faceNormals[i].z) ;

        glTexCoord2f(Vertices[Vertex_1].x+0.5, Vertices[Vertex_1].y+0.5) ;
        glNormal3f(pointNormals[Vertex_1].x, pointNormals[Vertex_1].y, pointNormals[Vertex_1].z) ;
        glVertex3f(Vertices[Vertex_1].x, Vertices[Vertex_1].y, Vertices[Vertex_1].z);

        glTexCoord2f(Vertices[Vertex_2].x+0.5, Vertices[Vertex_2].y+0.5) ;
        glNormal3f(pointNormals[Vertex_2].x, pointNormals[Vertex_2].y, pointNormals[Vertex_2].z) ;
        glVertex3f(Vertices[Vertex_2].x, Vertices[Vertex_2].y, Vertices[Vertex_2].z);

        glTexCoord2f(Vertices[Vertex_3].x+0.5, Vertices[Vertex_3].y+0.5) ;
        glNormal3f(pointNormals[Vertex_3].x, pointNormals[Vertex_3].y, pointNormals[Vertex_3].z) ;
        glVertex3f(Vertices[Vertex_3].x, Vertices[Vertex_3].y, Vertices[Vertex_3].z);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D) ;
//    glEnable(GL_LIGHTING) ;
}

void _dashboard::draw_line() {
    int Vertex_1,Vertex_2,Vertex_3;

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) ;
    glDisable(GL_LIGHTING) ;
    glBegin(GL_TRIANGLES) ;
    for(unsigned int i=0 ; i<Triangles.size() ; i++) {
        Vertex_1 = Triangles[i]._0  ;
        Vertex_2 = Triangles[i]._1  ;
        Vertex_3 = Triangles[i]._2  ;
        glVertex3f(Vertices[Vertex_1].x, Vertices[Vertex_1].y, Vertices[Vertex_1].z);
        glVertex3f(Vertices[Vertex_2].x, Vertices[Vertex_2].y, Vertices[Vertex_2].z);
        glVertex3f(Vertices[Vertex_3].x, Vertices[Vertex_3].y, Vertices[Vertex_3].z);
    }
    glEnd();
    glEnable(GL_LIGHTING) ;
}
