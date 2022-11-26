/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef HIERARCHICAL_H
#define HIERARCHICAL_H


#include "object3d.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _hierarchical : public _object3D
{
public:
    void draw(string mode, string line_color);
};

#endif
