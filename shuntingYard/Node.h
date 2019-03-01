#include <iostream>

class Node {
	public:
		Node();
		void setRight(Node* newRight);
		Node* getRight();
		void setLeft(Node* newLeft);
		Node* getLeft();
		void setData(char* newData);
		char* getData();
	private:
		Node* right;
		Node* left;
		char* data;
};
