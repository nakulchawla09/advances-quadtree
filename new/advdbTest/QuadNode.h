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


    QuadNode() {
    }

    QuadNode(QBoundingBox QBB)
    {
        (*this).qbb = QBB;
    }

    virtual bool insert(QPoint *object) = 0;

//    virtual bool remove(QPoint *object) = 0;

//    virtual void queryRange(QBoundingBox *range, vector<QPoint*> objectsInRange) = 0;



};


#endif //ADVDBTEST_QUADNODE_H
