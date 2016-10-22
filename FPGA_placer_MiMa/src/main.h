/*
 * main.h
 *
 *  Created on: 2016Äê10ÔÂ3ÈÕ
 *      Author: zwangaj
 */

#ifndef MAIN_H_
#define MAIN_H_

#define MAX_NET  10000
#define MAX_CELL 10000

using namespace std;

#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <vector>

#include "global.h"

#include "fileIO.h"

#include "Cell.h"
#include "Map.h"
#include "Net.h"

#include "commonAlgorithm.h"
#include "gravitationAlgorithm.h"


enum type {INVALID, CLB, DSP, RAM, IO};
enum FM {FIXED, MOVED};

extern clock_t tStart;

#endif /* MAIN_H_ */
