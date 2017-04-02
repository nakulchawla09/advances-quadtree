//
// Created by ravichandran on 19/03/17.
//

#ifndef ADVDBTEST_TESTCASESMXCIFQUADTREE_H
#define ADVDBTEST_TESTCASESMXCIFQUADTREE_H

#include "../UtilityFunctions.h"
#include "../mxcifQuadNode.h"
#include "../mxcifQuadTree.h"

using namespace std;


void testmxcifQuadNode()
{
    cout<<"\n\n mxcifQuadNode Testing - Started"<<endl;

    cout<<"\n\n mxcifQuadNode Test Case 1"<<endl;
    mxcifQuadNode *mxcifQuadNode1= new mxcifQuadNode();
    mxcifQuadNode1->print();

    cout<<"\n\n mxcifQuadNode Test Case 2"<<endl;
    QBoundingBox *tqbb1 = new QBoundingBox(0,0,100,100);
    mxcifQuadNode *mxcifQuadNode2= new mxcifQuadNode(*tqbb1);
    mxcifQuadNode2->print();

    cout<<"\n\n mxcifQuadNode Testing - Ended"<<endl;

}


#endif //ADVDBTEST_TESTCASESMXCIFQUADTREE_H
