//
// Created by Darshan Shetty on 16-03-2017.
//

#ifndef UNTITLED_SPATIALINDEXINTERFACE_H
#define UNTITLED_SPATIALINDEXINTERFACE_H
#include "Point.h"
#include "Rectangle.h"
class SpatialIndexInterface {
public:
    virtual Point* search(Point diagonal1,Point diagonal2,Point &points[]) = 0;
    virtual Rectangle* search(Point diagonal1,Point diagonal2, Rectangle &rectangles[]) = 0;
    virtual SpatialIndexInterface* createIndex(Point &points[]) = 0;
    virtual SpatialIndexInterface* createIndex(Rectangle &rectangles[]) = 0;
    virtual int update(Point &points[]) = 0;
    virtual int update(Rectangle &rectangles[]) = 0;
    virtual bool deleteIndex() = 0;
};
#endif //UNTITLED_SPATIALINDEXINTERFACE_H
