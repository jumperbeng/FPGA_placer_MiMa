/*
 * readFile.cpp
 *
 *  Created on: 2016Äê10ÔÂ3ÈÕ
 *      Author: zwangaj
 */

#include "fileIO.h"

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

	site.initial(siteWidth,siteHeight);
	ABUMap.resize(ceil(siteWidth/6.0));
	for (int h = 0; h < ceil(siteWidth/6.0); h++){
		ABUMap[h].resize(ceil(siteHeight/6.0));
	}

	while(!inFile.eof()){
		getline(inFile, line);
		stringstream stringin(line);
		stringin >> x_temp;
		stringin >> y_temp;
		stringin >> cellType_temp;
		x=atoi(x_temp.c_str());
		y=atoi(y_temp.c_str());
		if(!strcmp(cellType_temp.c_str(),"INVALID")){
			cellType=INVALID;
		}else if(!strcmp(cellType_temp.c_str(),"CLB")){
			cellType=CLB;
		}else if(!strcmp(cellType_temp.c_str(),"IO")){
			cellType=IO;
		}else if(!strcmp(cellType_temp.c_str(),"DSP")){
			cellType=DSP;
		}else if(!strcmp(cellType_temp.c_str(),"RAM")){
			cellType=RAM;
		}
		site.setType(x,y,cellType);
	}
	inFile.close();
}

void readPl(const char* file){
	ifstream inFile(file);
	string line;
	int cellIndex, x, y, cellType;
	bool cellFM;
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

			if(!strcmp(cellType_temp.c_str(),"CLB")){
				cellType=CLB;
			}else if(!strcmp(cellType_temp.c_str(),"IO")){
				cellType=IO;
			}else if(!strcmp(cellType_temp.c_str(),"DSP")){
				cellType=DSP;
			}else if(!strcmp(cellType_temp.c_str(),"RAM")){
				cellType=RAM;
			}

			if(cellFM_temp=='F')
				cellFM=FIXED;
			else if(cellFM_temp=='M')
				cellFM=MOVED;

			site.setValid(x,y,false);
			site.insertCell(x,y,cellIndex);
			Cell tempCell(cellIndex, x, y, cellType, cellFM);
			cellRecords.push_back(tempCell);
		}
	}
	inFile.close();
	totalCellNumber=cellRecords.size();
}

void readNets(const char* file){
	ifstream inFile(file);
	string line;
	string netName,cellName;
	int netNum,cellNum;
	vector<int> cellList;
	int index=0;
    while(!inFile.eof()){
    	getline(inFile, line);
		stringstream stringin(line);
		cellList.clear();

		if(stringin >> netName){
			netNum=atoi( netName.substr(4).c_str());
			while (stringin >> cellName) {
				cellNum=atoi(cellName.substr(5).c_str());
				cellList.push_back(cellNum);
				cellRecords[cellNum].net.push_back(index);
			}
			index++;
		}else
			continue;
		Net tempNet(index,netName,cellList);
		netRecords.push_back(tempNet);
	}
	inFile.close();
	totalNetNumber=netRecords.size();
}

void writePl(const char* file){
	ofstream outfile;
	outfile.open (file);
	if(outfile.is_open()){
		for(int i=0;i<totalCellNumber;i++){
			string type="xxx";
			char fm='x';
			switch(cellRecords[i].getType()){
				case INVALID:
					type="INVALID"; break;
				case CLB:
					type="CLB"; break;
				case DSP:
					type="DSP"; break;
				case RAM:
					type="RAM"; break;
				case IO:
					type="IO"; break;
				default:
					break;
			}
			switch(cellRecords[i].getFM()){
				case FIXED:
					fm='F'; break;
				case MOVED:
					fm='M'; break;
				default:
					break;
			}
			outfile << "cell_"<<cellRecords[i].getIndex()<<" "<<type<<" "<<cellRecords[i].getX()<<" "<<cellRecords[i].getY()<<" "<<fm<<endl;
		}
	}
	outfile.close();
}

void writeABU(const char* file){
	ofstream outfile;
	char str[80];
	strcpy (str,file);
	outfile.open (strcat (str,".counts"));
	if(outfile.is_open()){
		for(int j=0;j<ABUMap[0].size();j++){//jth row
			for(int i=0;i<ABUMap.size();i++)//ith column
				outfile<<(ABUMap[i][j].density)<<'\t';
				//outfile<<(ABUMap[i][j].density>CROWDED)<<'\t';
			outfile<<endl;
		}
	}
	outfile.close();

	strcpy (str,file);
	outfile.open (strcat (str,".x"));
	if(outfile.is_open()){
		for(int j=0;j<ABUMap[0].size();j++){//jth row
			for(int i=0;i<ABUMap.size();i++)//ith column
				outfile<<ABUMap[i][j].xStep<<'\t';
			outfile<<endl;
		}
	}
	outfile.close();
	strcpy (str,file);
	outfile.open (strcat (str,".y"));
	if(outfile.is_open()){
		for(int j=0;j<ABUMap[0].size();j++){//jth row
			for(int i=0;i<ABUMap.size();i++)//ith column
				outfile<<ABUMap[i][j].yStep<<'\t';
			outfile<<endl;
			}
	}
	outfile.close();

}

void writeSite(const char* file){
	ofstream outfile;
	char str[80];
	strcpy (str,file);
	outfile.open (strcat (str,".site"));
	if(outfile.is_open()){
		for(int j=0;j<site.getHeight();j++){//jth row
			for(int i=0;i<site.getWidth();i++)//ith column
				outfile<<(!site.getValid(i,j))<<'\t';
		outfile<<endl;
		}
	}
	outfile.close();
}
