/*
 * Cell.h
 *
 *  Created on: 2016Äê10ÔÂ3ÈÕ
 *      Author: zwangaj
 */

#ifndef CELL_H_
#define CELL_H_
#include "main.h"
#include "global.h"

class Cell {
public:
	Cell();
	Cell(int index, int x_cord, int y_cord, int nodeType, bool nodeFM);
	virtual ~Cell();
	int getIndex();
	int getX();
	int getY();
	int getType();
	bool getFM();
	void editX(int newX);
	void editY(int newY);
	void editXY(int newX,int newY);
	void updateCost();

	vector<int> net;

private:
	int cellIndex;
	int x;
	int y;
	int cellType;
	bool cellFM;
};

#endif /* CELL_H_ */
