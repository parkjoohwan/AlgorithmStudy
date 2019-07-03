#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

int main() {

	cin >> n;

	
	vector<long long> a(n), b(n), c(n), d(n);

	for (int i = 0; i < n; i++) {
		scanf("%lld %lld %lld %lld", &a[i], &b[i], &c[i], &d[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << b[i] << c[i] << d[i]<<endl;
	}


	system("pause");

	return 0;
}
