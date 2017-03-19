//
// Created by ravichandran on 18/03/17.
//

#ifndef ADVDBTEST_QUADNODE_H
#define ADVDBTEST_QUADNODE_H

#include "QuadTreeLib.h"
#include "QBoundingBox.h"

using namespace std;


class QuadNode {
public :
    QBoundingBox qbb;


    QuadNode() {}

    QuadNode(QBoundingBox QBB)
    {
        (*this).qbb = QBB;
    }

    virtual bool insert(QPoint *point) = 0;

//    virtual bool remove(QPoint *point) = 0;

    virtual void queryRange(QBoundingBox range, vector<QPoint> &pointsInRange) = 0;


};


#endif //ADVDBTEST_QUADNODE_H
