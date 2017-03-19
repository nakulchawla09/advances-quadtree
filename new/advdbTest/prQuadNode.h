//
// Created by ravichandran on 18/03/17.
//

#ifndef ADVDBTEST_PRQUADNODE_H
#define ADVDBTEST_PRQUADNODE_H

#include "QuadTreeLib.h"
#include "QuadNode.h"

class prQuadNode : public QuadNode
{
protected:
    int leafCapacity;
    int maxHeight;

    int height;
    vector<QPoint> points;
    prQuadNode *prqnNW;
    prQuadNode *prqnNE;
    prQuadNode *prqnSW;
    prQuadNode *prqnSE;

public:

    prQuadNode() {}
    prQuadNode(QBoundingBox QBB)
    {
        height = 1;
        leafCapacity = 4;
        maxHeight = 20;
        (*this).qbb = QBB;
        (*this).prqnNW = NULL;
        (*this).prqnNE = NULL;
        (*this).prqnSW = NULL;
        (*this).prqnSE = NULL;

    }
    prQuadNode(int originX, int originY, float width, float height)
    {
        height = 1;
        leafCapacity = 4;
        maxHeight = 20;
        QBoundingBox *QBB = new QBoundingBox(originX, originY, width, height);
        (*this).qbb = *QBB;
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

    void pointsPrint()
    {
        cout<<endl;
        for (int i=0; i<points.size(); i++)
            points[i].print("\t\t");
        cout<<endl;
    }

    void print(string prefix = "", bool emptyLine = false)
    {
        if(emptyLine) cout<<endl;
        cout<<prefix<< "prQuadNode | leafCapacity : "<<this->leafCapacity<<" | maxHeight : "<<this->maxHeight<<endl;
        cout<<prefix<< "prQuadNode | height : "<<this->height<<endl;
        cout<<prefix<< "prQuadNode | ";
        this->qbb.print("\t\t",true);
        cout<<prefix<< "prQuadNode | points -> ";
        pointsPrint();
        if(prqnNW != NULL)
        {
            cout<<prefix<< "prQuadNode | northWest -> ";
            this->prqnNW->print("\t");
            cout<<prefix<< "prQuadNode | northEast -> ";
            this->prqnNE->print("\t");
            cout<<prefix<< "prQuadNode | southWest -> ";
            this->prqnSW->print("\t");
            cout<<prefix<< "prQuadNode | southEast -> ";
            this->prqnSE->print("\t");

        }

    }

};



#endif //ADVDBTEST_PRQUADNODE_H
