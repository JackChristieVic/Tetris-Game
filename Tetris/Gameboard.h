//
// Created by Jack Christie on 2019-03-27.
//

#ifndef L7Q1_CLION_GAMEBOARD_H
#define L7Q1_CLION_GAMEBOARD_H

#include <vector>
#include "Point.h"

class Gameboard
{
public:
    // CONSTANTS
    static const int MAX_X = 10;		// gameboard x dimension
    static const int MAX_Y = 19;		// gameboard y dimension
    static const int EMPTY_BLOCK = -1;	// contents of an empty block

    // MEMBER FUNCTIONS

    Gameboard();								// constructor - empty() the grid

    int getContent(Point pt) const;				// return the content at a given point
    int getContent(int x, int y) const;			// return the content at an x,y grid loc

    void setContent(Point pt, int content);		// set the content at a given point
    void setContent(int x, int y, int content);	// set the content at an x,y grid loc
    void setContent(std::vector<Point> locs, int content);	// set the content for an array of grid locs

    bool areLocsEmpty(std::vector<Point> locs) const;// return true if the content at all the locs specified is empty
    //   IMPORTANT NOTE: invalid x,y values can be passed to this method.
    //   Invalid meaning: outside the bounds of the grid.
    //   * Only test valid points (disregard the others - and ensure you
    //   don't use them to index into the grid).  Testing invalid points
    //   would likely result in an out of bounds error or segmentation fault!
    int removeCompletedRows();					// removes all completed rows from the board
    //   use getCompletedRowIndices() and removeRows()
    //   return the # of completed rows removed
    void empty();

    // fill the board with EMPTY_BLOCK
    //   (iterate through each rowIndex and fillRow() with EMPTY_BLOCK))

    Point getSpawnLoc() const;
    // getter for the spawnLoc for new blocks

    void printToConsole() const;
    // print the grid contents to the console (for debugging purposes)
    //   use setw(2) to space the contents out.


private:
    bool isRowCompleted(int rowIndex) const;
    // return a bool indicating if a given row is full (no EMPTY_BLOCK in the row)


    std::vector<int> getCompletedRowIndices() const;
    // scan the board for completed rows.
    //   Iterate through grid rows and use isRowCompleted(rowIndex)
    //   return a vector of completed row indices.


    void removeRow(int rowIndex);
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
    void removeRows(std::vector<int> rowIndices);
    // given a vector of row indices, remove them
    //   (iterate through the vector and and call removeRow()
    //   on each row index).

    void fillRow(int rowIndex, int content);	// fill a given grid row with specified content

    void copyRowIntoRow(int sourceRowIndex,
                        int targetRowIndex);	// copy a source row's contents into a target row.




    // MEMBER VARIABLES -------------------------------------------------

    int grid[MAX_X][MAX_Y];				// the gameboard - a grid of X and Y offsets.
    //  ([0][0] is top left, [MAX_X][MAX_Y] is bottom right)
    const Point spawnLoc {MAX_X/2, 0};	// the gameboard offset to spawn a new tetromino at.

    // FRIENDS
    friend class TestSuite;				// for testing purposes (allows TestSuite to access private members of this class)
};



#endif //L7Q1_CLION_GAMEBOARD_H
