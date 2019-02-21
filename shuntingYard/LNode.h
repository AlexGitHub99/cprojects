class LNode {
	public: 
	LNode* getNext();
	void setNext();
	char* getData();
	void setData();
	private:
	LNode* next;
	char data;
}