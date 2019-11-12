//
// Created by Jack Christie on 2019-03-18.
//
#pragma once
#ifndef TETROMINO_H
#define TETROMINO_H

#include <string>
#include <iostream>
#include "Point.h"
#include <vector>


enum class TetColor {
    RED = 0, ORANGE, YELLOW, GREEN,
    BLUE_LIGHT, BLUE_DARK, PURPLE
};

enum class TetShape {
    SHAPE_S = 0, SHAPE_Z, SHAPE_L,
    SHAPE_J, SHAPE_O, SHAPE_I, SHAPE_T
};

class Tetromino {
    friend class TestSuite;
private:
    TetColor color;
    TetShape shape;
protected:
    std::vector<Point> blockLocs;
public:
    Tetromino();
    TetColor getColor();
    TetShape getShape();
    void setShape(TetShape shape);
    void rotateCW();
    void printToConsole();

};

#endif
