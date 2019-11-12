//
// Created by Jack Christie on 2019-03-18.
//

#include "Point.h"
using namespace std;

Point::Point() {
    x = 0;
    y = 0;
}

//Point::Point(int newX, int newY) :x(newX), y(newY) {}
Point::Point(int newX, int newY){
    x = newX;
    y = newY;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}

void Point::setXY(int x, int y) {
    this->x = x;
    this->y = y;
}

void Point::swapXY() {
    int temp;
    temp = x;
    x = y;
    y = temp;
}
void Point::multiplyX(int factor) {
    x = factor * x;
}

void Point::multiplyY(int factor) {
    y = factor * y;
}

std::string Point::toString() const {
    string s = "[";
    s += x;
    s += ",";
    s += y;
    s += "]";
    return s;
}

