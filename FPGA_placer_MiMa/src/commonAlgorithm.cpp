/*
 * commonAlgorithm.cpp
 *
 *  Created on: 2016Äê10ÔÂ16ÈÕ
 *      Author: zwangaj
 */

#include "commonAlgorithm.h"

void updateABU(){
	for(int x=0;x<ABUMap.size();x++){
		for(int y=0;y<ABUMap[0].size();y++){
				ABUMap[x][y].cellCount=0;
				ABUMap[x][y].CLBCount=0;
		}
	}

	for(int x=0;x<site.getWidth();x++){
		for(int y=0;y<site.getHeight();y++){
			if(site.getType(x,y)==CLB){
				ABUMap[x/6][y/6].CLBCount++;
				if(!site.getValid(x,y)){
					ABUMap[x/6][y/6].cellCount++;
				}
			}
		}
	}

	for(int x=0;x<ABUMap.size();x++){
		for(int y=0;y<ABUMap[0].size();y++){
				ABUMap[x][y].density=ABUMap[x][y].cellCount*1.0/ABUMap[x][y].CLBCount;
		}
	}


	for(int x=1;x<ABUMap.size()-2;x++){
		for(int y=1;y<ABUMap[0].size()-2;y++){
			ABUMap[x][y].xStep=diffuseCoeff*(ABUMap[x-1][y].density-ABUMap[x+1][y].density)/(1.1-ABUMap[x][y].density);/*rightwards*/
			ABUMap[x][y].yStep=diffuseCoeff*(ABUMap[x][y-1].density-ABUMap[x][y+1].density)/(1.1-ABUMap[x][y].density);/*downwards*/
		}
	}
}

void updateABU(int x_prev, int y_prev, int x_next, int y_next){/*Move a CLB from (x_prev,y_prev) to (x_next,y_next)*/
	ABUMap[x_prev][y_prev].cellCount--;
	ABUMap[x_prev][y_prev].density=ABUMap[x_prev][y_prev].cellCount*1.0/ABUMap[x_prev][y_prev].CLBCount;
	if((x_prev>1)&&(x_prev<ABUMap.size()-2)){
		ABUMap[x_prev-1][y_prev].xStep=diffuseCoeff*(ABUMap[x_prev-2][y_prev].density-ABUMap[x_prev][y_prev].density)/(1.1-ABUMap[x_prev-1][y_prev].density);/*rightwards*/
		ABUMap[x_prev+1][y_prev].xStep=diffuseCoeff*(ABUMap[x_prev][y_prev].density-ABUMap[x_prev+2][y_prev].density)/(1.1-ABUMap[x_prev+1][y_prev].density);/*rightwards*/
	}
	if((y_prev>1)&&(y_prev<ABUMap.size()-2)){
		ABUMap[x_prev][y_prev-1].yStep=diffuseCoeff*(ABUMap[x_prev][y_prev-2].density-ABUMap[x_prev][y_prev].density)/(1.1-ABUMap[x_prev][y_prev-1].density);/*rightwards*/
		ABUMap[x_prev][y_prev+1].yStep=diffuseCoeff*(ABUMap[x_prev][y_prev].density-ABUMap[x_prev][y_prev+2].density)/(1.1-ABUMap[x_prev][y_prev+1].density);/*rightwards*/
	}

	ABUMap[x_next][y_next].cellCount++;
	ABUMap[x_next][y_next].density=ABUMap[x_next][y_next].cellCount*1.0/ABUMap[x_next][y_next].CLBCount;
	if((x_next>1)&&(x_next<ABUMap.size()-2)){
		ABUMap[x_next-1][y_next].xStep=diffuseCoeff*(ABUMap[x_next-2][y_next].density-ABUMap[x_next][y_next].density)/(1.1-ABUMap[x_next-1][y_next].density);/*rightwards*/
		ABUMap[x_next+1][y_next].xStep=diffuseCoeff*(ABUMap[x_next][y_next].density-ABUMap[x_next+2][y_next].density)/(1.1-ABUMap[x_next+1][y_next].density);/*rightwards*/
	}
	if((y_next>1)&&(y_next<ABUMap.size()-2)){
		ABUMap[x_next][y_next-1].yStep=diffuseCoeff*(ABUMap[x_next][y_next-2].density-ABUMap[x_next][y_next].density)/(1.1-ABUMap[x_next][y_next-1].density+1);/*rightwards*/
		ABUMap[x_next][y_next+1].yStep=diffuseCoeff*(ABUMap[x_next][y_next].density-ABUMap[x_next][y_next+2].density)/(1.1-ABUMap[x_next][y_next+1].density);/*rightwards*/
	}
}

double calculateABU10(){

	double maxDens=ABUMap[0][0].density;
	double minDens=1;
	for(int i=0;i<ABUMap.size();i++){
		for(int j=0;j<ABUMap[0].size();j++){
			if(ABUMap[i][j].density>maxDens)
				maxDens=ABUMap[i][j].density;
			if((ABUMap[i][j].density<minDens)&&(ABUMap[i][j].density>0))
				minDens=ABUMap[i][j].density;
		}
	}
	return 0.1*minDens+0.9*maxDens;
}

bool isCrowded(int x,int y){
	if(ABUMap[x/6][y/6].density>=CROWDED)
		return true;
	return false;
}
