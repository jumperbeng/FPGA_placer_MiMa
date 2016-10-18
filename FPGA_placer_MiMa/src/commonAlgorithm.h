/*
 * commonAlgorithm.h
 *
 *  Created on: 2016Äê10ÔÂ16ÈÕ
 *      Author: zwangaj
 */

#ifndef COMMONALGORITHM_H_
#define COMMONALGORITHM_H_

#define CROWDED 0.9

#include "main.h"

extern vector<vector<int> > siteMap;
extern vector<vector<bool> > validMap;
extern vector<vector<int> > ABUMap;
extern vector<Net> netRecords;
extern vector<Cell> cellRecords;
extern int totalNetNumber;
extern int totalCellNumber;

void updateABU();
void updateABU(int x_prev, int y_prev, int x_next, int y_next);
bool isCrowded(int x,int y);



#endif /* COMMONALGORITHM_H_ */
