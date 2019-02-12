using namespace std;
#include "Node.h"

Node::Node() {
	right = NULL;
	left = NULL;
	data = NULL;
}

Node:: setRight(Node* newRight) {
	right = newRight;
} 

Node::setLeft(Node* newLeft) {
	left = newLeft;
}

Node::setData(char* newData) {
	data = newData;
}

Node* Node::getRight() {
	return right;
}

Node* Node::getLeft() {
	return left;
}

char* Node::getData() {
	return data;
}