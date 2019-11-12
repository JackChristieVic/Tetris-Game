//
// Created by Jack Christie on 2019-03-27.
//

#include "Gameboard.h"
#include <iostream>
#include <iomanip>
using namespace std;


Gameboard::Gameboard(){
    // constructor - empty() the grid
    empty();
}

int Gameboard::getContent(Point pt) const{
    // return the content at a given point
    //pt is an object of class Point, so it has getX() & getY() functions.
    //grid is a 2-dim array, we assign the coordinate of the pt and return it.
    //"content" refers to the integer in Point class that represents a color in the color enum
    return grid[pt.getX()][pt.getY()];
}

int Gameboard::getContent(int x, int y) const{
    // return the content at an x,y grid loc
    return grid[x][y];
}


void Gameboard::setContent(Point pt, int content){
    // set the content at a given point
    grid[pt.getX()][pt.getY()] = content;
}


void Gameboard::setContent(int x, int y, int content){
    // set the content at an x,y grid loc
    grid[x][y] = content;
}


void Gameboard::setContent(std::vector<Point> locs, int content){
    // set the content for an array of grid locs
    for(Point a : locs){
        setContent(a, content);
    }
}


bool Gameboard::areLocsEmpty(std::vector<Point> locs) const{
// return true if the content at all the locs specified is empty
    for(Point pt : locs){
        if (grid[pt.getX()][pt.getX()] != EMPTY_BLOCK ){
            return false;
        }
    }
    return true;
}



//   use getCompletedRowIndices() and removeRows()
//   return the # of completed rows removed
int Gameboard::removeCompletedRows(){

    vector<int> tempVector = getCompletedRowIndices();
    removeRows(tempVector);
    return tempVector.size();
}

void Gameboard::empty(){
    // fill the board with EMPTY_BLOCK
    for (int x = 0; x < MAX_X; ++x) {
        for (int y = 0; y < MAX_Y; ++y) {
            grid[x][y] = EMPTY_BLOCK;
        }
    }
}


Point Gameboard::getSpawnLoc() const{
    // getter for the spawnLoc for new blocks
    return spawnLoc;
}


void Gameboard::printToConsole() const{
    // print the grid contents to the console (for debugging purposes)
    for (int y = 0; y < MAX_Y; ++y) {
        for (int x = 0; x < MAX_X ; ++x) {
            if(grid[y][x] == EMPTY_BLOCK)
                cout << setw(2) << "o";
        }
        cout << "\n";
    }
}

// PRIVATE FUNCTION
bool Gameboard::isRowCompleted(int rowIndex) const{
    // return a bool indicating if a given row is full
    // (no EMPTY_BLOCK in the row)
    for (int x = 0; x < MAX_X; ++x) {
        if(grid[x][rowIndex] == EMPTY_BLOCK){
            return false;
        }
    }
    return true;
}


std::vector<int> Gameboard::getCompletedRowIndices() const{
    // scan the board for completed rows.
    // Iterate through grid rows and use isRowCompleted(rowIndex)
    // return a vector of completed row indices.
    vector<int> tempVector;
    for (int y = 0; y < MAX_Y; ++y) {
        if (isRowCompleted(y)) {
            tempVector.push_back(y);
        }
    }
    return tempVector;
}






// In gameplay, when a full row is completed (filled with content)
// it gets "removed".  To be exact, the row itself is not removed
// but the content from the row above it is copied into it.
// This continues all the way up the grid until the first row
// is copied into the second row.  Finally, the first row is
// filled with EMPTY_BLOCK
// given a row index:
//   1) Starting at rowIndex, copy each row above the removed
//     row "one-row-downwards" in the grid.
//     (loop from y=rowIndex to 0, and copyRowIntoRow(y-1, y)).
//   2) call fillRow() on the first row (and place EMPTY_BLOCKs in it).
void Gameboard::removeRow(int rowIndex){
    // In gameplay, when a full row is completed (filled with content)
    for (int i = rowIndex - 1;  i > 0 ; --i) {
            copyRowIntoRow(i, i+1);
    }
    fillRow(0, EMPTY_BLOCK);
}


// PRIVATE FUNCTION
void Gameboard::removeRows(std::vector<int> rowIndices){
    // given a vector of row indices, remove them
    //   (iterate through the vector and and call removeRow()
    //   on each row index).
    for (int i = 0; i < rowIndices.size(); ++i) {
        removeRow(rowIndices[i]);
    }
}

// PRIVATE FUNCTION
void Gameboard::fillRow(int rowIndex, int content){
    // fill a given grid row with specified content
    for (int x = 0; x < MAX_X; ++x) {
        grid[x][rowIndex] = content;
    }
}

// PRIVATE FUNCTION
void Gameboard::copyRowIntoRow(int sourceRowIndex,
                               int targetRowIndex){
    // copy a source row's contents into a target row.
    for (int x = 0; x < MAX_X; ++x) {
        grid[x][targetRowIndex] = grid[x][sourceRowIndex];
    }
}

