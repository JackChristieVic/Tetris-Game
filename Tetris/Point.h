//
// Created by Jack Christie on 2019-03-18.
//


#ifndef POINT_H
#define POINT_H
#include <string>
#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    Point();
    Point(int newX, int newY);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    void setXY(int x, int y);
    void swapXY();
    void multiplyX(int factor);
    void multiplyY(int factor);
    std::string toString() const;
};

#endif
