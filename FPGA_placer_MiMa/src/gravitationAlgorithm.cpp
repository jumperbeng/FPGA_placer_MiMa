/*
 * gravitationAlgorithm.cpp
 *
 *  Created on: 2016��10��12��
 *      Author: zwangaj
 */
#include "gravitationAlgorithm.h"

void moveByForce(){
	for(int i=0;i<totalCellNumber;i++){
		if(!cellRecords[i].getFM())
			continue;

		//Cell tempCell = cellRecords[i];
		int tempX = cellRecords[i].getX();
		int tempY = cellRecords[i].getY();
		int xMassCenter = 0;
		int yMassCenter = 0;
		for(int j = 0;j < cellRecords[i].net.size();j++){
			//Net tempNet = netRecords[cellRecords[i].net[j]];
			xMassCenter += netRecords[cellRecords[i].net[j]].getXCenter();
			yMassCenter += netRecords[cellRecords[i].net[j]].getYCenter();
		}

		xMassCenter /= cellRecords[i].net.size();
		yMassCenter /= cellRecords[i].net.size();
		cout<<"a "<<" "<<xMassCenter<<" "<< yMassCenter<<endl;

		int newX = tempX+gFactor*(xMassCenter-tempX);
		int newY = tempY+gFactor*(yMassCenter-tempY);

		if((!validMap[newX][newY])||(siteMap[newX][newY]!=cellRecords[i].getType())||(isCrowded(newX,newY))){
			relocate(newX,newY,tempX,tempY,cellRecords[i].getType());
		}

		cellRecords[i].editXY(newX,newY);
		validMap[newX][newY]=false;
		cellRecords[i].updateCost();
	}
	update();
}

void update(){
	for(int i=0;i<totalNetNumber;i++){
		if(netRecords[i].isModified()){
			netRecords[i].updateCost();
		}
	}
}

void relocate(int& x,int& y,int x_prev,int y_prev,int type){
	int xDiff=abs(x-x_prev);
	int yDiff=abs(y-y_prev);
	int xSign, ySign;
	int tempX=x;
	int tempY=y;
	if(x_prev<x)
		xSign=-1;
	else if(x_prev==x)
		xSign=0;
	else
		xSign=1;

	if(y_prev<y)
		ySign=-1;
	else if(y_prev==y)
		ySign=0;
	else
		ySign=1;

	for(int sum=1;sum<=xDiff+yDiff;sum++){
		for(int i=max(0,sum-yDiff); i<=min(xDiff,sum); i++){
			tempX=x+xSign*i;
			tempY=y+ySign*(sum-i);
			if((validMap[tempX][tempY])&&(siteMap[tempX][tempY]==type)&&(!isCrowded(tempX,tempY))){
				x=tempX;
				y=tempY;
				return;
			}
		}
	}
	x=x_prev;
	y=y_prev;
	return;
}
