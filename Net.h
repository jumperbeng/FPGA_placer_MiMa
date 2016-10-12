/*
 * Net.h
 *
 *  Created on: 2016Äê10ÔÂ3ÈÕ
 *      Author: zwangaj
 */

#ifndef NET_H_
#define NET_H_
#include "main.h"

extern vector<vector<int> > siteMap;
extern vector<vector<bool> > validMap;

class Net {
public:
	Net();
	Net(string name, vector<int> nodeList);
	virtual ~Net();
	string getName();
	int getCost();
	int updateCost();
	int getSize();
	int getNode(int num);

private:
	string netName;
	int cost;
	int cellNum;
	vector<int> cellList;

	int xMin;
	int xMax;
	int yMin;
	int yMax;
};

#endif /* NET_H_ */
