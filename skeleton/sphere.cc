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
    Vertices.resize((n-2)*revolutions + 2) ;
    int pos=0 ;
    for (int j=0 ; j<revolutions ; j++) {
        for (int i=1 ; i<n-1 ; i++) {
            float x = cos(3*M_PI/2 + M_PI*i/(n-1))*r ;
            float y = sin(3*M_PI/2 + M_PI*i/(n-1))*r ;

            Vertices[pos] = _vertex3f( x*( cos((2*M_PI/revolutions)*j) ) , y, x*( sin((2*M_PI/revolutions)*j) )) ;
            pos++ ;
        }
    }

    Vertices[pos] = _vertex3f(0,r,0) ;
    pos++ ;
    Vertices[pos] = _vertex3f(0,-r,0) ;

    //(n-1)*2*revolutions
    Triangles.resize(revolutions*(2+(n-3)*2)) ;
    //Lateral
    pos=0 ;
    for (int i=0 ; i<n-3 ; i++) {
        for (int j=0 ; j<revolutions ; j++) {
//            int v1 = ((1+n*j)+i)%(revolutions*n);
//            int v2 = (n+i+1+ n*j)%(revolutions*n);
//            int v3 = 2+i+n*j;
//            Triangles[pos] = _vertex3ui( v1 , v2 , v3 ) ;
//            pos++ ;
//            Triangles[pos] = _vertex3ui( (v1+n)%(revolutions*n) , (v2+1)%(revolutions*n) , v3 ) ;
//            pos++ ;
            int v1 = ((n-2)*j+i)%((n-2)*revolutions);
            int v2 = ((n-2)*(1+j)+i)%((n-2)*revolutions) ;
            int v3 = (1+(n-2)*j+i)%((n-2)*revolutions) ;
            Triangles[pos] = _vertex3ui(v1, v2, v3) ;
            pos++ ;
            Triangles[pos] = _vertex3ui((v1+(n-2))%((n-2)*revolutions), (v2+1)%((n-2)*revolutions), v3) ;
            pos++ ;
        }
    }
    //Cubierta superior
    for (int i=0 ; i<revolutions ; i++) {
        Triangles[pos] = _vertex3ui(((n-3)+(n-2)*i)%((n-2)*revolutions), ((n-3)+(n-2)*(i+1))%((n-2)*revolutions), Vertices.size()-2) ;
        pos++ ;
    }
    //Cubierta inferior
    for (int i=0 ; i<revolutions ; i++) {
        Triangles[pos] = _vertex3ui(((n-2)*i)%((n-2)*revolutions), ((n-2)*(i+1))%((n-2)*revolutions), Vertices.size()-1) ;
        pos++ ;
    }

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

