/*
 * readFile.h
 *
 *  Created on: 2016Äê10ÔÂ3ÈÕ
 *      Author: zwangaj
 */

#ifndef READFILE_H_
#define READFILE_H_
using namespace std;

#include "main.h"
class Cell;
class Net;

extern vector<vector<int> > siteMap;
extern vector<vector<bool> > validMap;
extern vector<Net> netRecords;
extern vector<Cell> cellRecords;

void readSitemap(const char* file);
void readNets(const char* file);
void readPl(const char* file);

#endif /* READFILE_H_ */
