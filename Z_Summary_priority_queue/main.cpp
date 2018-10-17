#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main() {

	// priority_queue
	priority_queue< int, vector<int>, less<int> > pq; // top�� ū ������
	// priority_queue< int, vector<int>, greater<int> > pq; // top�� ���� ������ functional ����ʼ�



	// push(element)
	pq.push(5);
	pq.push(2);
	pq.push(8);
	pq.push(9);
	pq.push(1);
	pq.push(14);



	// top();
	cout << "pq top : " << pq.top() << '\n';


	// empty(), size()
	if (!pq.empty()) cout << "pq size : " << pq.size() << '\n';


	// pop all
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}

	cout << '\n';

	system("pause");

	return 0;

}