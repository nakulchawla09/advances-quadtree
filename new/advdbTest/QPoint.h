//
// Created by ravichandran on 17/03/17.
//

#ifndef ADVDBTEST_QPOINT_H
#define ADVDBTEST_QPOINT_H

#include "QuadTreeLib.h"


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
};


#endif //ADVDBTEST_QPOINT_H