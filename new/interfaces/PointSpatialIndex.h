//
// Created by Darshan Shetty on 16-03-2017.
//

#ifndef UNTITLED_POINTSPATIALINDEX_H
#define UNTITLED_POINTSPATIALINDEX_H

#include "SpatialIndexInterface.h"
#include "CustomQuadTree.h"
using namespace std;

class PointSpatialIndex: public SpatialIndexInterface {
    PointQuadtree pointQuadtree;
    PointSpatialIndex *pointIndex;
    int compare(const void * a, const void * b)
    {
        return ((Point *)a)->getCoordinates()[0] - ((Point*)b)->getCoordinates()[0];
    }
public:
     Point* search(Point diagonal1,Point diagonal2, Point &points[]) {

         int count = sizeof(points)/ sizeof(points[0]),j=0;
         Point* pointsFound = new Point[count];
         for(int i=0;i<count;i++){
             if(pointQuadtree.search(points[i]))
                 pointsFound[j++]= points[i];
         }
         return pointsFound;
     }
     Rectangle* searchRectangle(Point diagonal1,Point diagonal2, Rectangle &rectangles[]){
         return nullptr;
     }
     SpatialIndexInterface* createIndex(Point &points[]) {

        int elementCount = sizeof(points)/ sizeof(points[0]);
         pointIndex = new PointSpatialIndex;
         SpatialIndexInterface *returnInterface = pointIndex;
         qsort(points,elementCount, sizeof(Point),compare);
         pointQuadtree.insert(points[elementCount/2]);
         for(int i=0;i<elementCount;i++){
             if(i != elementCount/2)
                 pointQuadtree.insert(points[i]);
         }
         return returnInterface;
     }
     SpatialIndexInterface* createIndex(Rectangle &rectangles[]){
         return nullptr;
     }
     int update(Point &points[]){
        deleteIndex();
         createIndex(points);
     }
     int update(Rectangle &rectangles[]) {
         return nullptr;
     }
     bool deleteIndex() {
        pointQuadtree.deleteTree();
         if(pointIndex != NULL)
         delete pointIndex;
     }
};
#endif //UNTITLED_POINTSPATIALINDEX_H