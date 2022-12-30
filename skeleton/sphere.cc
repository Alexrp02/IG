/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "sphere.h"
#include<cmath>



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_sphere::_sphere(int n, float r, int revolutions)
{
    texture_name = "../textures/mundo.jpg" ;

    //    Vertices.resize((n-2)*revolutions + 2) ;
    Vertices.resize(n*(revolutions+1)) ;
    textureX.resize(Vertices.size()) ;
    int pos=0 ;
    float textXCoord = 0 ;
    //    for (int j=0 ; j<revolutions ; j++) {
    //        textXCoord = j/revolutions;
    //        for (int i=1 ; i<n-1 ; i++) {
    //            float x = cos(3*M_PI/2 + M_PI*i/(n-1))*r ;
    //            float y = sin(3*M_PI/2 + M_PI*i/(n-1))*r ;

    //            Vertices[pos] = _vertex3f( x*( cos((2*M_PI/revolutions)*j) ) , y, x*( sin((2*M_PI/revolutions)*j) )) ;
    //            textureX[pos] = textXCoord ;
    //            pos++ ;
    //        }
    //    }

    for (int j=0 ; j<revolutions+1 ; j++) {
        float angle = 2 * M_PI * j / revolutions;
        textXCoord = angle / (2 * M_PI);
        for (int i=0 ; i<n ; i++) {
            float x = cos(3*M_PI/2 + M_PI*i/(n-1))*r ;
            float y = sin(3*M_PI/2 + M_PI*i/(n-1))*r ;

            Vertices[pos] = _vertex3f( x*( cos((2*M_PI/revolutions)*j) ) , y, x*( sin((2*M_PI/revolutions)*j) )) ;
            textureX[pos] = textXCoord ;
            pos++ ;
        }
    }

    //    Vertices[pos] = _vertex3f(0,r,0) ;
    //    pos++ ;
    //    Vertices[pos] = _vertex3f(0,-r,0) ;

    //(n-1)*2*revolutions
    Triangles.resize(revolutions*(2+(n-3)*2)) ;
    faceNormals.resize(revolutions*(2+(n-3)*2)) ;
    pointNormals.resize(Vertices.size()) ;
    numberOfNormals.resize(Vertices.size()) ;
    //Lateral
    pos=0 ;
    //    for (int i=0 ; i<n-3 ; i++) {
    //        for (int j=0 ; j<revolutions ; j++) {
    //            int v1 = ((n-2)*j+i)%((n-2)*revolutions);
    //            int v2 = ((n-2)*(1+j)+i)%((n-2)*revolutions) ;
    //            int v3 = (1+(n-2)*j+i)%((n-2)*revolutions) ;

    //            Triangles[pos] = _vertex3ui(v1, v2, v3) ;
    //            faceNormals[pos] = calculate_normalized_normal(Vertices[v3], Vertices[v2], Vertices[v1]) ;
    //            pointNormals[v1].x += faceNormals[pos].x ;
    //            pointNormals[v1].y += faceNormals[pos].y ;
    //            pointNormals[v1].z += faceNormals[pos].z ;
    //            numberOfNormals[v1] += 1 ;

    //            pointNormals[v2].x += faceNormals[pos].x ;
    //            pointNormals[v2].y += faceNormals[pos].y ;
    //            pointNormals[v2].z += faceNormals[pos].z ;
    //            numberOfNormals[v2] += 1 ;

    //            pointNormals[v3].x += faceNormals[pos].x ;
    //            pointNormals[v3].y += faceNormals[pos].y ;
    //            pointNormals[v3].z += faceNormals[pos].z ;
    //            numberOfNormals[v3] += 1 ;
    //            pos++ ;

    //            Triangles[pos] = _vertex3ui((v1+(n-2))%((n-2)*revolutions), (v2+1)%((n-2)*revolutions), v3) ;
    //            faceNormals[pos] = calculate_normalized_normal(Vertices[v3], Vertices[(v2+1)%((n-2)*revolutions)], Vertices[(v1+(n-2))%((n-2)*revolutions)]) ;
    //            pointNormals[v1].x += faceNormals[pos].x ;
    //            pointNormals[v1].y += faceNormals[pos].y ;
    //            pointNormals[v1].z += faceNormals[pos].z ;
    //            numberOfNormals[v1] += 1 ;

    //            pointNormals[v2].x += faceNormals[pos].x ;
    //            pointNormals[v2].y += faceNormals[pos].y ;
    //            pointNormals[v2].z += faceNormals[pos].z ;
    //            numberOfNormals[v2] += 1 ;

    //            pointNormals[v3].x += faceNormals[pos].x ;
    //            pointNormals[v3].y += faceNormals[pos].y ;
    //            pointNormals[v3].z += faceNormals[pos].z ;
    //            numberOfNormals[v3] += 1 ;
    //            pos++ ;
    //        }
    //    }

    for (int i=0 ; i<n-3 ; i++) {
        for (int j=0 ; j<revolutions ; j++) {
            int v1 = (n*j+i+1);
            int v2 = (n*(1+j)+i+1) ;
            int v3 = (2+n*j+i);

            Triangles[pos] = _vertex3ui(v1, v2, v3) ;
            faceNormals[pos] = calculate_normalized_normal(Vertices[v3], Vertices[v2], Vertices[v1]) ;
            pointNormals[v1].x += faceNormals[pos].x ;
            pointNormals[v1].y += faceNormals[pos].y ;
            pointNormals[v1].z += faceNormals[pos].z ;
            numberOfNormals[v1] += 1 ;

            pointNormals[v2].x += faceNormals[pos].x ;
            pointNormals[v2].y += faceNormals[pos].y ;
            pointNormals[v2].z += faceNormals[pos].z ;
            numberOfNormals[v2] += 1 ;

            pointNormals[v3].x += faceNormals[pos].x ;
            pointNormals[v3].y += faceNormals[pos].y ;
            pointNormals[v3].z += faceNormals[pos].z ;
            numberOfNormals[v3] += 1 ;
            pos++ ;

            Triangles[pos] = _vertex3ui(v1+n, v2+1, v3) ;
            faceNormals[pos] = calculate_normalized_normal(Vertices[v3], Vertices[(v2+1)%(n*revolutions)], Vertices[(v1+n)%(n*revolutions)]) ;
            pointNormals[v1].x += faceNormals[pos].x ;
            pointNormals[v1].y += faceNormals[pos].y ;
            pointNormals[v1].z += faceNormals[pos].z ;
            numberOfNormals[v1] += 1 ;

            pointNormals[v2].x += faceNormals[pos].x ;
            pointNormals[v2].y += faceNormals[pos].y ;
            pointNormals[v2].z += faceNormals[pos].z ;
            numberOfNormals[v2] += 1 ;

            pointNormals[v3].x += faceNormals[pos].x ;
            pointNormals[v3].y += faceNormals[pos].y ;
            pointNormals[v3].z += faceNormals[pos].z ;
            numberOfNormals[v3] += 1 ;
            pos++ ;
        }
    }


    //    //Cubierta superior
    //    for (int i=0 ; i<revolutions ; i++) {
    //        int v1 = Vertices.size()-2;
    //        int v2 = ((n-3)+(n-2)*(i+1))%((n-2)*revolutions) ;
    //        int v3 = ((n-3)+(n-2)*i)%((n-2)*revolutions) ;
    //        faceNormals[pos] = calculate_normalized_normal(Vertices[v1], Vertices[v2], Vertices[v3]) ;
    //        pointNormals[v1].x += faceNormals[pos].x ;
    //        pointNormals[v1].y += faceNormals[pos].y ;
    //        pointNormals[v1].z += faceNormals[pos].z ;
    //        numberOfNormals[v1] += 1 ;

    //        pointNormals[v2].x += faceNormals[pos].x ;
    //        pointNormals[v2].y += faceNormals[pos].y ;
    //        pointNormals[v2].z += faceNormals[pos].z ;
    //        numberOfNormals[v2] += 1 ;

    //        pointNormals[v3].x += faceNormals[pos].x ;
    //        pointNormals[v3].y += faceNormals[pos].y ;
    //        pointNormals[v3].z += faceNormals[pos].z ;
    //        numberOfNormals[v3] += 1 ;
    //        Triangles[pos] = _vertex3ui(v3, v2, v1) ;
    //        pos++ ;
    //    }
    //Cubierta superior
    for (int i=0 ; i<revolutions ; i++) {
        int v1 = (n-2)+n*i;
        int v2 = ((n-2)+n*(i+1)) ;
        int v3 = (n*(i+1)-1) ;
        faceNormals[pos] = calculate_normalized_normal(Vertices[v1], Vertices[v2], Vertices[v3]) ;
        pointNormals[v1].x += faceNormals[pos].x ;
        pointNormals[v1].y += faceNormals[pos].y ;
        pointNormals[v1].z += faceNormals[pos].z ;
        numberOfNormals[v1] += 1 ;

        pointNormals[v2].x += faceNormals[pos].x ;
        pointNormals[v2].y += faceNormals[pos].y ;
        pointNormals[v2].z += faceNormals[pos].z ;
        numberOfNormals[v2] += 1 ;

        pointNormals[v3].x += faceNormals[pos].x ;
        pointNormals[v3].y += faceNormals[pos].y ;
        pointNormals[v3].z += faceNormals[pos].z ;
        numberOfNormals[v3] += 1 ;
        Triangles[pos] = _vertex3ui(v1, v2, v3) ;
        pos++ ;
    }
    //    //Cubierta inferior
    //    for (int i=0 ; i<revolutions ; i++) {
    //        int v1 = ((n-2)*i)%((n-2)*revolutions) ;
    //        int v2 = ((n-2)*(i+1))%((n-2)*revolutions) ;
    //        int v3 = Vertices.size()-1 ;
    //        faceNormals[pos] = calculate_normalized_normal(Vertices[v1], Vertices[v2], Vertices[v3]) ;
    //        pointNormals[v1].x += faceNormals[pos].x ;
    //        pointNormals[v1].y += faceNormals[pos].y ;
    //        pointNormals[v1].z += faceNormals[pos].z ;
    //        numberOfNormals[v1] += 1 ;

    //        pointNormals[v2].x += faceNormals[pos].x ;
    //        pointNormals[v2].y += faceNormals[pos].y ;
    //        pointNormals[v2].z += faceNormals[pos].z ;
    //        numberOfNormals[v2] += 1 ;

    //        pointNormals[v3].x += faceNormals[pos].x ;
    //        pointNormals[v3].y += faceNormals[pos].y ;
    //        pointNormals[v3].z += faceNormals[pos].z ;
    //        numberOfNormals[v3] += 1 ;

    //        Triangles[pos] = _vertex3ui(v1, v2, v3) ;
    //        pos++ ;
    //    }
    //Cubierta inferior
    for (int i=0 ; i<revolutions ; i++) {
        int v1 = (n*(i+1)) ;
        int v2 = (n*(i+1)+1) ;
        int v3 = 1+n*i ;
        faceNormals[pos] = calculate_normalized_normal(Vertices[v1], Vertices[v2], Vertices[v3]) ;
        pointNormals[v1].x += faceNormals[pos].x ;
        pointNormals[v1].y += faceNormals[pos].y ;
        pointNormals[v1].z += faceNormals[pos].z ;
        numberOfNormals[v1] += 1 ;

        pointNormals[v2].x += faceNormals[pos].x ;
        pointNormals[v2].y += faceNormals[pos].y ;
        pointNormals[v2].z += faceNormals[pos].z ;
        numberOfNormals[v2] += 1 ;

        pointNormals[v3].x += faceNormals[pos].x ;
        pointNormals[v3].y += faceNormals[pos].y ;
        pointNormals[v3].z += faceNormals[pos].z ;
        numberOfNormals[v3] += 1 ;

        Triangles[pos] = _vertex3ui(v1, v2, v3) ;
        pos++ ;
    }
    averageNormal() ;

    Edges.resize(Triangles.size()*3) ;

    pos = 0 ;
    for (unsigned int i=0 ; i<Triangles.size() ; i++) {
        Edges[pos]._0 = Triangles[i]._0;
        Edges[pos]._1 = Triangles[i]._1 ;
        pos++ ;
        Edges[pos]._0 = Triangles[i]._1;
        Edges[pos]._1 = Triangles[i]._2 ;
        pos++ ;
        Edges[pos]._0 = Triangles[i]._2;
        Edges[pos]._1 = Triangles[i]._0 ;
        pos++ ;
    }


}

void _sphere::draw_fill() {
    int Vertex_1,Vertex_2,Vertex_3;
    //    GLfloat material_diffuse[] = { 1, 1, 1, 1.0 };
    //    GLfloat material_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    //    GLfloat material_specular[] = { 0.5, 0.5, 0.5, 1.0 };
    //    GLfloat material_shininess[] = { 50.0 };

    //    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
    //    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    //    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    //    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);
    glBindTexture(GL_TEXTURE_2D, textureID);
    //    glEnable(GL_LIGHTING) ;
    glDisable(GL_LIGHTING) ;
    glEnable(GL_TEXTURE_2D) ;

    glPolygonMode(GL_FRONT, GL_FILL) ;
    glColor3fv((GLfloat *) &_colors_ne::WHITE) ;
    glBegin(GL_TRIANGLES) ;
    for(unsigned int i=0 ; i<Triangles.size() ; i++) {
        Vertex_1 = Triangles[i]._0  ;
        Vertex_2 = Triangles[i]._1  ;
        Vertex_3 = Triangles[i]._2  ;
        glNormal3f(faceNormals[i].x, faceNormals[i].y, faceNormals[i].z) ;

        glNormal3f(pointNormals[Vertex_1].x, pointNormals[Vertex_1].y, pointNormals[Vertex_1].z) ;
        glTexCoord2f(textureX[Vertex_1], (Vertices[Vertex_1].y+1)/2) ;
        glVertex3f(Vertices[Vertex_1].x, Vertices[Vertex_1].y, Vertices[Vertex_1].z);

        glNormal3f(pointNormals[Vertex_2].x, pointNormals[Vertex_2].y, pointNormals[Vertex_2].z) ;
        glTexCoord2f(textureX[Vertex_2], (Vertices[Vertex_2].y+1)/2) ;
        glVertex3f(Vertices[Vertex_2].x, Vertices[Vertex_2].y, Vertices[Vertex_2].z);

        glNormal3f(pointNormals[Vertex_3].x, pointNormals[Vertex_3].y, pointNormals[Vertex_3].z) ;
        glTexCoord2f(textureX[Vertex_3], (Vertices[Vertex_3].y+1)/2) ;
        glVertex3f(Vertices[Vertex_3].x, Vertices[Vertex_3].y, Vertices[Vertex_3].z);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D) ;
}

