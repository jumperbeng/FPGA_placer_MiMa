/*
 * Net.cpp
 *
 *  Created on: 2016Äê10ÔÂ3ÈÕ
 *      Author: zwangaj
 */

#include "Net.h"

Net::Net() {
	cost=0;
	cellNum=0;
	xMin=0;
	xMax=0;
	yMin=0;
	yMax=0;
}

Net::Net(string name, vector<int> nodeList){
	netName=name;
	cellList=nodeList;
	cellNum=cellList.size();
	xMin=0;
	xMax=0;
	yMin=0;
	yMax=0;
	updateCost();
}

Net::~Net() {
	// TODO Auto-generated destructor stub
}

string Net::getName(){
	return netName;
}

int Net::getCost(){
	return cost;
}

int Net::updateCost(){
	int i = 0;
	int x0 = cellRecords[cellList[0]].getX();
	int y0 = cellRecords[cellList[0]].getY();
	if (cellNum % 2) {
		xMin = x0;
		xMax = x0;
		yMin = y0;
		yMax = y0;
		i = 1;
	}else{
		int x1 = cellRecords[cellList[1]].getX();
		int y1 = cellRecords[cellList[1]].getY();
		if (x0 < x1) {
			xMin = x0;
			xMax = x1;
		}else{
			xMin = x1;
			xMax = x0;
		}
		if (y0 < y1) {
			yMin = y0;
			yMax = y1;
		}else {
			yMin = y1;
			yMax = y0;
		}
		i = 2;
	}

	for(i;i<cellNum;i=i+2){
		int xi0 = cellRecords[cellList[i]].getX();
		int yi0 = cellRecords[cellList[i]].getY();
		int xi1 = cellRecords[cellList[i+1]].getX();
		int yi1 = cellRecords[cellList[i+1]].getY();

		if (xi0 < xi1) {
			if (xi0 < xMin) xMin = xi0;
			if (xi1 > xMax) xMax = xi1;
		}else {
			if (xi1 < xMin) xMin = xi1;
			if (xi0 > xMax) xMax = xi0;
		}

		if (yi0 < yi1) {
			if (yi0 < yMin) yMin = yi0;
			if (yi1 > yMax) yMax = yi1;
		}else {
			if (yi1 < yMin) yMin = yi1;
			if (yi0 > yMax) yMax = yi0;
		}
	}

	cost = (xMax - xMin) + (yMax - yMin);
	return cost;
}

int Net::getSize(){
	return cellNum;
}
int Net::getNode(int num){
	return cellList[num];
}
