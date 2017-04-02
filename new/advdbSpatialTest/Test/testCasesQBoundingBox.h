//
// Created by ravichandran on 18/03/17.
//

#ifndef ADVDBTEST_TESTCASESQBOUNDINGBOX_H
#define ADVDBTEST_TESTCASESQBOUNDINGBOX_H

#include "../QuadTreeLib.h"
#include "../QBoundingBox.h"

using namespace std;

void qBoundingBoxTestCase1()
{
    cout<<"\nQBoundingBox 1"<<endl;
    QBoundingBox *tqbb1 = new QBoundingBox(100,100);
    tqbb1->print();
    tqbb1->set(200,100);
    tqbb1->print();
    tqbb1->set(10,10,200,100);
    tqbb1->print();

}

void qBoundingBoxTestCase2()
{
    cout<<"\nQBoundingBox 2"<<endl;
    QBoundingBox *tqbb2 = new QBoundingBox(0,0,100,100);
    tqbb2->print();
    tqbb2->set(50,50);
    tqbb2->print();
    tqbb2->set(10,10,100,100);
    tqbb2->print();

}




void testCreateQBoundingBox()
{
    cout<<"\n\n Create QBoundingBox Testing - Started"<<endl;

    qBoundingBoxTestCase1();
    qBoundingBoxTestCase2();

    cout<<"\n\n Create QBoundingBox Testing - Started"<<endl;

}

vector<QPoint*> pointsTestCaseQBoundingBox1(){

    vector<QPoint*> vQPoint;

    vQPoint.push_back(new QPoint(-20,-10,5));
    vQPoint.push_back(new QPoint(5,5,6));
    vQPoint.push_back(new QPoint(6,-26,7));
    vQPoint.push_back(new QPoint(10,-10,10));
    vQPoint.push_back(new QPoint(-5,-10,11));
    vQPoint.push_back(new QPoint(-5,11,11));

    return vQPoint;

}

void testGetBoundingBoxCoordinates()
{
    cout<<"\n\n Get BoundingBox Co-ordinates Points - Testing - Started"<<endl;

    cout<<"\nTest Case 1"<<endl;
    vector<QPoint*> testQPoints = pointsTestCaseQBoundingBox1();
    QBoundingBox *QBB = QBoundingBox::getQBoundingBoxCooridinates(testQPoints);
    QBB->print();

    cout<<"\n\n Get BoundingBox Co-ordinates Points - Testing - Ended"<<endl;
}

void testQBoundingBox()
{
    cout<<"\n\n QBoundingBox Testing - Started"<<endl;

//    testCreateQBoundingBox();
    testGetBoundingBoxCoordinates();


    cout<<"\n\n QBoundingBox Testing - Ended"<<endl;

}


#endif //ADVDBTEST_TESTCASESQBOUNDINGBOX_H