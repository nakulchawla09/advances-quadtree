//
// Created by ravichandran on 19/03/17.
//

#ifndef ADVDBTEST_UTILITYFUNCTIONS_H
#define ADVDBTEST_UTILITYFUNCTIONS_H

#include "QuadTreeLib.h"
#include "QPoint.h"

using namespace std;

void printQPointVectors(vector<QPoint> qP)
{
    for(int i=0;i< qP.size();i++) {
        qP[i].print();
    }
}

void getBoundingBoxCooridinates(vector<QPoint> qP)
{
    float minX,maxX,minY,maxY,currentX,currentY; int i;
    minX = qP[1].getX();
    minY = qP[1].getY();
    maxX = qP[1].getX();
    maxY = qP[1].getY();

    for(i=0;i< qP.size();i++){
        currentX = qP[i].getX();
        currentY = qP[i].getY();
        if(currentX <= minX){
            minX = currentX;
        }else if (currentX >= maxX){
            maxX = currentX;
        }

        if(currentY <= minY){
            minY = currentY;
        }else if(currentY >= maxY){
            maxY = currentY;
        }
    }

    //coordinates for bounding box should be (minX,minY) , (maxX,maxY)

}

//void getHeightAndWidth(vector<QPoint> qP){
//
//
//}


#endif //ADVDBTEST_UTILITYFUNCTIONS_H
