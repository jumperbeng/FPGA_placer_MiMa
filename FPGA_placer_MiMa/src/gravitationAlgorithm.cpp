/*
 * gravitationAlgorithm.cpp
 *
 *  Created on: 2016ï¿½ï¿½10ï¿½ï¿½12ï¿½ï¿½
 *      Author: zwangaj
 */
#include "gravitationAlgorithm.h"

double diffusion(){
	int tempX, tempY, newX, newY;
	for(int i=0;i<totalCellNumber;i++){
		if(!cellRecords[i].getFM())
			continue;
		tempX = cellRecords[i].getX();
		tempY = cellRecords[i].getY();
		newX = tempX+ABUMap[tempX/6][tempY/6].xStep;
		newY = tempY+ABUMap[tempX/6][tempY/6].yStep;
		newX=min(site.getWidth()-1,newX);
		newX=max(0,newX);
		newY=min(site.getHeight()-1,newY);
		newY=max(0,newY);

		site.setValid(tempX,tempY,true);
		if((!site.getValid(newX,newY))||(site.getType(newX,newY)!=cellRecords[i].getType())||(isCrowded(newX,newY))){
			relocate(newX,newY,tempX,tempY,cellRecords[i].getType());
		}

		if(site.getValid(newX,newY)){
			updateABU(tempX/6, tempY/6, newX/6, newY/6);
		}else{
			if((site.getType(newX,newY)==CLB)&&(cellRecords[i].getType()!=CLB))
				updateABU(newX/6, newY/6, tempX/6, tempY/6);
			if((site.getType(newX,newY)!=CLB)&&(cellRecords[i].getType()==CLB))
				updateABU(tempX/6, tempY/6, newX/6, newY/6);
		}

		cellRecords[i].editXY(newX,newY);
		site.setValid(newX,newY,false);
		site.insertCell(newX,newY,i);

		cellRecords[i].updateCost();
	}
	update();
	return calculateABU10();
}

int moveByForce(){
	int movedObjects=0;
	int tempX, tempY, xMassCenter, yMassCenter;
	for(int i=0;i<totalCellNumber;i++){
		if(!cellRecords[i].getFM())
			continue;

		//Cell tempCell = cellRecords[i];
		tempX = cellRecords[i].getX();
		tempY = cellRecords[i].getY();
		xMassCenter = 0;
		yMassCenter = 0;
		for(int j = 0;j < cellRecords[i].net.size();j++){
			//Net tempNet = netRecords[cellRecords[i].net[j]];
			xMassCenter += netRecords[cellRecords[i].net[j]].getXCenter();
			yMassCenter += netRecords[cellRecords[i].net[j]].getYCenter();
		}

		xMassCenter /= cellRecords[i].net.size();
		yMassCenter /= cellRecords[i].net.size();

		int newX = tempX+gFactor*(xMassCenter-tempX);
		int newY = tempY+gFactor*(yMassCenter-tempY);

		site.setValid(tempX,tempY,true);
		if((!site.getValid(newX,newY))||(site.getType(newX,newY)!=cellRecords[i].getType())||(isCrowded(newX,newY))){
			if(relocate(newX,newY,tempX,tempY,cellRecords[i].getType()))
				movedObjects--;
		}
		movedObjects++;

		if(site.getValid(newX,newY)){
			updateABU(tempX/6, tempY/6, newX/6, newY/6);
		}else{
			if((site.getType(newX,newY)==CLB)&&(cellRecords[i].getType()!=CLB))
				updateABU(newX/6, newY/6, tempX/6, tempY);
			if((site.getType(newX,newY)!=CLB)&&(cellRecords[i].getType()==CLB))
				updateABU(tempX/6, tempY/6, newX/6, newY/6);
		}
		cellRecords[i].editXY(newX,newY);
		site.setValid(newX,newY,false);
		site.insertCell(newX,newY,i);

		cellRecords[i].updateCost();
	}
	update();
	return movedObjects;
}

void update(){
	for(int i=0;i<totalNetNumber;i++){
		if(netRecords[i].isModified()){
			netRecords[i].updateCost();
		}
	}
}

bool relocate(int& x,int& y,int x_prev,int y_prev,int type){
	int xDiff=abs(x-x_prev);
	int yDiff=abs(y-y_prev);
	int xSign, ySign;
	int tempX=x;
	int tempY=y;
	int tempCell;
	int randNum;
	double currentTemp;
	double prob;
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

	for(int sum=0;sum<xDiff+yDiff;sum++){
		for(int i=max(0,sum-yDiff); i<=min(xDiff,sum); i++){
			tempX=x+xSign*i;
			tempY=y+ySign*(sum-i);
			if((site.getValid(tempX,tempY))&&(site.getType(tempX,tempY)==type)&&(!isCrowded(tempX,tempY))){/*Find a space*/
				x=tempX;
				y=tempY;
				return false;
			}
			tempCell=site.getResident(tempX, tempY);
			currentTemp=(double)(clock() - tStart)/CLOCKS_PER_SEC;
			prob=exp(-currentTemp);
			srand(time(NULL)); //Éú²úËæ»úÊýÖÖ×Ó
			randNum = rand()*10000/(RAND_MAX+1);
			if((!site.getValid(tempX,tempY))&&(randNum<10000*prob)){/*Swap*/
				x=tempX;
				y=tempY;
				cellRecords[tempCell].editXY(x_prev, y_prev);
				site.setValid(x_prev, y_prev,false);
				site.insertCell(x_prev, y_prev,tempCell);
				return false;
			}
		}
	}
	x=x_prev;
	y=y_prev;
	return true;	/*True means the relocation fails*/
}
