class Node {
 public:
  Node();
  Node* getRight();
  Node* getLeft();
  int getData();
  void setRight(Node* newRight);
  void setLeft(Node* newLeft);
  void setData(int newData);
 private:
  Node* right;
  Node* left;
  int data;
};
