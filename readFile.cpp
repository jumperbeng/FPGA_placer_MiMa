/*
 * readFile.cpp
 *
 *  Created on: 2016Äê10ÔÂ3ÈÕ
 *      Author: zwangaj
 */

#include "readFile.h"

void readSitemap(const char* file){

	ifstream inFile(file);
	string line;
	int siteWidth,siteHeight;
	int x;
	int y;
	int cellType;
	string 	siteWidth_temp,siteHeight_temp, cellType_temp, x_temp, y_temp;

	if(!inFile){
		cout<<"File Name Error!"<<endl;
		return;
	}


	getline(inFile, line);
	stringstream stringin(line);
	stringin >> siteWidth_temp;
	stringin >> siteHeight_temp;
	siteWidth=atoi(siteWidth_temp.c_str());
	siteHeight=atoi(siteHeight_temp.c_str());

	siteMap.resize(siteWidth);
	validMap.resize(siteWidth);
	for (int h = 0; h < siteWidth; h++) {
		siteMap[h].resize(siteHeight);
		validMap[h].resize(siteHeight);
	}

	while(!inFile.eof()){
		getline(inFile, line);
		stringstream stringin(line);
		stringin >> x_temp;
		stringin >> y_temp;
		stringin >> cellType_temp;
		x=atoi(x_temp.c_str());
		y=atoi(y_temp.c_str());
		if(!strcmp(cellType_temp.c_str(),"INVALID"))
			cellType=INVALID;
		else if(!strcmp(cellType_temp.c_str(),"CLB"))
			cellType=CLB;
		else if(!strcmp(cellType_temp.c_str(),"IO"))
			cellType=IO;
		else if(!strcmp(cellType_temp.c_str(),"DSP"))
			cellType=DSP;
		else if(!strcmp(cellType_temp.c_str(),"RAM"))
			cellType=INVALID;
		siteMap[x][y]=cellType;
	}
	inFile.close();
}

void readNets(const char* file){
	ifstream inFile(file);
	string line;
	string netName,cellName;
	int temp;
	vector<int> cellList;
    while(!inFile.eof()){
    	getline(inFile, line);
		stringstream stringin(line);
		cellList.clear();

		if(stringin >> netName){
			while (stringin >> cellName) {
				temp=atoi(cellName.substr(5).c_str());
				cellList.push_back(temp);
			}
		}
		Net tempNet(netName,cellList);
		netRecords.push_back(tempNet);
	}
	inFile.close();
}

void readPl(const char* file){

	ifstream inFile(file);
	string line;
	int cellIndex, x, y, cellType, cellFM;
	string cellName, cellType_temp, x_temp, y_temp;
	char cellFM_temp;

    while(!inFile.eof()){
    	getline(inFile, line);
		stringstream stringin(line);
		if(stringin >> cellName){
			cellIndex=atoi(cellName.substr(5).c_str());
			stringin >> cellType_temp;
			stringin >> x_temp;
			stringin >> y_temp;
			stringin >> cellFM_temp;
			x=atoi(x_temp.c_str());
			y=atoi(y_temp.c_str());

			if(!strcmp(cellType_temp.c_str(),"CLB"))
				cellType=CLB;
			else if(!strcmp(cellType_temp.c_str(),"IO"))
				cellType=IO;
			else if(!strcmp(cellType_temp.c_str(),"DSP"))
				cellType=DSP;
			else if(!strcmp(cellType_temp.c_str(),"RAM"))
				cellType=INVALID;

			if(cellFM_temp=='F')
				cellFM=FIXED;
			else if(cellFM_temp=='M')
				cellFM=MOVED;

			validMap[x][y] = true;
			Cell tempCell(cellIndex, x, y, cellType, cellFM);
			cellRecords.push_back(tempCell);
		}
	}
	inFile.close();
}
