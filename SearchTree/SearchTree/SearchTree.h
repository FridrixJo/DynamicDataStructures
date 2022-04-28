#pragma once
#include "../../../LABA$4/pair/pair.h"

template <typename T>
class Tree {
private:
	template<typename T>
	class Node {
	public:
		int key;
		T data;
		Node<T>* right;
		Node<T>* left;
		size_t height;
		
		Node(int key, T data = T()) {
			this->key = key;
			this->data = data;
			this->left = nullptr;
			this->right = nullptr;
		}
	};

	Node<T>* root = nullptr;

	void inOrder(Node<T>* node) {
		if (node == nullptr) {
			return;
		}
		inOrder(node->left);
		std::cout << node->key << " ";
		inOrder(node->right);
	}

	void recursive_show(Node<T>* node, unsigned int level = 1) {
		if (node) {
			recursive_show(node->right, level + 1);

			for (int i = 0; i < level; ++i) {
				std::cout << "\t";
			}

			std::cout << node->key << "\n\n";

			recursive_show(node->left, level + 1);
		}
	}

	/*void balance(Node<T>* node) {

	}*/

	void correctHeight(Node<T>* node) {
		size_t heightLeft = getSize(node->left);
		size_t heigthRight = getSize(node->right);

		node->height = ((heightLeft > heigthRight) ? heightLeft : heigthRight) + 1;
	}

	size_t bfactor(Node<T>* node) {
		return getSize(node->right) - getSize(node->left);
	}

	size_t getSize(Node<T>* node) {
		if (node == nullptr) {
			return 0;
		}
		return node->height;
	}

	Node<T>* balance(Node<T>* node) {
		correctHeight(node);
		if (bfactor(node) == 2) {
			if (bfactor(node->right) < 0) {
				node->right = rotateLeft(node->right);
			}

			return rotateLeft(node);
		}

		if (bfactor(node) == -2) {
			if (bfactor(node->left) > 0) {
				node->left = rotateRight(node->left);
			}

			return rotateRight(node);
		}

		return node;

	}

	Node<T>* rotateRight(Node<T>* y) {
		Node<T>* x = y->left;
		Node<T>* T2 = x->right;

		x->right = y;
		y->left = T2;

		y->height = std::max(getSize(y->left), getSize(y->right)) + 1;
		x->height = std::max(getSize(x->left), getSize(x->right)) + 1;

		return x;
	}

	Node<T>* rotateLeft(Node<T>* x) {
		Node<T>* y = x->right;
		Node<T>* T2 = y->left;

		y->left = x;
		x->right = T2;

		x->height = std::max(getSize(x->left), getSize(x->right)) + 1;
		y->height = std::max(getSize(y->left), getSize(y->right)) + 1;
		
		return y;
	}

	Node<T>* putNode(Node<T>* node, int key, T value) {

		if (!node) {//
			Node<T>* newNode = new Node<T>(key, value);
			return newNode;
		}

		if (node->key > key) {
			node->left = putNode(node->left, key, value);

		}
		else if (node->key < key) {
			node->right = putNode(node->right, key, value);
		}
		else {
			node->data = value;
		}

		node->height = 1 + getSize(node->left) + getSize(node->right);

		return balance(node);

		/*Node<T>* cur = this->root;
		Node<T>* parent = nullptr;

		while (cur) {
			if (cur->key < key) {
				parent = cur;
				cur = cur->right;
			}
			else if (cur->key > key) {
				parent = cur;
				cur = cur->left;
			}
			else {
				return;
			}
		}

		cur = new Node<T>(key, data);

		if (parent->key < key) {
			parent->right = cur;
		}
		else {
			parent->left = cur;
		}

		return;*/
	}

	void print(Node<T>* node, int l = 1) {
		if (node) {
			print(node->right, l + 1);

			for (int i = 1; i <= l; i++) std::cout << "  "; {
				std::cout << node->key << "\n";
			}

			print(node->left, l + 1);
		}
	}


public:

	Tree() = default;

	~Tree() {
		
	}

	void clear() {

	}

	void output() {
		inOrder(root);
	}

	void recursive_show() {
		recursive_show(root);
	}

	void push_middle(int key, T data = T()) {
		
		root = putNode(root, key, data);
	}

	void print() {
		print(root);
	}


};