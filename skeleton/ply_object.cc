/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "ply_object.h"

#include "object3d.h"

using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_ply_object::_ply_object(const string &file_name)
{
    reader.open(file_name) ;
    reader.read(Coordinates,Positions) ;
    reader.close() ;
    Vertices.resize(Coordinates.size()/3) ;
    faceNormals.resize(Positions.size()/3) ;
    Triangles.resize(Positions.size()/3) ;
    for (unsigned int i=0 ; i<Coordinates.size() ; i+=3) {
        Vertices[i/3] = _vertex3f(Coordinates[i] , Coordinates[i+1], Coordinates[i+2]) ;
    }

    for (unsigned int i=0 ; i<Positions.size() ; i+=3){
        faceNormals[i/3] = calculate_normalized_normal(Vertices[Positions[i]], Vertices[Positions[i+1]], Vertices[Positions[i+2]]) ;
        Triangles[i/3] = _vertex3ui(Positions[i] , Positions[i+1], Positions[i+2]) ;
    }

//    Edges.resize(Triangles.size()*3) ;

//    int pos = 0 ;
//    for (unsigned int i=0 ; i<Triangles.size() ; i++) {
//        Edges[pos]._0 = Triangles[i]._0;
//        Edges[pos]._1 = Triangles[i]._1 ;
//        pos++ ;
//        Edges[pos]._0 = Triangles[i]._1;
//        Edges[pos]._1 = Triangles[i]._2 ;
//        pos++ ;
//        Edges[pos]._0 = Triangles[i]._2;
//        Edges[pos]._1 = Triangles[i]._0 ;
//        pos++ ;
//    }

}

void _ply_object::draw_line() {
    int Vertex_1,Vertex_2,Vertex_3;

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) ;
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
}

