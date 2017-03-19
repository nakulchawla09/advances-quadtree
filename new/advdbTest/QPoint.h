//
// Created by ravichandran on 17/03/17.
//

#ifndef ADVDBTEST_QPOINT_H
#define ADVDBTEST_QPOINT_H

#include "QuadTreeLib.h"

using namespace std;

class QPoint {
    float x;
    float y;
    int id;
public:
    QPoint() {}
    QPoint(float x, float y)
    {   this->x = x;
        this->y = y;
    }

//    bool  operator==(const QPoint& rhsNode){
//        return this->x==rhsNode.x && this->y==rhsNode.y;
//    }

    void set(float x,float y)
    {
        this->x = x;
        this->y = y;
    }
    float getX()
    {
        return x;
    }
    float getY()
    {
        return y;
    }
    int getId()
    {
        return id;
    }
    void setId(int id){
        this->id = id;
    }

//    bool isIn(vector<QPoint> points)
//    {
//        return find(points.begin(), points.end(), this) != points.end() ;
//    }
};


#endif //ADVDBTEST_QPOINT_H