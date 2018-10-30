#include <iostream>


int test[5] = { 1,1,1,1,1 };

int num(const int* map) {
	map = test;
	return 100;
}

int main() {
	num(test);

}