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

    bool isIn(vector<QPoint> points)
    {
        for(int i=0; i<points.size();i++) {
            if (points[i].x == this->x && points[i].y == this->y)
                return true;
        }
        return false;
    }
};


#endif //ADVDBTEST_QPOINT_H