/*
 * gravitationAlgorithm.h
 *
 *  Created on: 2016Äê10ÔÂ12ÈÕ
 *      Author: zwangaj
 */

#ifndef GRAVITATIONALGORITHM_H_
#define GRAVITATIONALGORITHM_H_

#include "main.h"
#define gFactor 0.9

extern vector<vector<int> > siteMap;
extern vector<vector<bool> > validMap;
extern vector<vector<int> > ABUMap;
extern vector<Net> netRecords;
extern vector<Cell> cellRecords;
extern int totalNetNumber;
extern int totalCellNumber;

void moveByForce();
void update();
void relocate(int& x,int& y,int x_prev,int y_prev,int type);

#endif /* GRAVITATIONALGORITHM_H_ */
