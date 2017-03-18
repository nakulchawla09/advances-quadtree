//
// Created by ravichandran on 17/03/17.
//

#ifndef ADVDBTEST_QUADTREE_H
#define ADVDBTEST_QUADTREE_H

#include "QuadTreeLib.h"
#include "QPoint.h"
using namespace std;

template <class QPoint>
class QuadTree {

//    virtual QuadNode getRoot() = 0;

    virtual vector<QPoint> queryRange(double x, double y, double width, double height) = 0;

    virtual bool insert(double x, double y) = 0 ;

};

#endif //ADVDBTEST_QUADTREE_H
