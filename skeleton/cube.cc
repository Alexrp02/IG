/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "cube.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_cube::_cube(float Size)
{
  Vertices.resize(8);

  Vertices[0]=_vertex3f(-Size/2,-Size/2,Size/2);
  Vertices[1]=_vertex3f(Size/2,-Size/2,Size/2);
  Vertices[2]=_vertex3f(Size/2,Size/2,Size/2);
  Vertices[3]=_vertex3f(-Size/2,Size/2,Size/2);
  Vertices[4]=_vertex3f(-Size/2,-Size/2,-Size/2);
  Vertices[5]=_vertex3f(Size/2,-Size/2,-Size/2);
  Vertices[6]=_vertex3f(Size/2,Size/2,-Size/2);
  Vertices[7]=_vertex3f(-Size/2,Size/2,-Size/2);

  Edges.resize(30) ;

  int cont=0 ;
  for(int i=0 ; i<=1 ; i++) {
      for(int j=0 ; j<4 ; j++) {
          Edges[cont] = _vertex2i((j + 4*i), ((j+1)%4 + 4*i)) ;
          cont++ ;
      }
  }
  for (int i=0 ; i<4 ; i++) {
      Edges[cont] = _vertex2i(i,i+4) ;
      cont++;
  }

  Edges[24] = _vertex2i(1,3);
  Edges[25] = _vertex2i(0,7);
  Edges[26] = _vertex2i(2,7);
  Edges[27] = _vertex2i(5,2);
  Edges[28] = _vertex2i(5,0);
  Edges[29] = _vertex2i(4,6);

  Triangles.resize(12);

  Triangles[0]=_vertex3ui(0,1,3);
  Triangles[1]=_vertex3ui(1,2,3);
  Triangles[2]=_vertex3ui(4,5,0);
  Triangles[3]=_vertex3ui(5,1,0);
  Triangles[4]=_vertex3ui(4,0,7);
  Triangles[5]=_vertex3ui(0,3,7);
  Triangles[6]=_vertex3ui(3,2,7);
  Triangles[7]=_vertex3ui(2,6,7);
  Triangles[8]=_vertex3ui(1,5,2);
  Triangles[9]=_vertex3ui(5,6,2);
  Triangles[10]=_vertex3ui(5,4,6);
  Triangles[11]=_vertex3ui(4,7,6);
}

