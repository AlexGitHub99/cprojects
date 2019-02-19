#include 

class stack 
{
public:
	void pop();
	Node* top();
	void push(Node* data);
	private:
	Node* head;
}