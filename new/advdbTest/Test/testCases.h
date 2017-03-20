//
// Created by ravichandran on 18/03/17.
//

#ifndef ADVDBTEST_TESTCASES_H
#define ADVDBTEST_TESTCASES_H

#include "testCasesPoint.h"
#include "testCasesRectangle.h"
#include "../QPoint.h"
#include "../QBoundingBox.h"
#include "../prQuadNode.h"
#include "../prQuadTree.h"
#include "../mxcifQuadNode.h"
#include "../mxcifQuadTree.h"

using namespace std;


void testprQuadTree()
{
    prQuadTreeTestCase1();
    prQuadTreeTestCase2();
    prQuadTreeTestCase3();
}


#endif //ADVDBTEST_TESTCASES_H
