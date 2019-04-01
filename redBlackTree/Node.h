class Node {
 public:
  Node();
  Node* getRight();
  Node* getLeft();
  Node* getParent();
  int getData();
  void setRight(Node* newRight);
  void setLeft(Node* newLeft);
  void setParent(Node* newParent);
  void setData(int newData);
 private:
  Node* right;
  Node* left;
  Node* parent;
  int data;
}
