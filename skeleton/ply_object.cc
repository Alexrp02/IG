/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "ply_object.h"


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
    Triangles.resize(Positions.size()/3) ;
    for (unsigned int i=0 ; i<Coordinates.size() ; i+=3) {
        Vertices[i/3] = _vertex3f(Coordinates[i] , Coordinates[i+1], Coordinates[i+2]) ;
    }

    for (unsigned int i=0 ; i<Positions.size() ; i+=3){
        Triangles[i/3] = _vertex3ui(Positions[i] , Positions[i+1], Positions[i+2]) ;
    }

    Edges.resize(Triangles.size()*3) ;

    int pos = 0 ;
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

