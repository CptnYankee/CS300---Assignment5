#include "HashSC.h"
#include "BarcodeItem.h"
#include <string>
#include <fstream>
#include <time.h>
#include <iostream>
/****************************************************************
 * Author: Joshua Standerfer					*
 * Date: 12-3-18						*
 * Desc: This is the main method which tests the time take	*
 *  for a hash table to allocate and then find 			*
 * a key value pair of UPC items.				*
 * *************************************************************/
using namespace std;
int main() {
	cout<<"test"<<endl;
	clock_t t;
	t = clock();
	string code;
	//info is the rest of the information 
	string info;
	//stores each line before we put it into a BarcodeItem
	string line;
	fstream aFile;
	aFile.open("upc_corpus.txt");
	//skips the first line
	string dummy;
	getline(aFile, dummy);

	HashSC<BarcodeItem> hashTable(1000);
	cout<<"test";
	cin>>dummy;
	int i = 0;
	int j = 10;
	//change j to the any int to limit the number of items in the tree
	while (getline(aFile, line) && i < j) {
		//	try{
				//make sure we have a UPC code delimited by ','
		string::size_type loc;
		//we only care about the first comma
		loc = line.find(',', 0);
		code = line.substr(0, loc);
		info = line.substr(loc + 1);

		BarcodeItem item(code, info);
		hashTable.insertItem(item.getKey(), item);
		i++;
	}
	cout<<"Enter UPC Code: ";
	string key;
	cin >> key;
	//create a dummy barcode item to compare in the list
	BarcodeItem temp(key, dummy);
	//note: Ideally we would have a HashSC that extends a scanner so we could use .getKey() inside HashSC. But I ran out of time.
	//This works because barcodeitem == operator only compares keys
	hashTable.find(temp);

	aFile.close();

	t = clock() - t;
	cout << "time: " << t << "milliseconds" << endl;
	cout << CLOCKS_PER_SEC << "clocks per second" << endl;
	cout << "time: " << t * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
}
