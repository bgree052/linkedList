#include <cstdlib>
#include <climits>
#include <cmath>

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

//SLList *SLList::sublist(int start, int end) {
//	SLList *prevList = NIL; //stores the previous itteration's list
//	SLList *outList = NIL; //is set to a new first each itteration that then has its rest set to the previous whole itteration list
//	for (int i = 1; i < end - start; i++) {
//		outList->setFirst(nth(end - i));
//		outList->setRest(prevList);
//		prevList = outList;
//	}
//	return (outList);
//}

SLList *SLList::sublist(int start, int end) {
	SLList *tempList = this;
	if (start == 0 && end == 0) {
		return NIL;
	}
	else if (start > 0 && end > 0) {
		return rest()->sublist(start - 1, end - 1);
	}
	else if (start == 0 && end > 0) {
		return new SLList(tempList->first(), rest()->sublist(0,end-1));
	}
}

SLList *SLList::merge(SLList *b) {
	SLList *mainList = this;

	if (mainList == NIL) {
		return b;
	}
	else if (b == NIL) {
		return mainList;
	}
	else if (mainList->first() <= b->first()) {
		return new SLList(mainList->first(), mainList->rest()->merge(b));
	}
	else {
		return new SLList(b->first(), b->rest()->merge(mainList));
	} 
}

SLList *SLList::mergesort() {
	int thisLength = this->length();
	if (thisLength <= 1) {
		return this;
	}
	else {
		int mid = (int)floor((double)thisLength / 2);
		SLList *left = sublist(0,mid)->mergesort();
		SLList *right = sublist(mid,thisLength)->mergesort();
		return left->merge(right);
	}
}