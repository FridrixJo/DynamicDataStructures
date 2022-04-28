#include <iostream>
#include "SearchTree.h"

int main() {
	Tree<int> a;
	for (int i = 0; i < 123; i++) {
		a.push_middle(i);
	}
	a.recursive_show();
}