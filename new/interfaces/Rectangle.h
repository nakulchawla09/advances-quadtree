//
// Created by Darshan Shetty on 16-03-2017.
//
#ifndef UNTITLED_RECTANGLE_H
#define UNTITLED_RECTANGLE_H
class Rectangle {
    float x1,y1,x2,y2;
    int id;
    Rectangle(float x1, float y1, float x2, float y2) {this->x1 = x1; this->y1=y1; this->x2=x2; this->y2=y2;}
    float* getCoordinates() { float coord[] = {x1,y1,x2,y2}; return coord;}
    int getId() {return id;}
    void setId(int id) {this->id = id;};
};
#endif //UNTITLED_RECTANGLE_H
