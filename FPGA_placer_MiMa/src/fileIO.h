/*
 * readFile.h
 *
 *  Created on: 2016Äê10ÔÂ3ÈÕ
 *      Author: zwangaj
 */

#ifndef FILEIO_H_
#define FILEIO_H_
using namespace std;

#include "main.h"
class Cell;
class Net;

extern vector<vector<int> > siteMap;
extern vector<vector<bool> > validMap;
extern vector<vector<int> > ABUMap;
extern vector<Net> netRecords;
extern vector<Cell> cellRecords;
extern int totalNetNumber;
extern int totalCellNumber;

void readSitemap(const char* file);
void readPl(const char* file);
void readNets(const char* file);

void writePl(const char* file);

#endif /* FILEIO_H_ */
