#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	stack<int> st; //int type�� stack ����. 
	string str;

	for (int i = 0; i<n; i++) {
		cin >> str;
		if (str == "push") { //push ���ɾ� �϶�. 
			int num;
			cin >> num;
			st.push(num);
		}
		else if (str == "pop") {    //pop ���ɾ� �϶�. 
			if (!st.empty()) {
				cout << st.top() << endl;
				st.pop();
			}
			else {
				cout << "-1" << endl;
			}

		}
		else if (str == "size") {        //size ���ɾ� �϶�. 
			cout << st.size() << endl;
		}
		else if (str == "empty") {    //empty ���ɾ� �϶�. 

			if (st.empty()) {
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
			}

		}
		else if (str == "top") {        //top ���ɾ� �϶�. 

			if (!st.empty()) {
				cout << st.top() << endl;
			}
			else {
				cout << "-1" << endl;
			}

		}

	}
	return 0;
}