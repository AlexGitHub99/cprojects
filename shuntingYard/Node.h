#include <iostream>

class Node {
	public:
		Node();
		setRight(Node* newRight);
		Node* getRight();
		setLeft(Node* newLeft);
		Node* getLeft();
		setData(char* newData);
		char* getData();
	private:
		Node* right;
		Node* left;
		char* data;
};