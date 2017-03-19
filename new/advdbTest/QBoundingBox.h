//
// Created by ravichandran on 18/03/17.
//

#ifndef ADVDBTEST_QBOUNDINGBOX_H
#define ADVDBTEST_QBOUNDINGBOX_H

#include "QuadTreeLib.h"
#include "QPoint.h"



class QBoundingBox : public QPoint
{
private:
     float height;
     float width;

     float minX;
     float minY;
     float maxX;
     float maxY;


public:

    QBoundingBox();


    QBoundingBox(float width, float height):QPoint(0,0)
    {
        this->setHeight(height);
        this->setWidth(width);

        this->minX = 0;
        this->minY = 0;
        this->maxX = width;
        this->maxY = height;

    }

    QBoundingBox(QPoint *downLeft, float width, float height):QPoint((*downLeft).getX(),(*downLeft).getY())
    {
        this->setHeight(height);
        this->setWidth(width);

        this->minX = (*downLeft).getX();
        this->minY = (*downLeft).getY();
        this->maxX = (*downLeft).getX()+width;
        this->maxY = (*downLeft).getY()+height;

    }

    void set(QPoint (*downLeft), float width, float height)
    {
        this->setHeight(height);
        this->setWidth(width);

        this->minX = (*downLeft).getX();
        this->minY = (*downLeft).getY();
        this->maxX = (*downLeft).getX()+width;
        this->maxY = (*downLeft).getY()+height;

    }

    void setHeight(float height)
    {
        this->height = height;
    }
    
    float getHeight() {
        return height;
    }

    void setWidth(float width)
    {
        this->width = width;
    }

    float getWidth() {
        return width;
    }

    bool containsPoint(QPoint *point) {

        if ( (*point).getX() >= maxX ) return false;
        if ( (*point).getX() < minX ) return false;
        if ( (*point).getY() >= maxY ) return false;
        if ( (*point).getY() < minY ) return false;
        return true;
    }

    bool insideThis(QBoundingBox (*boundingBox)) {
        return (((*boundingBox).minX >= minX && (*boundingBox).maxX <= maxX) && ((*boundingBox).minY >= minY && (*boundingBox).maxY <= maxY));
    }

     bool intersectsBox(QBoundingBox (*boundingBox)) {
        if (insideThis((boundingBox)) || (*boundingBox).insideThis(this)) return true;

        if (maxX < (*boundingBox).minX || minX > (*boundingBox).maxX) return false;
        if (maxY < (*boundingBox).minY || minY > (*boundingBox).maxY) return false;

        return true;
    }


};

#endif //ADVDBTEST_QBOUNDINGBOX_H
