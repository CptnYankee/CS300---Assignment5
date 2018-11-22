//BarcodeItem.h
#ifndef BARCODEITEM_H
#define BARCODEITEM_H
#include <string>
#include <iostream>
/********************************************************
 *Author:Joshua Standerfer				*
 *Date:11-21-18						*
 *Desc:This is a simple class to contain a UPC code	*
 *and the information about the UPC code.		*
 ********************************************************/
class BarcodeItem {
	private:

		std::string key;
		std::string info;
	public:		
		BarcodeItem();
		BarcodeItem(std::string, std::string);
		
		std::string getKey();

		friend bool operator> (const BarcodeItem&, const BarcodeItem&);
		friend bool operator< (const BarcodeItem&, const BarcodeItem&);
		//void operator=(const BarcodeItem&);
		friend std::ostream& operator<<(std::ostream &out, const BarcodeItem &item);

};
//default constructor
BarcodeItem::BarcodeItem() {
	key = "0";
	info = "0";
}
//constructor
BarcodeItem::BarcodeItem(std::string _key, std::string _info){
		key = _key;
		info = _info;
}
	
std::string BarcodeItem::getKey(){
	return key;
}
//overrides
bool operator>(const BarcodeItem& a, const BarcodeItem& other){
	return a.key>other.key;
}
bool operator<(const BarcodeItem& a, const BarcodeItem& other){
	return a.key<other.key;
}
//didn't end up needing this
/*BarcodeItem::operator=(const BarcodeItem& other){
	this->key = other.key;
	this->info = other.info;
}*/

std::ostream& operator<<(std::ostream &out, const BarcodeItem &item) {
	out << "UPC: " << item.key << std::endl << item.info << std::endl;
	return out;
}
#endif
