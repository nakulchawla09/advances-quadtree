//
// Created by ravichandran on 18/03/17.
//

#ifndef ADVDBTEST_TESTCASES_H
#define ADVDBTEST_TESTCASES_H

#include "QuadTreeLib.h"
#include "QPoint.h"
#include "QBoundingBox.h"
#include "QuadNode.h"
#include "QuadTree.h"
#include "prQuadNode.h"
#include "prQuadTree.h"

using namespace std;

void testPoints()
{
    cout<<"\n\nPoint 1"<<endl;
    QPoint *tPoint1 = new QPoint(0,0);
    tPoint1->print();
    tPoint1->set(2.5,2.8);
    tPoint1->print();

    cout<<"\n\nPoint 2"<<endl;
    QPoint *tPoint2 = new QPoint(1,0,12);
    tPoint2->print();
}

void testQBoundingBox()
{
    cout<<"\n\nQBoundingBox 1"<<endl;
    QBoundingBox *tqbb1 = new QBoundingBox(100,100);
    tqbb1->print();
    tqbb1->set(200,100);
    tqbb1->print();
    tqbb1->set(10,10,200,100);
    tqbb1->print();

    cout<<"\n\nQBoundingBox 2"<<endl;
    QBoundingBox *tqbb2 = new QBoundingBox(0,0,100,100);
    tqbb2->print();
    tqbb2->set(50,50);
    tqbb2->print();
    tqbb2->set(10,10,100,100);
    tqbb2->print();

}

void testprQuadNode()
{
    cout<<"\n\nprQuadNode 1"<<endl;
    prQuadNode *prQuadNode1= new prQuadNode();
    prQuadNode1->print();

    cout<<"\n\nprQuadNode 2"<<endl;
    QBoundingBox *tqbb1 = new QBoundingBox(100,100);
    prQuadNode *prQuadNode2= new prQuadNode(*tqbb1);
    prQuadNode2->print();


}

void prQuadTreeTestCase1()
{

}

void testprQuadTree()
{
    prQuadTreeTestCase1();

}


#endif //ADVDBTEST_TESTCASES_H
