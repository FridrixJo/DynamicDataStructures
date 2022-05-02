#pragma once
#include <iostream>
#include "../../../LABA$5/queue/queue/queue.h"
#include <vector>
#include "../../../LABA$3/stack/stack/stack.h"

template <typename T>
class AVLTree {
public:
	class Node {
	public:
		int key;
		T data;
		Node* left;
		Node* right;
		Node* parent;
		int height;

		Node() = default;
		~Node() {

		}
	};

	Node* newNode(Node* parent, int key, T data = T())
	{
		Node* node = new Node();
		node->key = key;
		node->data = data;
		node->left = nullptr;
		node->right = nullptr;
		node->parent = parent;
		node->height = 1;

		return(node);
	}

	Node* root = nullptr;

	int max(int a, int b) {
		return (a > b) ? a : b;
	}

	int height(Node* node)
	{
		if (node == nullptr) {
			return 0;
		}
		return node->height;
	}

	Node* rightRotate(Node* y)
	{
		Node* x = y->left;
		Node* T2 = x->right;

		x->right = y;
		y->left = T2;

		x->parent = y->parent;
		y->parent = x;

		if (T2)
			T2->parent = y;

		y->height = max(height(y->left),
			height(y->right)) + 1;
		x->height = max(height(x->left),
			height(x->right)) + 1;

		return x;
	}

	Node* leftRotate(Node* x)
	{
		Node* y = x->right;
		Node* T2 = y->left;

		y->left = x;
		x->right = T2;

		y->parent = x->parent;
		x->parent = y;

		if (T2)
			T2->parent = x;

		x->height = max(height(x->left),
			height(x->right)) + 1;
		y->height = max(height(y->left),
			height(y->right)) + 1;

		return y;
	}

	int getBalance(Node* node)
	{
		if (node == nullptr) {
			return 0;
		}
		int heightL = height(node->left);
		int heightR = height(node->right);
		return heightL - heightR;
	}

	Node* insert(Node* parentNode, Node* node, int key, T data = T())
	{
		if (node == nullptr) {
			return (newNode(parentNode, key, data));
		}

		if (key < node->key)
			node->left = insert(node, node->left, key, data);
		else if (key > node->key)
			node->right = insert(node, node->right, key, data);
		else
			return node;

		node->height = 1 + max(height(node->left), height(node->right));

		int balance = getBalance(node);


		if (balance > 1 && key < node->left->key)
			return rightRotate(node);

		if (balance < -1 && key > node->right->key)
			return leftRotate(node);

		if (balance > 1 && key > node->left->key)
		{
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}


		if (balance < -1 && key < node->right->key)
		{
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}

		return node;
	}

	Node* deleteNode(Node* root, int key)
	{

		if (!root) return root;

		if (key > root->key)
			root->right = deleteNode(root->right, key);
		else if (key < root->key)
			root->left = deleteNode(root->left, key);
		else
		{
			if (!root->left && !root->right)
			{
				delete root;
				root = nullptr;
			}
			else if (!root->left)
			{
				Node* temp = root;
				root = root->right;
				delete temp;
				temp = nullptr;
			}
			else if (!root->right)
			{
				Node* temp = root;
				root = root->left;
				delete temp;
				temp = nullptr;
			}
			else
			{
				Node* temp = root->right;
				while (temp->left)
				{
					temp = temp->left;
				}
				root->key = temp->key;
				root->data = temp->data;
				root->right = deleteNode(root->right, temp->key);
			}
		}


		if (root == NULL)
			return root;

		root->height = 1 + max(height(root->left), height(root->right));

		int balance = getBalance(root);


		if (balance > 1 && getBalance(root->left) >= 0)
			return rightRotate(root);

		if (balance > 1 && getBalance(root->left) < 0)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}

		if (balance < -1 && getBalance(root->right) <= 0)
			return leftRotate(root);

		if (balance < -1 && getBalance(root->right) > 0)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}

	void preOrder(Node* root)
	{
		if (root != nullptr)
		{
			std::cout << root->key << " ";
			preOrder(root->left);
			preOrder(root->right);
		}
	}


	void inOrder(Node* node) {
		if (node == nullptr) return;
		inOrder(node->left);
		std::cout << node->key << " ";
		inOrder(node->right);
	}


	void postOrder(Node* node) {
		if (node == nullptr) return;
		inOrder(node->left);
		inOrder(node->right);
		std::cout << node->key << " ";
	}

	void wideOrder(Node* root) {
		queue<Node*> children;
		children.push(root);

		while (!children.empty()) {
			Node* node = *children.front();
			children.pop();

			std::cout << node->key << " ";

			if (node->left)
				children.push(node->left);
			if (node->right)
				children.push(node->right);

		}
	}

	Node* findElement(Node* root, int key) {

		if (root == nullptr) {
			return nullptr;
		}

		if (root->key > key)
		{
			root->left = findElement(root->left, key);
		}
		else if (root->key < key)
		{
			root->right = findElement(root->right, key);
		}
		else
		{
			return root;
		}
	}


	void recursive_show(Node* cur, unsigned level = 1) {

		if (cur) {

			recursive_show(cur->right, level + 1);

			for (int i = 0; i < level; ++i)
				std::cout << '\t';

			std::cout << cur->key << '\n' << '\n';

			recursive_show(cur->left, level + 1);
		}
	}

	void printTree(Node* root, int space = 0) {
		if (!root)
			return;
		const int COUNT = 3;
		space += COUNT;
		printTree(root->right, space);
		for (int i = COUNT; i < space; i++) {
			std::cout << "  ";
		}
		std::cout << root->key << "\n";
		printTree(root->left, space);
	}

public:
	AVLTree() = default;
	~AVLTree() {

	}

	void push(int key, T data = T()) {
		root = insert(nullptr, root, key, data);
	}

	void pop(int key) {
		root = deleteNode(root, key);
	}

	void print() {
		printTree(root);
	}

	void output() {
		preOrder(root);
		std::cout << "\n\n";
		inOrder(root);
		std::cout << "\n\n";
		postOrder(root);
		std::cout << "\n\n";
		wideOrder(root);
		std::cout << "\n\n";
	}

	void find(int key) {
		Node* element = findElement(root, key);
		if (element != nullptr)
		{
			std::cout << element->key << "\n";
		}
		else
		{
			std::cout << "nullptr\n";
		}
		//std::cout << element != nullptr ? element->key : "nullptr";
	}

	Node* firstNode(Node* node) {
		while (node->left) {
			node = node->left;
		}
		return node;
	}

	Node* lastNode(Node* node) {
		while (node->right) {
			node = node->right;
		}
		return node->right;
	}


	class ForwardBSTIterator {
	private:
		stack<Node*> stack;
	public:

		ForwardBSTIterator(Node* root) {
			pushLeft(root);
		}

		~ForwardBSTIterator() {

		}

		int next() {
			Node* node = stack.get();
			stack.pop();
			if (node->right != nullptr) {
				pushLeft(node->right);
			}

			return node->key;
		}

		bool hasNext() {
			return stack.size() > 0;
		}

	private:
		void pushLeft(Node* root) {
			while (root != nullptr) {
				stack.push(root);
				root = root->left;
			}
		}
	};

	class BSTIterator {
	private:
		Node* node;

	public:
		BSTIterator(Node* node) {
			this->node = node;
		}

		~BSTIterator() {

		}

		Node* operator++(int) {
			if (node->right) {
				node = node->right;
				while (node->left)
					node = node->left;
			}
			else {
				if (node->key < node->parent->key)
					node = node->parent;
				else {
					while (node->key > node->parent->key)
						node = node->parent;
					node = node->parent;
				}
			}
			return node;
		}

		Node* operator--(int) {
			if (node->left) {
				node = node->left;
				while (node->right)
					node = node->right;
			}
			else {
				if (node->key > node->parent->key)
					node = node->parent;
				else {
					while (node->key < node->parent->key)
						node = node->parent;
					node = node->parent;
				}
			}
			return node;
		}

		int& operator*() {
			return node->key;
		}
	};
};

/*
template <typename T>
class Tree {
private:
	template<typename T>
	class Node {
	public:
		int key;
		T data;
		Node<T>* left;
		Node<T>* right;
		
		Node() = default;
		~Node() {

		}
	};

	Node<T>* newNode(int key, T value = T()) {
		Node<T>* newNode = new Node<T>();
		newNode->key = key;
		newNode->data = value;
		newNode->left = nullptr;
		newNode->right = nullptr;

		return newNode;
	}

	Node<T>* root = nullptr;

	Node<T>* insert(Node<T>* node, int key, T value = T()) {
		if (node == nullptr) {
			return (newNode(key, value));
		}

		if (key < node->key)
			node->left = insert(node->left, key, value);
		else if (key > node->key)
			node->right = insert(node->right, key, value);
		else
			return node;

		return node;
	}

	void recursive_show(Node<T>* cur, unsigned level = 1) {

		if (cur) {

			recursive_show(cur->right, level + 1);

			for (int i = 0; i < level; ++i)
				std::cout << '\t';

			std::cout << cur->key << '\n' << '\n';

			recursive_show(cur->left, level + 1);
		}

	}

	void inOrder(Node<T>* node) {
		if (node == nullptr) return;
		inOrder(node->left);
		//std::cout << node->key << " ";
		inOrder(node->right);
	}

public:
	Tree() = default;
	~Tree() {

	}

	void push(int key, T data = T()) {
		root = insert(root, key, data);
	}

	void print() {
		recursive_show(root);
	}


};
*/
