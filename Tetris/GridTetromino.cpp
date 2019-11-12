//
// Created by Jack Christie on 2019-03-27.
//

//
// Created by Jack Christie on 2019-04-03.
//
// The GridTetromino extends the basic Tetromino
// Functionality added:
//  - The concept of the tetromino's location on the gameboard/grid. (gridLoc)
//  - The ability to change a tetromino's location
//  - The ability to retrieve a vector of tetromino block locations mapped to the gridLoc.
//
//  [expected .cpp size: ~ 40 lines]

#include "Tetromino.h"
#include "GridTetromino.h"

GridTetromino::GridTetromino() {
	// constructor, initialize gridLoc to 0,0
	gridLoc.setX(0);
	gridLoc.setY(0);
}

Point GridTetromino::getGridLoc() const {
	// return the tetromino's grid/gameboard loc (x,y)
	return gridLoc;
}
void GridTetromino::setGridLoc(int x, int y) {
	// sets the tetromino's grid/gameboard loc using x,y
	gridLoc.setXY(x, y);
}
void GridTetromino::setGridLoc(const Point& pt) {
	// sets the tetromino's grid/gameboard loc using a Point
	// gridLoc is of type Point, Point class has a function: setXY(int x, int y)
	// we use the getX() & getY() functions to get the two integers of setXY()
	gridLoc.setXY(pt.getX(), pt.getY());

}

// transpose the gridLoc of this shape
//	(1,0) represents a move to the right (x+1)
//	(-1,0) represents a move to the left (x-1)
//	(0,1) represents a move down (y+1)
void GridTetromino::move(int xOffset, int yOffset) {
	// sets the tetromino's grid/gameboard loc using a Point
	gridLoc.multiplyX(xOffset);
	gridLoc.multiplyY(yOffset);

}




// build and return a vector of Points to represent our inherited
// blockLocs vector mapped to the gridLoc of this object instance.
// eg: if we have a Point [x,y] in our vector,
// and our gridLoc is [5,6] the mapped Point would be [5+x,6+y].
std::vector<Point> GridTetromino::getBlockLocsMappedToGrid() const {
	std::vector<Point> tempVector;
	for (int i = 0; i < blockLocs.size(); ++i) {
		int x = gridLoc.getX() + blockLocs[i].getX();
		int y = gridLoc.getY() + blockLocs[i].getY();
		Point pt(x, y);


		tempVector.push_back(pt);
	}
	return tempVector;
}







/*
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

---------------------------------------------------------------

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
private:
	std::vector<Point> blockLocs;
public:
	Tetromino();
	TetColor getColor();
	TetShape getShape();
	void setShape(TetShape shape);
	void rotateCW();
	void printToConsole();

};
-----------------------------------------------------------
class Gameboard
{
public:
	// CONSTANTS
	static const int MAX_X = 10;		// gameboard x dimension
	static const int MAX_Y = 19;		// gameboard y dimension
	static const int EMPTY_BLOCK = -1;	// contents of an empty block

	// MEMBER FUNCTIONS

	Gameboard();								

	int getContent(Point pt) const;				
	int getContent(int x, int y) const;		

	void setContent(Point pt, int content);		
	void setContent(int x, int y, int content);
	void setContent(std::vector<Point> locs, int content);	

	bool areLocsEmpty(std::vector<Point> locs) const;
	int removeCompletedRows();				
	void empty();
	Point getSpawnLoc() const;
	void printToConsole() const;
	
private:
	bool isRowCompleted(int rowIndex) const;
	
	std::vector<int> getCompletedRowIndices() const;

	void removeRow(int rowIndex);

	void removeRows(std::vector<int> rowIndices);

	void fillRow(int rowIndex, int content);

	void copyRowIntoRow(int sourceRowIndex,
						int targetRowIndex);

	int grid[MAX_X][MAX_Y];				
	const Point spawnLoc {MAX_X/2, 0};	

	friend class TestSuite;				
*/