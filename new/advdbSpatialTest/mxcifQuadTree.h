//
// Created by ravichandran on 19/03/17.
//

#ifndef ADVDBTEST_MXCIFQUADTREE_H
#define ADVDBTEST_MXCIFQUADTREE_H

#include "quadTreeLib.h"
#include "mxcifQuadNode.h"

class mxcifQuadTree
{

private:
    qPoint XY_POINT;
    qBoundingBox RANGE;

    mxcifQuadNode *root;

public:

    mxcifQuadTree(){}
    mxcifQuadTree(float originX, float originY, float width, float height)
    {
        float x = originX - width/2;
        float y = originY - height/2;
        qPoint *xyPoint = new qPoint(x,y);
        qBoundingBox *QBB = new qBoundingBox(xyPoint,width,height);
        root = new mxcifQuadNode( *QBB );
    }

    mxcifQuadTree(float width, float height)
    {
        float x = 0 - width/2;
        float y = 0 - height/2;
        qPoint *xyPoint = new qPoint(x,y);
        qBoundingBox *QBB = new qBoundingBox(xyPoint,width,height);
        root = new mxcifQuadNode( *QBB );
    }

    mxcifQuadTree(qBoundingBox *qbb)
    {
        root = new mxcifQuadNode( *qbb );
    }

    mxcifQuadNode* getRoot() { return root; }


    bool insert(float x, float y, float width, float height) {
        qBoundingBox *QBB = new qBoundingBox(x, y, width, height);
        return (*root).insert(QBB);
    }

    bool insert(float x, float y, float width, float height,int id) {
        qBoundingBox *QBB = new qBoundingBox(x, y, width, height, id);
        return (*root).insert(QBB);
    }

    bool insert(float width, float height)
    {
        float x = 0;
        float y = 0;
        qPoint *xyPoint = new qPoint(x,y);
        qBoundingBox *QBB = new qBoundingBox(xyPoint,width,height);
        return (*root).insert(QBB);
    }

    bool insert(qBoundingBox *QBB)
    {
        return (*root).insert(QBB);
    }

    void deleteRoot()
    {
        if(root == NULL) return;

        root->deleteNode();

    }

    vector<qBoundingBox> queryRange(float x, float y, float width, float height)
    {
        vector<qBoundingBox> vQPoint;
        if (root == NULL)
            return vQPoint;

        XY_POINT.set(x,y);
        RANGE.set(&XY_POINT,width,height);

        vector<qBoundingBox> rectsInRange;
        root->queryRange(RANGE,rectsInRange);
        return rectsInRange;
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

};

#endif //ADVDBTEST_MXCIFQUADTREE_H
