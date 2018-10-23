#include <cstdio>

class Node {
	Node* link;
	int data;

public:
	Node(int val = 0) : data(val), link(NULL) {}
	Node* getLink() { return link; }
	void setLink(Node* next) { link = next; }
	void display() { printf(" <%2d>", data); }

};


class LinkedQueue {
	Node* front;
	Node* rear;
public:
	LinkedQueue() : front(NULL), rear(NULL) {}
	~LinkedQueue() { while (!isEmpty()) delete dequeue(); }
	bool isEmpty() { return front == NULL; }

	void enqueue(Node* p) {
		if (isEmpty()) front = rear = p;
		else {
			rear->setLink(p);
			rear = p;
		}
	}

	Node* dequeue() {
		if (isEmpty()) return NULL;
		Node* p = front;
		front = front->getLink();
		if (front == NULL) rear = NULL;
		return p;
	}
	Node* peek() { return front; }
	void display() {
		printf("[Å¥ ³»¿ë] : ");
		for (Node* p = front; p != NULL; p = p->getLink())
			p->display();
		printf("\n");

	}
};