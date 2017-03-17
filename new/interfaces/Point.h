//
// Created by Darshan Shetty on 16-03-2017.
//

#ifndef UNTITLED_POINT_H
#define UNTITLED_POINT_H
class Point {
    float x,y;
    int id;
public:
    Point();
    Point(float a, float b) {x = a; y = b;}
    float* getCoordinates() { float coord[] = {x,y}; return coord;}
    int getId() {return id;}
    void setId(int id) {this->id = id;};
};
#endif //UNTITLED_POINT_H
