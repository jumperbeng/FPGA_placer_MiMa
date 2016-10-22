/*
 * Net.h
 *
 *  Created on: 2016Äê10ÔÂ3ÈÕ
 *      Author: zwangaj
 */

#ifndef NET_H_
#define NET_H_
#include "main.h"
#include "global.h"


class Net {
public:
	Net();
	Net(int index, string name, vector<int> nodeList);
	virtual ~Net();


	string getName();
	int getSize();
	int getNode(int num);
	int getCost();
	int getXMin();
	int getXMax();
	int getYMin();
	int getYMax();
	int getXCenter();
	int getYCenter();
	bool isModified();

	int updateCost();
	void modify();

private:
	int netIndex;
	string netName;
	int cost;
	int cellNum;
	vector<int> cellList;

	int xMin;
	int xMax;
	int yMin;
	int yMax;

	bool modified;
};

#endif /* NET_H_ */
