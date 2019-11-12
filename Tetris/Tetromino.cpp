//
// Created by Jack Christie on 2019-03-18.
//

#include "Tetromino.h"
using namespace std;

Tetromino::Tetromino() {
    setShape(TetShape::SHAPE_T);
}

TetColor Tetromino::getColor() {
    return color;
}
TetShape Tetromino::getShape() {
    return shape;
}
void Tetromino::setShape(TetShape shape) {
    this->shape = shape;
    switch (shape) {

        case TetShape::SHAPE_S:
            blockLocs = {Point(-1, 0), Point(0, 0), Point(0, 1), Point(1, 1)};
            color = TetColor::RED;
            break;

        case TetShape::SHAPE_Z:
            blockLocs = {Point(-1, 1), Point(0, 1), Point(0, 0), Point(1, 0),};
            color = TetColor::ORANGE;
            break;

        case TetShape::SHAPE_L:
            blockLocs = {Point(0, 1), Point(0, 0), Point(0, -1), Point(1, -1)};
            color = TetColor::YELLOW;
            break;

        case TetShape::SHAPE_J:
            blockLocs = {Point(-1, -1), Point(0, -1), Point(0, 0), Point(0, 1),};
            color = TetColor::GREEN;
            break;

        case TetShape::SHAPE_O:
            blockLocs = {Point(0, 1), Point(1, 1), Point(0, 0), Point(1, 0)};
            color = TetColor::BLUE_LIGHT;
            break;

        case TetShape::SHAPE_I:
            blockLocs = {Point(0, 2), Point(0, 1), Point(0, 0), Point(0, -1)};
            color = TetColor::BLUE_DARK;
            break;

        case TetShape::SHAPE_T:
            blockLocs = {Point(-1,0), Point(0, 0), Point(1,0), Point(0,-1)};
            color = TetColor::PURPLE;
            break;

    }
}

void Tetromino::rotateCW() {
    for (int i = 0; i < blockLocs.size(); i++) {
        blockLocs[i].swapXY();
        blockLocs[i].multiplyY(-1);
    }
}

void Tetromino::printToConsole() {
    for (int i = 3; i >= -3;  i--){
        for (int j = -3; j <= 3; j++){
            bool pointMatch = false;
            for(Point a : blockLocs){
                int x = a.getX();
                int y = a.getY();
                if (x == j && y == i){
                    pointMatch = true;
                }
            }
            if(!pointMatch) {
                cout << " . ";
            }else{
                cout << " X " ;
            }
        }
        cout << "\n";
    }
}
