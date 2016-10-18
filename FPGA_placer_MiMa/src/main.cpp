/*
 * main.cpp
 *
 *  Created on: 2016��10��3��
 *      Author: zwangaj
 */

#include "main.h"

vector<vector<int> > siteMap;   /*Define the type of each location*/
vector<vector<bool> > validMap; /*Record whether a location is empty*/
vector<vector<int> > ABUMap;	/*Record whether a Bin is crowded*/
vector<Net> netRecords;			/*Record all nets*/
vector<Cell> cellRecords;		/*Record all cells*/
int totalNetNumber;
int totalCellNumber;

int main(){
	/*
	 *The code for read the sitemap
	 **/
	readSitemap("FPGA-example1.sitemap");

	/*
	int h=siteMap[0].size();
	int w=siteMap.size();
	for(int j=0;j<h;j++){//jth row
		for(int i=0;i<w;i++)//ith column
			cout<<siteMap[i][j]<<" ";
		cout<<endl;
	}

	for(int j=0;j<ceil(h/6.0);j++){//jth row
		for(int i=0;i<ceil(w/6.0);i++)//ith column
			cout<<ABUMap[i][j]<<" ";
		cout<<endl;
	}
	*/

	/*
	 *The code for read the cells
	 **/
	readPl("FPGA-example1.pl");
	/*
	cout<<cellRecords.size()<<endl;
	for(int p=0;p<cellRecords.size();p++){
		cout<<cellRecords[p].getIndex()<<endl;
	}
	*/

	/*
	 *The code for read the nets
	 **/
	readNets("FPGA-example1.nets");
	/*
	cout<<netRecords.size()<<endl;
	for(int p=0;p<netRecords.size();p++){
		cout<<netRecords[p].getName()<<endl;
		for(int q=0;q<netRecords[p].getSize();q++)
			cout<<netRecords[p].getNode(q)<<" ";
		cout<<endl;
	}
	*/
	moveByForce();
	writePl("result.pl");

	cout<<"The program has been finished!"<<endl;
	//cout<<"All codes have been tested by Jumper WANG"<<endl;
	return 0;
}


