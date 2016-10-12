/*
 * Cell.cpp
 *
 *  Created on: 2016Äê10ÔÂ3ÈÕ
 *      Author: zwangaj
 */

#include "Cell.h"

Cell::Cell() {
	cellIndex=0;
	x=0;
	y=0;
}

Cell::Cell(int index, int x_cord, int y_cord, int nodeType, int nodeFM){
	cellIndex=index;
	x=x_cord;
	y=y_cord;
	cellType=nodeType;
	cellFM=nodeFM;
}

Cell::~Cell() {
	// TODO Auto-generated destructor stub
}

int Cell::getIndex(){
	return cellIndex;
}

int Cell::getX(){
	return x;
}

int Cell::getY(){
	return y;
}

void Cell::editX(int newX){
	x=newX;
}

void Cell::editY(int newY){
	y=newY;
}

int Cell::updateCost(){

	return 0;
}
