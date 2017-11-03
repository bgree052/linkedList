#include <cstdlib>
#include <climits>

#include "SLList.hpp"

using namespace std;

SLList * const SLList::NIL = new SLList(0, NULL);

SLList::SLList(int i, SLList *n) {
	firstStorage = i;
	restStorage = n;
}

int SLList::first() {
	return firstStorage;
}

SLList *SLList::rest() {
	return restStorage;
}

void SLList::setFirst(int i) {
	firstStorage = i;
}

void SLList::setRest(SLList *n) {
	restStorage = n;
}

int SLList::nth(unsigned int i) {
	if (i == 0) {
		return first();
	}
	else {
		inc = 1;
		newRest = rest();
		while (inc < i) {
			inc++;
			newRest = newRest->rest();
		}
	}
	return newRest->first();
}

SLList *SLList::nthRest(unsigned int i) {
	if (i == 0) {
		return this;
	}
	else {
		inc = 1;
		newRest = rest();
		while (inc < i) {
			inc++;
			newRest = newRest->rest();
		}
	}
	return newRest;
}

unsigned int SLList::length() {
	unsigned int counter = 0;
	SLList *tempList = this;
	while (tempList->rest() != NULL) {
		tempList = tempList->rest();
		counter++;
	}
	return counter;
}

int SLList::sum() {
	SLList *tempList = this;
	int sumOf=0;
	while (tempList->rest()!=NULL) {
		sumOf += tempList->first();
		tempList = tempList->rest();
	}
	return sumOf;
}



SLList *SLList::remove(int i) {
	SLList *tempList = this;
	if (tempList == NIL) {
		return NIL;
	}
	else if (i == tempList->first()) {
		return tempList->rest()->remove(i);
	}
	else {
		return new SLList(tempList->first(), tempList->rest()->remove(i));
	}
}

SLList *SLList::reverse() {
	SLList *tempList = this;
	SLList *tempList2 = NIL;
	SLList *tempList3 = NIL;

	while (tempList != NIL) {
		tempList2 = new SLList(tempList->first(), tempList3);
		tempList = tempList->rest();
		tempList3 = tempList2;
	}
	return tempList2;
}

//int SLList::max() {
//	SLList *tempList = this;
//	int maxOf = 0;
//	while (tempList->rest() != NULL) {
//		if(tempList->first()>tempList->rest
//	}
//}