const bool RED = true;
const bool BLACK = false;

class Node {
 public:
  Node(int newData, bool newColor);
  Node* getRight();
  Node* getLeft();
  Node* getParent();
  bool getColor();
  char getColorChar();
  bool isRight();
  bool isLeft();
  int getData();
  void setRight(Node* newRight);
  void setLeft(Node* newLeft);
  void setParent(Node* newParent);
  void setColor(bool newColor);
  void setIsR(bool newIsR);
  void setData(int newData);
 private:
  Node* right;
  Node* left;
  Node* parent;
  bool color;
  bool isR;
  int data;
};
