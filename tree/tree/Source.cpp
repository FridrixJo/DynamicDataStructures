#include <iostream>
#include "Header.h"
#include <set>
#include <map>

int main() {
	srand(time(NULL));
	AVLTree<int> a;
	for (int i = 0; i < 100; i++) {
		a.push(i);
	}

    a.print();

	std::cout << "\n\n";

	auto it = AVLTree<int>::BSTIterator(a.begin());
	auto it_end = AVLTree<int>::BSTIterator(a.end());
	for (it; it != it_end; it++) {
		std::cout << *it << "\n";
	}
	std::cout << "\n\n";

	return 0;
}