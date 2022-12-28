/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "tetrahedron.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_tetrahedron::_tetrahedron(float Size)
{
  Vertices.resize(4);

  Vertices[0]=_vertex3f(-Size/2,-Size/2,-Size/2);
  Vertices[1]=_vertex3f(0,-Size/2,Size/2);
  Vertices[2]=_vertex3f(Size/2,-Size/2,-Size/2);
  Vertices[3]=_vertex3f(0,Size/2,0);

  Edges.resize(6);

  Edges[0] = _vertex2i(0,1) ;
  Edges[1] = _vertex2i(1,2) ;
  Edges[2] = _vertex2i(2,0) ;
  Edges[3] = _vertex2i(0,3) ;
  Edges[4] = _vertex2i(3,2) ;
  Edges[5] = _vertex2i(3,1) ;

  Triangles.resize(4);
  faceNormals.resize(4) ; //Por cada triangulo una normal.
  pointNormals.resize(Vertices.size()) ;
  numberOfNormals.resize(Vertices.size()) ;

  Triangles[0]=_vertex3ui(0,1,3);
  faceNormals[0] = calculate_normalized_normal(Vertices[0], Vertices[1], Vertices[3]);
  Triangles[1]=_vertex3ui(1,2,3);
  faceNormals[1] = calculate_normalized_normal(Vertices[1], Vertices[2], Vertices[3]);
  Triangles[2]=_vertex3ui(2,0,3);
  faceNormals[2] = calculate_normalized_normal(Vertices[2], Vertices[0], Vertices[3]);
  Triangles[3]=_vertex3ui(0,2,1);
  faceNormals[3] = calculate_normalized_normal(Vertices[1], Vertices[2], Vertices[0]);

  for (int i=0 ; i<Triangles.size() ; i++) {
      pointNormals[Triangles[i].x] += faceNormals[i] ;
      pointNormals[Triangles[i].y] += faceNormals[i] ;
      pointNormals[Triangles[i].z] += faceNormals[i] ;
      numberOfNormals[Triangles[i].x] += 1;
      numberOfNormals[Triangles[i].y] += 1;
      numberOfNormals[Triangles[i].z] += 1;
  }
  averageNormal() ;
}

