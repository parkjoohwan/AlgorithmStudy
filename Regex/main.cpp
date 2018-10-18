#include <iostream>
#include <regex>
#include <vector>
#include <string>
using namespace std;

regex regularExpression("([a-z]{1,6})(_{0,1})([0-9]{0,4})@(hackerrank.com)");

string str = "tester_1235@hackerrank.com";

int main() {


	if (regex_match(str, regularExpression))
		cout << true<<endl;
	

	system("pause");
	return 0;
}

