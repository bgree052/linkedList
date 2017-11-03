#ifndef SLLIST_HPP
#define SLLIST_HPP

class SLList {
public:
  SLList(int, SLList *);
  static SLList * const NIL;

  SLList *rest();
  int first();
  void setFirst(int);
  void setRest(SLList *);

  int nth(unsigned int);
  SLList *nthRest(unsigned int);

  unsigned int length();
  SLList *remove(int i);
  SLList *reverse();

  int firstStorage;
  SLList *restStorage;
  SLList *newRest;
  int inc;

  int sum();
  //int max();
};

#endif
