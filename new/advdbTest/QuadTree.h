//
// Created by ravichandran on 17/03/17.
//

#ifndef ADVDBTEST_QUADTREE_H
#define ADVDBTEST_QUADTREE_H

#include "QuadTreeLib.h"
#include "QuadNode.h"
using namespace std;


class QuadTree {

    virtual QuadNode getRoot() = 0;

//    virtual vector<QPoint*> queryRange(float x, float y, float width, float height) = 0;

    virtual bool insert(float x, float y) = 0 ;


};

#endif //ADVDBTEST_QUADTREE_H
