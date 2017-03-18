//
// Created by ravichandran on 18/03/17.
//

#ifndef ADVDBTEST_QUADNODE_H
#define ADVDBTEST_QUADNODE_H

#include "QuadTreeLib.h"
//#include "QPoint.h"
#include "QBoundingBox.h"

using namespace std;


class QuadNode {
protected :
    QBoundingBox qbb;

    QuadNode *qnNW;
    QuadNode *qnNE;
    QuadNode *qnSW;
    QuadNode *qnSE;

public:
    QuadNode() {
        (*this).qnNW = NULL;
        (*this).qnNE = NULL;
        (*this).qnSW = NULL;
        (*this).qnSE = NULL;

    }

    QuadNode(QBoundingBox qbb)
    {
        (*this).qnNW = NULL;
        (*this).qnNE = NULL;
        (*this).qnSW = NULL;
        (*this).qnSE = NULL;
        (*this).qbb = qbb;
    }

    virtual bool insert(QPoint *object) = 0;

    virtual bool remove(QPoint *object) = 0;

    virtual void queryRange(QBoundingBox range, vector<QPoint*> geometricObjectsInRange) = 0;

    bool isLeaf() {
        return (qnNW==NULL && qnNE==NULL && qnSW==NULL && qnSE==NULL);
    }

};


#endif //ADVDBTEST_QUADNODE_H
