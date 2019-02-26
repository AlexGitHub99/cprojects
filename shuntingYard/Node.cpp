using namespace std;
#include "Node.h"

Node::Node() {
	right = NULL;
	left = NULL;
	data = NULL;
}

void Node::setRight(Node* newRight) {
	right = newRight;
} 

void Node::setLeft(Node* newLeft) {
	left = newLeft;
}

void Node::setData(char* newData) {
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
