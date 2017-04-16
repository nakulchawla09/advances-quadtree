
#ifndef ADVDBTEST_TESTCASESQPOINT_H
#define ADVDBTEST_TESTCASESQPOINT_H

#include "../QuadTreeLib.h"
#include "../QPoint.h"

using namespace std;


void testQPoints()
{
    cout<<"\n\n qPoints Testing - Started"<<endl;

    cout<<"\nqPoint Test Case 1"<<endl;
    qPoint *tPoint1 = new qPoint(0,0);
    tPoint1->print();
    tPoint1->set(2.5,2.8);
    tPoint1->print();

    cout<<"\nqPoint Test Case 2"<<endl;
    qPoint *tPoint2 = new qPoint(1,0,12);
    tPoint2->print();

    cout<<"\n\n qPoints Testing - Ended"<<endl;
}


#endif //ADVDBTEST_TESTCASESQPOINT_H