#ifndef LNODE_H
#define LNODE_H

class LNode {
 public:
  LNode();
  LNode* getNext();
  void setNext(LNode* newNext);
  char* getData();
  void setData(char* newData);
 private:
  LNode* next;
  char* data;
};

#endif
