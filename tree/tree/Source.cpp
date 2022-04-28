#include <iostream>
#include "Header.h"

int main() {
	srand(time(NULL));
	AVLTree<char> a;
	for (int i = 0; i < 2; i++) {
		int n = rand() % 100 + 1;
		a.push(i);
	}
	a.pop(1);
	a.pop(0);
	a.print();
	std::cout << "\n\n";

	a.find(40);

	return 0;
}