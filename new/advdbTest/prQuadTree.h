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



    prQuadTree(float x, float y, float width, float height, int leafCapacity, int maxTreeHeight) {
        QPoint *xyPoint = new QPoint(x,y);
        QBoundingBox *QBB = new QBoundingBox(xyPoint,width,height);
        prQuadNode::leafCapacity = leafCapacity;
        prQuadNode::maxHeight = maxTreeHeight;
        root = new prQuadNode( *QBB );
    }

    prQuadTree(float x, float y, float width, float height, int leafCapacity);
    prQuadTree(float x, float y, float width, float height);
    prQuadTree();


};

prQuadTree::prQuadTree(float x, float y, float width, float height, int leafCapacity) : prQuadTree(x,y,width,height,leafCapacity,20) {}
prQuadTree::prQuadTree(float x, float y, float width, float height) : prQuadTree(x,y,width,height,4,20) {}
prQuadTree::prQuadTree() {}

#endif //ADVDBTEST_PRQUADTREE_H
