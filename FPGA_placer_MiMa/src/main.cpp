/*
 * main.cpp
 *
 *  Created on: 2016��10��3��
 *      Author: zwangaj
 */

#include "main.h"

clock_t tStart = clock();

int main(){

	/*
	 *The code for read the sitemap
	 **
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
	*

	/*
	 *The code for read the cells
	 **
	readPl("FPGA-example1.pl");
	/*
	cout<<cellRecords.size()<<endl;
	for(int p=0;p<cellRecords.size();p++){
		cout<<cellRecords[p].getIndex()<<endl;
	}
	*

	/*
	 *The code for read the nets
	 **
	readNets("FPGA-example1.nets");
	/*
	cout<<netRecords.size()<<endl;
	for(int p=0;p<netRecords.size();p++){
		cout<<netRecords[p].getName()<<endl;
		for(int q=0;q<netRecords[p].getSize();q++)
			cout<<netRecords[p].getNode(q)<<" ";
		cout<<endl;
	}
	*

	while(moveByForce()>5);
	writePl("result.pl");
	*/

	/*
	readSitemap("FPGA-example1.sitemap");
	readPl("FPGA-example1.pl");
	readNets("FPGA-example1.nets");
	while(moveByForce());
	writePl("result.pl");
	printf("Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	cout<<"The program has been finished!"<<endl;
*/

	/*
	readSitemap("FPGA01/FPGA01.sitemap");
	readPl("FPGA01/FPGA01.pl");
	readNets("FPGA01/FPGA01.nets");
	updateABU();

	int h=site.getHeight();
	int w=site.getWidth();
	writeABU("FPGA01/pre.abu");
	while(diffusion()>CROWDED*36);
	cout<<endl;
	writeABU("FPGA01/post.abu");
	while(moveByForce());
	writeABU("FPGA01/afterPlacement.abu");
	writePl("FPGA01/result01.pl");
	printf("Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	cout<<"The program has been finished!"<<endl;
	*/
	
	readSitemap("FPGA01/FPGA01.sitemap");
	readPl("FPGA01/FPGA01.pl");
	readNets("FPGA01/FPGA01.nets");

	writeSite("FPGA01/pre");

	updateABU();

	int h=site.getHeight();
	int w=site.getWidth();
	writeABU("FPGA01/pre.abu");

	double d;
	do{
		d=diffusion();
		cout<<d<<endl;
	}while(d>CROWDED);

	writeABU("FPGA01/post.abu");

	int i;
	do{
		i=moveByForce();
		cout<<i<<endl;
	}while(i);

	int count=0;
	do{
		while(diffusion()>CROWDED)
			count++;
		while(moveByForce());
	}while(count);

	writeABU("FPGA01/afterPlacement.abu");
	writePl("FPGA01/result01.pl");
	printf("Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	cout<<"The program has been finished!"<<endl;	
	return 0;
}


