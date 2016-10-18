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

Cell::Cell(int index, int x_cord, int y_cord, int nodeType, bool nodeFM){
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

int Cell::getType(){
	return cellType;
}

bool Cell::getFM(){
	return 	cellFM;
}

void Cell::editX(int newX){
	x=newX;
	updateCost();
}

void Cell::editY(int newY){
	y=newY;
	updateCost();
}

void Cell::editXY(int newX,int newY){
	x=newX;
	y=newY;
	updateCost();
}

void Cell::updateCost(){
	for(int i=0;i<net.size();i++){
		netRecords[net[i]].modify();
	}
}
