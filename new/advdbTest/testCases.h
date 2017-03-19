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
#include "mxcifQuadNode.h"

using namespace std;


void printQPointVectors(vector<QPoint> qP)
{
    for(int i=0;i< qP.size();i++) {
        qP[i].print();
    }
}

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
    QBoundingBox *tqbb1 = new QBoundingBox(0,0,100,100);
    prQuadNode *prQuadNode2= new prQuadNode(*tqbb1);
    prQuadNode2->print();


}



void printprQuadTreeRange(prQuadTree *prQT,float x, float y, float width, float height)
{
    vector<QPoint> vQPoint = prQT->queryRange(x,y,width,height);
    printQPointVectors(vQPoint);

}

vector<QPoint*> pointsTestCase1(){
    vector<QPoint*> vQPoint;
    vQPoint.push_back(new QPoint(20,20,5));
    vQPoint.push_back(new QPoint(30,30,6));
    vQPoint.push_back(new QPoint(40,40,7));
//    vQPoint.push_back(new QPoint(50,50,8));
//    vQPoint.push_back(new QPoint(25,25,9));
    vQPoint.push_back(new QPoint(22,22,10));
    vQPoint.push_back(new QPoint(42,42,11));

    return vQPoint;

}

void prQuadTreeTestCase1()
{
    cout<<"\n\nprQuadTree 1"<<endl;
    prQuadTree *prQT = new prQuadTree(0,0,200,200);
    vector<QPoint*> testQPoints=pointsTestCase1();
    for(int i=0;i<testQPoints.size();i++) {
        prQT->insert(testQPoints[i]);
    }
    prQT->print();
    cout<<"\n\n\n\n\n"<<endl;
    cout<<"\n\nprQuadTree 1 - Query Range 1"<<endl;
    printprQuadTreeRange(prQT,0,0,30,30);
}

//testcase 2:
vector<QPoint*> pointsTestCase2(){
    vector<QPoint*> vQPoint;
    vQPoint.push_back(new QPoint(20,30,5));
    vQPoint.push_back(new QPoint(30,30,6));
    vQPoint.push_back(new QPoint(30,20,7));
    vQPoint.push_back(new QPoint(20,20,8));

    return vQPoint;

}

void prQuadTreeTestCase2()
{
    cout<<"\n\nprQuadTree 2"<<endl;
    prQuadTree *prQT = new prQuadTree(25,25,50,50);
    vector<QPoint*> testQPoints=pointsTestCase2();
    for(int i=0;i<testQPoints.size();i++) {
        prQT->insert(testQPoints[i]);
    }
    prQT->print();
    cout<<"\n\n\n\n\n"<<endl;
    cout<<"\n\nprQuadTree 2 - Query Range 1"<<endl;
    printprQuadTreeRange(prQT,0,0,30,30);   //works fine if we consider a point lying on quadrant division line is not to be included.

    cout<<"\n\nprQuadTree 2 - Query Range 1.1"<<endl;
    printprQuadTreeRange(prQT,30,30,1,1);   //ERROR

    cout<<"\n\nprQuadTree 2 - Query Range 2"<<endl;
    printprQuadTreeRange(prQT,0,0,31,31);   //works fine

    cout<<"\n\nprQuadTree 2 - Query Range 3"<<endl;
    printprQuadTreeRange(prQT,0,0,20,20);   //works fine if we consider a point lying on quadrant division line is not to be included.

    cout<<"\n\nprQuadTree 2 - Query Range 4"<<endl;
    printprQuadTreeRange(prQT,0,0,21,21);   //works fine

    cout<<"\n\nprQuadTree 2 - Query Range 5"<<endl;
    printprQuadTreeRange(prQT,30,30,0,0);   //works fine if we consider a point lying on quadrant division line is not to be included.

    cout<<"\n\nprQuadTree 2 - Query Range 6"<<endl;
    printprQuadTreeRange(prQT,29,29,1,1);   //works fine if we consider a point lying on quadrant division line is not to be included.

    cout<<"\n\nprQuadTree 2 - Query Range 7"<<endl;
    printprQuadTreeRange(prQT,30,30,1,1);   //ERROR: contradicts above assumption, given as value present (while it is on the quadrant division)

    cout<<"\n\nprQuadTree 2 - Query Range 8"<<endl;
    printprQuadTreeRange(prQT,20,30,1,1);   //works fine if we consider a point lying on quadrant division line is not to be included.

    cout<<"\n\nprQuadTree 2 - Query Range 9"<<endl;
    printprQuadTreeRange(prQT,19,29,1,1);   //ERROR: does not follow expected output as of Query Range 6

    cout<<"\n\nprQuadTree 2 - Query Range 10"<<endl;
    printprQuadTreeRange(prQT,30,20,1,1);   //works fine if we consider a point lying on quadrant division line is not to be included.

    cout<<"\n\nprQuadTree 2 - Query Range 11"<<endl;
    printprQuadTreeRange(prQT,29,19,1,1);   //works fine if we consider a point lying on quadrant division line is not to be included.

    cout<<"\n\nprQuadTree 2 - Query Range 12"<<endl;
    printprQuadTreeRange(prQT,15,15,30,10);   //works fine

    /**
     * CONCLUSION: parameter height and width does not include points that lie on them,
     *             but parameters x and y include a points that lie on them
     */
}

//testcase 3:
vector<QPoint*> pointsTestCase3(){
    vector<QPoint*> vQPoint;
    vQPoint.push_back(new QPoint(100,100,5));
    vQPoint.push_back(new QPoint(150,150,6));
    vQPoint.push_back(new QPoint(175,175,7));
    vQPoint.push_back(new QPoint(187.5,187.5,8));
    vQPoint.push_back(new QPoint(193.75,193.75,9));
    return vQPoint;

}

void prQuadTreeTestCase3()
{
    cout<<"\n\nprQuadTree 1"<<endl;
    prQuadTree *prQT = new prQuadTree(0,0,400,400);
    vector<QPoint*> testQPoints=pointsTestCase3();
    for(int i=0;i<testQPoints.size();i++) {
        prQT->insert(testQPoints[i]);
    }
    prQT->print();
    cout<<"\n\n\n\n\n"<<endl;
    cout<<"\n\nprQuadTree 3 - Query Range 1"<<endl;
    printprQuadTreeRange(prQT,0,0,400,400);

    /**
     * CONCLUSION: Works fine
     */


}


void testprQuadTree()
{
    //prQuadTreeTestCase1();
    prQuadTreeTestCase2();
    //prQuadTreeTestCase3();


}


#endif //ADVDBTEST_TESTCASES_H
