/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "cylinder.h"
#include<cmath>



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_cylinder::_cylinder(int n, float r, float h)
{
    Vertices.resize(n*2 + 2) ;

    int pos = 0 ;

    for (int i=0 ; i<n ; i++){
        //(2*M_PI/n)*i
//        Vertices[pos] = _vertex3f(0, 0, 0);
//        pos++ ;
        Vertices[pos] = _vertex3f((cos((2*M_PI/n)*i) )*r, -h/2, (sin((2*M_PI/n)*i))*r);
        pos++;
        Vertices[pos] = _vertex3f((cos((2*M_PI/n)*i) )*r, h/2, (sin((2*M_PI/n)*i))*r);
        pos++;
//        Vertices[pos] = _vertex3f(0, h, 0);
//        pos++;
    }
    Vertices[pos] = _vertex3f(0, h/2, 0);
    pos++;
    Vertices[pos] = _vertex3f(0, -h/2, 0);
    pos++ ;

    Triangles.resize(4*n) ;
    faceNormals.resize(4*n) ;
    pointNormals.resize(Vertices.size()) ;
    numberOfNormals.resize(Vertices.size()) ;

//    for(int i=0 ; i<2 ; i++) {
//        for (int j=0 ; j<n ; j++){
//            Triangles[pos] = _vertex3ui((j*3+i)%(3*n),(4+(3*j))%(3*n),(1+i+3*j)%(3*n));
//            pos++ ;
////            Triangles[pos] = _vertex3ui(((3+3*j)+i)%(3*n), ((4+3*j)+i)%(3*n), (1+i+3*j)%(3*n));
////            pos++;
//        }
//    }

    pos=0 ;
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<2 ; j++) {
            faceNormals[pos] = calculate_normalized_normal(Vertices[1+2*i], Vertices[(2*i+j+2)%(2*n)], Vertices[(2*i+j*2)%(2*n)]) ;
            int v1 = (2*i+j*2)%(2*n) ;
            int v2 = (2*i+j+2)%(2*n) ;
            int v3 = 1+2*i ;
            pointNormals[v1] += faceNormals[pos] ;
            numberOfNormals[v1] ++ ;

            pointNormals[v2] += faceNormals[pos] ;
            numberOfNormals[v2] ++ ;

            pointNormals[v3] += faceNormals[pos] ;
            numberOfNormals[v3] ++ ;

            Triangles[pos] = _vertex3ui(v1, v2, v3) ;
            pos++ ;
        }
    }

    for (int i=0 ; i<n ; i++) {
        faceNormals[pos] = calculate_normalized_normal(Vertices[Vertices.size()-2], Vertices[(2*i+3)%(n*2)], Vertices[i*2+1]) ;
        Triangles[pos] = _vertex3ui(i*2+1, (2*i+3)%(n*2), Vertices.size()-2) ;
        pos++ ;
    }
    for (int i=0 ; i<n ; i++) {
        faceNormals[pos] = calculate_normalized_normal(Vertices[i*2], Vertices[(i*2+2)%(n*2)], Vertices[Vertices.size()-1]) ;
        Triangles[pos] = _vertex3ui(Vertices.size()-1, (i*2+2)%(n*2), i*2);
        pos++;
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

