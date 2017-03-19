//
// Created by ravichandran on 18/03/17.
//

#ifndef ADVDBTEST_PRQUADNODE_H
#define ADVDBTEST_PRQUADNODE_H

#include "QuadTreeLib.h"
#include "QuadNode.h"

class prQuadNode : public QuadNode
{
public:
    static int leafCapacity;
    static int maxHeight;

    int height;
    prQuadNode *prqnNW;
    prQuadNode *prqnNE;
    prQuadNode *prqnSW;
    prQuadNode *prqnSE;

    prQuadNode()
    {
        height = 1;
        (*this).prqnNW = NULL;
        (*this).prqnNE = NULL;
        (*this).prqnSW = NULL;
        (*this).prqnSE = NULL;
    }

    vector<QPoint> points;

    prQuadNode(QBoundingBox QBB):prQuadNode( QBB )
    {
        height = 1;
        (*this).prqnNW = NULL;
        (*this).prqnNE = NULL;
        (*this).prqnSW = NULL;
        (*this).prqnSE = NULL;

    }



    bool isLeaf() {
        return (prqnNW == NULL && prqnNE == NULL && prqnSW == NULL && prqnSE == NULL);
    }


    bool insert(QPoint *point)
    {

    if ( !qbb.containsPoint(point) || ( isLeaf() && point->isIn(points) ) )
        return false;


    if (( isLeaf() && points.size() < leafCapacity )  || ( height == maxHeight ) )
    {
        points.push_back(*point);
        return true;
    }

    if (isLeaf() && height<maxHeight)
        subdivide();
    return insertIntoChildren(point);
}


    bool insertIntoChildren(QPoint *point) {

        if (prqnNW->insert(point)) return true;
        if (prqnNE->insert(point)) return true;
        if (prqnSW->insert(point)) return true;
        if (prqnSE->insert(point)) return true;

    return false;
}


    void subdivide()
    {
        float h = qbb.getHeight()/2;
        float w = qbb.getWidth()/2;

        QPoint *pNW = new QPoint(qbb.getX(),qbb.getY());
        QBoundingBox *qbbNW = new QBoundingBox( pNW, w, h);
        this->prqnNW = new prQuadNode(*qbbNW);
        this->prqnNW->height = this->height + 1;

        QPoint *pNE = new QPoint(qbb.getX()-w,qbb.getY());
        QBoundingBox *qbbNE = new QBoundingBox( pNE, w, h);
        this->prqnNE = new prQuadNode(*qbbNE);
        this->prqnNE->height = this->height + 1;

        QPoint *pSW = new QPoint(qbb.getX()-w,qbb.getY()-h);
        QBoundingBox *qbbSW =new QBoundingBox( pSW, w, h);
        this->prqnSW = new prQuadNode(*qbbSW);
        this->prqnSW->height = this->height + 1;

        QPoint *pSE = new QPoint(qbb.getX(),qbb.getY()-h);
        QBoundingBox *qbbSE =new QBoundingBox( pSE, w, h);
        this->prqnSE = new prQuadNode(*qbbSE);
        this->prqnSE->height = this->height + 1;


        for (int i=0; i<points.size(); i++)
            insertIntoChildren(&points[i]);
        points.clear();




 }

};



#endif //ADVDBTEST_PRQUADNODE_H
