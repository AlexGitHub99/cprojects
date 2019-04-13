class Node {
 public:
  Node();
  Node* getRight();
  Node* getLeft();
  Node* getParent();
  bool getColor();
  bool isRed();
  bool isBlack();
  int getData();
  void setRight(Node* newRight);
  void setLeft(Node* newLeft);
  void setParent(Node* newParent);
  void setColor(bool newColor);
  void setData(int newData);
 private:
  Node* right;
  Node* left;
  Node* parent;
  bool color;
  int data;
};
