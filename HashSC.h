#ifndef HASHSC_H
#define HASHSC_H
#include <iostream>
#include <list>
#include <string>
/****************************************************
*Author: Joshua Standerfer
*Date: 12-3-18
*Assignment 5
*Desc: HashSC is a generic class with creates a hashed table with seperate chaining. It can handle
*keys up to size unsigned long long. 
*/
using namespace std;
template <class T>
class HashSC{
	//No. of spots a linked list will inhabit
	int bucket;

	//pointer to  what will be defined later as an array of buckets
	list<T> *table;

public:
	//Constructor
	HashSC(int);

	int hasher(unsigned long long int);

	void insertItem(unsigned long long int, T&);

	void deleteItem(unsigned long long int, T&);

	void find(T&);

	void destroyTable();

	~HashSC();
};
template <class T>
HashSC<T>::HashSC(int b) {
	bucket = b;
	//defining the list
	table = new list<T>[bucket];
}

template <class T>
int HashSC<T>::hasher(unsigned long long int key) {
	int hashedKey = key % bucket;
	return hashedKey;
}

template <class T>
inline void HashSC<T>::insertItem(unsigned long long key,T &item){
	int index = hasher(key);
	table[hasher(index)].push_front(item);
}

template <class T>
void HashSC<T>::deleteItem(unsigned long long int key, T &item) {
	int index = hasher(key);
	//need to look through list. Iteration
	typename list<T> ::iterator n;
	for (n = table[index].begin(); n != table[index].end(); n++) {
		if (*n == item)
			break;
	}
	if (n != table[index].end()) {
		table[index].erase(n);
	}
}
template <class T>
void HashSC<T>::find(T& item) {
	unsigned long long int key;
	int index = hasher(key);
	typename list<T>::iterator n;
	for (n = table[index].begin(); n != table[index].end(); n++) {
		if (*n == item) {
			cout << item;
			break;
		}
	}
}
template <class T>
void HashSC<T>::destroyTable() {
	for (int i = 0; i < bucket; i++)
		//unsure if <list> will automatically handle this when table is deleted or not
		table[i].~list();
	delete[] table;
}

template <class T>
HashSC<T>::~HashSC() {
	destroyTable();
}
#endif
