//BarcodeBSTScanner.cpp
#include "BinarySearchTree.h"
#include "BarcodeItem.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
/***********************************************************************
 * Author:Joshua Standerfer						*
 * Date:11-21-18							*
 * Desc:This uses a BinarySearchTree of BarcodeItems to store and search*
 * through a variable number of BarcodeItems. The time taken to find the*
 * Barcode item is recorded.						*	
 * *********************************************************************/

using namespace std;
int main(){
	//start timer!
	clock_t t;
	t = clock();

	BinarySearchTree<BarcodeItem>* tree = new BinarySearchTree<BarcodeItem>();
       //code is the UPC code	
	string code;
	//info is the rest of the information 
	string info;
	//stores each line before we put it into a BarcodeItem
	string line;

	fstream aFile;
	aFile.open("upc_corpus.txt");
	//skips the first line
	string dummy;
	getline(aFile,dummy);
	
	int i = 0;
	int j = 1000000;
	//change j to the any int to limit the number of items in the tree
	while(getline(aFile, line)&& i < j){
	//	try{
			//make sure we have a UPC code delimited by ','
			string::size_type loc;
			//we only care about the first comma
			loc = line.find(',',0);
			code = line.substr(0,loc);
			info = line.substr(loc+1);

			BarcodeItem item(code, info);
			tree->insert(item);
	//	}catch (const out_of_range& e){
	//		cout<<"string too short"<<endl;
	//	}
		i++;
	}
	BarcodeItem searchee(code,info);
	tree->search(searchee);
	//tree->printInOrder();
	aFile.close();
	
	

	t=clock() - t;
	cout<<"time: "<<t<<"milliseconds"<<endl;
	cout<<CLOCKS_PER_SEC<<"clocks per second"<<endl;
	cout<<"time: "<<t*1.0/CLOCKS_PER_SEC<<" seconds"<<endl;	

	return 0;
}
