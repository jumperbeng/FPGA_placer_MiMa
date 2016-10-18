/*
 * commonAlgorithm.cpp
 *
 *  Created on: 2016Äê10ÔÂ16ÈÕ
 *      Author: zwangaj
 */

#include "commonAlgorithm.h"

void updateABU(){
	for(int x=0;x<siteMap.size();x++){
		for(int y=0;y<siteMap[0].size();y++){
			if(siteMap[x][y]){
				ABUMap[x/6][y/6]++;
			}
		}
	}
}

void updateABU(int x_prev, int y_prev, int x_next, int y_next){
	ABUMap[x_prev/6][y_prev/6]--;
	ABUMap[x_next/6][y_next/6]++;
}

bool isCrowded(int x,int y){
	if(ABUMap[x/6][y/6]>=CROWDED*36)
		return true;
	return false;
}
