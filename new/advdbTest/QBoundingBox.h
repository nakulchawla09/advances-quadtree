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

    QBoundingBox(QPoint downLeft, float width, float height):QPoint(downLeft.getX(),downLeft.getY())
    {
        this->setHeight(height);
        this->setWidth(width);

        this->minX = downLeft.getX();
        this->minY = downLeft.getY();
        this->maxX = downLeft.getX()+width;
        this->maxY = downLeft.getY()+height;

    }

    void set(QPoint downLeft, float width, float height)
    {
        this->setHeight(height);
        this->setWidth(width);

        this->minX = downLeft.getX();
        this->minY = downLeft.getY();
        this->maxX = downLeft.getX()+width;
        this->maxY = downLeft.getY()+height;

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

    bool containsPoint(QPoint p) {

        if ( p.getX() >= maxX ) return false;
        if ( p.getX() < minX) return false;
        if ( p.getY() >= maxY ) return false;
        if ( p.getY() < minY ) return false;
        return true;
    }

    bool insideThis(QBoundingBox Qbox) {
        return ((Qbox.minX >= minX && Qbox.maxX <= maxX) && (Qbox.minY >= minY && Qbox.maxY <= maxY));
    }

     bool intersectsBox(QBoundingBox Qbox) {
        if (insideThis(Qbox) || Qbox.insideThis(*this)) {
            // INSIDE
            return true;
        }

        // OUTSIDE
        if (maxX < Qbox.minX || minX > Qbox.maxX) return false;
        if (maxY < Qbox.minY || minY > Qbox.maxY) return false;

        // INTERSECTS
        return true;
    }


};

#endif //ADVDBTEST_QBOUNDINGBOX_H
