/*
 * commonAlgorithm.h
 *
 *  Created on: 2016Äê10ÔÂ16ÈÕ
 *      Author: zwangaj
 */

#ifndef COMMONALGORITHM_H_
#define COMMONALGORITHM_H_

#include "main.h"
#include "global.h"

void updateABU();
void updateABU(int x_prev, int y_prev, int x_next, int y_next);
double calculateABU10();
bool isCrowded(int x,int y);



#endif /* COMMONALGORITHM_H_ */
