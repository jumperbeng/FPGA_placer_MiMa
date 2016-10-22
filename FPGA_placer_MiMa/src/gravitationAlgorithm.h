/*
 * gravitationAlgorithm.h
 *
 *  Created on: 2016��10��12��
 *      Author: zwangaj
 */

#ifndef GRAVITATIONALGORITHM_H_
#define GRAVITATIONALGORITHM_H_

#include "main.h"
#include "global.h"

double diffusion();
int moveByForce();
void update();
bool relocate(int& x,int& y,int x_prev,int y_prev,int type);

extern clock_t tStart;

#endif /* GRAVITATIONALGORITHM_H_ */
