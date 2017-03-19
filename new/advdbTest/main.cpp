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
    cout<<"Point 1"<<endl;
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
    cout<<"QBoundingBox 1"<<endl;
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

int main() {
    cout << "Hello, World" << endl;
    testPoints();
    testQBoundingBox();
    return 0;
}

