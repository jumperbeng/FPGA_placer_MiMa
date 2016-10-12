/*
 * main.cpp
 *
 *  Created on: 2016Äê10ÔÂ3ÈÕ
 *      Author: zwangaj
 */

#include "main.h"

vector<vector<int> > siteMap;
vector<vector<bool> > validMap;
vector<Net> netRecords;
vector<Cell> cellRecords;

int main(){
	/*
	 *The code for read the sitemap
	 *
	readSitemap("FPGA-example1.sitemap");
	for(int j=0;j<168;j++){//jth row
		for(int i=0;i<168;i++)//ith column
			cout<<siteMap[i][j]<<" ";
		cout<<endl;
	}
	 */

	/*
	 *The code for read the nets
	 *
	readNets("FPGA-example1.nets");
	cout<<netRecord.size()<<endl;
	for(int p=0;p<netRecord.size();p++){
		cout<<netRecord[p].getName()<<endl;
		for(int q=0;q<netRecord[p].getSize();q++)
			cout<<netRecord[p].getNode(q)<<" ";
		cout<<endl;
	}
	*/

	/*
	 *The code for read the cells
	 *
	readPl("FPGA-example1.pl");
	cout<<cellRecord.size()<<endl;
	for(int p=0;p<cellRecord.size();p++){
		cout<<cellRecord[p].getIndex()<<endl;
	}
	*/

	cout<<"All codes have been tested by Jumper WANG"<<endl;
	cout<<"The functions related to the cost are not implemented yet."<<endl;
	return 0;
}


