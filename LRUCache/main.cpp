#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>


using namespace std;

struct Node {
	Node* next;
	Node* prev;
	int value;
	int key;
	Node(Node* p, Node* n, int k, int val) : prev(p), next(n), value(val), key(k) {};
	Node(int k, int val) : key(k), value(val) {};
};

class Cache {
protected:
	map<int, Node*> mp;
	int cp;
	Node * head;
	Node * tail;
	virtual void set(int, int) = 0;
	virtual int get(int) = 0;
};


class LRUCache : public Cache
{
public:
	LRUCache(int c) { cp = c; }

	void set(int k, int v)
	{
		Node *N;

		if (mp.empty()) //No nodes 
		{
			N = new Node(k, v);
			tail = head = N;
			mp[k] = N;

			return;
		}

		auto it = mp.find(k);

		if (it != mp.end()) //In hash table
		{
			it->second->value = v; // update value

			if (head == it->second) //head?
				return;

			it->second->prev->next = it->second->next;

			if (tail == it->second) //tail?
				tail = tail->prev;
			else                   //in between?
				it->second->next->prev = it->second->prev;

			it->second->next = head;
			it->second->prev = NULL;
			head->prev = it->second;
			head = it->second;
		}
		else               // No in hash table
		{
			N = new Node(head->prev, head, k, v); //new node
			head->prev = N;
			head = N;
			mp[k] = N;

			if (mp.size() > cp) //capacity?
			{
				tail = tail->prev;
				mp.erase(tail->next->key);
				delete tail->next;
				tail->next = NULL;
			}

		}

	}

	int get(int k)
	{
		auto it = mp.find(k);
		if (it != mp.end())
			return it->second->value;

		return -1;
	}

};


int main() {

	int n, capacity, i;
	cin >> n >> capacity;
	LRUCache l(capacity);

	for (i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "get") {
			int key;
			cin >> key;
			cout << l.get(key) << endl;
		}
		else if (command == "set") {
			int key, value;
			cin >> key >> value;
			l.set(key, value);
		}
	}

	system("pause");

	return 0;

}