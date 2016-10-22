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
#include "global.h"


void readSitemap(const char* file);
void readPl(const char* file);
void readNets(const char* file);

void writePl(const char* file);
void writeABU(const char* file);
void writeSite(const char* file);

#endif /* FILEIO_H_ */
