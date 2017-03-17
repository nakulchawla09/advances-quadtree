//
// Created by Darshan Shetty on 16-03-2017.
//

#ifndef UNTITLED_POINTSPATIALINDEX_H
#define UNTITLED_POINTSPATIALINDEX_H

#include "SpatialIndexInterface.h"
class PointSpatialIndex: public SpatialIndexInterface {
public:
     Point* search(Point diagonal1,Point diagonal2) {

     }
     Rectangle* searchRectangle(Point diagonal1,Point diagonal2){
         return nullptr;
     }
     SpatialIndexInterface createIndex(Point &points[]) {

     }
     SpatialIndexInterface createIndex(Rectangle &rectangles[]){
         return nullptr;
     }
     int update(Point &points[]){

     }
     int update(Rectangle &rectangles[]) {
         return nullptr;
     }
     bool deleteIndex() {

     }
};
#endif //UNTITLED_POINTSPATIALINDEX_H