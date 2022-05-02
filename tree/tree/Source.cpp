#include <iostream>
#include "Header.h"
#include <set>
#include <map>

int main() {
	srand(time(NULL));
	AVLTree<char> a;
	for (int i = 0; i < 15; i++) {
		int n = rand() % 100 + 1;
		a.push(i);
	}

    a.print();

	std::cout << "\n\n";

	auto it = AVLTree<char>::BSTIterator(a.firstNode(a.root));
	it++;
	it++;
	it++;
	it++;
	it++;
	it++;
	it++;
	it++;
	it--;
	it--;
	it--;
	it++;
	it++;
	it++;
	std::cout << *it;


	
	return 0;
}