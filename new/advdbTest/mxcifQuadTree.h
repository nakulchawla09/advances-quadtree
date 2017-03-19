//
// Created by ravichandran on 19/03/17.
//

#ifndef ADVDBTEST_MXCIFQUADTREE_H
#define ADVDBTEST_MXCIFQUADTREE_H

#include "QuadTreeLib.h"
#include "mxcifQuadNode.h"
#include "QuadTree.h"

class mxcifQuadTree : public QuadTree
{

private:
    QPoint XY_POINT;
    QBoundingBox RANGE;

    mxcifQuadNode *root;

public:

    mxcifQuadTree(){}
    mxcifQuadTree(float originX, float originY, float width, float height) {
        float x = originX - width/2;
        float y = originY - height/2;
        QPoint *xyPoint = new QPoint(x,y);
        QBoundingBox *QBB = new QBoundingBox(xyPoint,width,height);
        root = new mxcifQuadNode( *QBB );
    }

    mxcifQuadTree(float width, float height) {
        float x = 0 - width/2;
        float y = 0 - height/2;
        QPoint *xyPoint = new QPoint(x,y);
        QBoundingBox *QBB = new QBoundingBox(xyPoint,width,height);
        root = new mxcifQuadNode( *QBB );
    }

    QuadNode* getRoot() {
        return root;
    }


    bool insert(float x, float y, float width, float height) {
        x = x - width/2;
        y = y - height/2;
        QPoint *xyPoint = new QPoint(x,y);
        QBoundingBox *QBB = new QBoundingBox(xyPoint,width,height);
        return (*root).insert(QBB);
    }

    bool insert(float width, float height) {
        float x = 0 - width/2;
        float y = 0 - height/2;
        QPoint *xyPoint = new QPoint(x,y);
        QBoundingBox *QBB = new QBoundingBox(xyPoint,width,height);
        return (*root).insert(QBB);
    }

    bool insert(QBoundingBox *QBB) {

        return (*root).insert(QBB);
    }

    void print(string prefix = "", bool emptyLine = false)
    {
        if(emptyLine) cout<<endl;
        cout<<prefix<< "Root Node | ";
        if(root!=NULL)
        {
            print(root,"*",true);
        }


    }

    void print(mxcifQuadNode *node, string prefix = "", bool emptyLine = false)
    {
        if(node!=NULL)
        {
//            if(node->qbb.getMinX()>=0 && node->qbb.getMinY()>=0)
//            {
//                node->print(prefix,true);
//            }
            node->print(prefix,true);

            if(node->mxqnNE != NULL && node->mxqnNW != NULL && node->mxqnSE != NULL && node->mxqnSW != NULL)
            {
                prefix += "\t";
                print(node->mxqnNW,prefix + " | NW |",true);
                print(node->mxqnNE,prefix + " | NE |",true);
                print(node->mxqnSW,prefix + " | SW |",true);
                print(node->mxqnSE,prefix + " | SE |",true);

            }
        }


    }

    vector<QBoundingBox> queryRange(float x, float y, float width, float height) {
        vector<QBoundingBox> vQPoint;
        if (root == NULL)
            return vQPoint;

        XY_POINT.set(x,y);
        RANGE.set(&XY_POINT,width,height);

        vector<QBoundingBox> rectsInRange;
        root->queryRange(RANGE,rectsInRange);
        return rectsInRange;
    }

};

#endif //ADVDBTEST_MXCIFQUADTREE_H
