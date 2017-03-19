//
// Created by ravichandran on 18/03/17.
//

#ifndef ADVDBTEST_PRQUADTREE_H
#define ADVDBTEST_PRQUADTREE_H

#include "QuadTreeLib.h"
#include "prQuadNode.h"
#include "QuadTree.h"

class prQuadTree : public QuadTree
{

private:
    QPoint XY_POINT;
    QBoundingBox RANGE;

    prQuadNode *root;

public:

    prQuadTree(){}
    prQuadTree(float originX, float originY, float width, float height) {
        QPoint *xyPoint = new QPoint(originX,originY);
        QBoundingBox *QBB = new QBoundingBox(xyPoint,width,height);
        root = new prQuadNode( *QBB );
    }

    prQuadTree(float width, float height) {
        QPoint *xyPoint = new QPoint(0,0);
        QBoundingBox *QBB = new QBoundingBox(xyPoint,width,height);
        root = new prQuadNode( *QBB );
    }

    QuadNode* getRoot() {
        return root;
    }

    bool insert(float x, float y) {
        QPoint *xyPoint = new QPoint(x,y);

        return (*root).insert(xyPoint);
    }

    bool insert(float x, float y, int id) {
        QPoint *xyPoint = new QPoint(x,y,id);

        return (*root).insert(xyPoint);
    }

};



#endif //ADVDBTEST_PRQUADTREE_H
