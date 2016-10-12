/*
 * Cell.h
 *
 *  Created on: 2016Äê10ÔÂ3ÈÕ
 *      Author: zwangaj
 */

#ifndef CELL_H_
#define CELL_H_
#include "main.h"

extern vector<vector<int> > siteMap;
extern vector<vector<bool> > validMap;

class Cell {
public:
	Cell();
	Cell(int index, int x_cord, int y_cord, int nodeType, int nodeFM);
	virtual ~Cell();
	int getIndex();
	int getX();
	int getY();
	void editX(int newX);
	void editY(int newY);
	int updateCost();

private:
	int cellIndex;
	int x;
	int y;
	int cellType;
	int cellFM;
	int net[MAX_NET];
};

#endif /* CELL_H_ */
