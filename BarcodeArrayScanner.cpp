//BarcodeArrayScanner.cpp
#include "BarcodeItem.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
/****************************************************************************************
 *Author:Joshua Standerfer								*
 *Date:11-21-2018									*
 *Desc:This class uses an array of BarcodeItems to store data from		*
 *a file with barcode and descreiptions. It then measures the time taken to search	*
 *for an item in the tree.								*
 * *************************************************************************************/


using namespace std;
int main(){
	clock_t t;
	t = clock();

	//size limits the number of items we want in the array
	int size = 100;
	BarcodeItem* arr[size];
	string code;
	string info;
	string line;
	fstream aFile;
	aFile.open("upc_corpus.txt");
	string dummy;
	getline(aFile, dummy);
	
	int i = 0;
	while(getline(aFile,line) && i < size){
		try{
			string::size_type loc;
			loc = line.find(',',0);
			code = line.substr(0,loc);
			info = line.substr(loc+1);
			arr[i] = new BarcodeItem(code,info);
		}catch (const out_of_range& e){
			cout<<"string too short"<<endl;
		}
		i++;
	}
	
	for(int k = 0; k < size; k++){
		//simulate looking for the WORST case scenario
		string a = arr[k]->getKey();
		string b = arr[size-1]->getKey();
		if(a.compare(b)== 0){
			cout<<"item found"<<endl;
			break;
		}
	}
	for(int k = 0; k < size; k++)
		delete arr[k];
	/*
	for(int j = 0; j < size; j++){
		cout<<arr[j];
	}
	*/
	aFile.close();

	t=clock() - t;
	cout<<"time: "<<t<<"milliseconds"<<endl;
	cout<<CLOCKS_PER_SEC<<" clocks per second"<<endl;
	cout<<"time: "<<t*1.0/CLOCKS_PER_SEC<<" seconds"<<endl;

	return 0;
}

