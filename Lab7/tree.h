#pragma once
#include <iostream>
using namespace std;
template<typename T>
struct node {
	T data;
	node<T>** next = nullptr;
	int size = 0;
};
template<typename T>
class tree
{
	node<T>* root = nullptr;
public:
	void add_node(T a) {
		if (root == nullptr) {
			root = new node<T>;
			root->data = a;
		}
		else
		{
			node<T>* new_child = new node<T>;
			new_child->data = a;
			node<T>** new_array = new node<T>*[root->size + 1];
			for (int i = 0; i < root->size; ++i) {
				new_array[i] = root->next[i];
			}
			new_array[root->size] = new_child;
			delete[] root->next;
			root->next = new_array;
			root->size++;
		}
	}
	node<T>* get_node(node<T>* parent) {
		if (parent == nullptr)
			return root;
		else
			return parent;
	}
	void delete_node(node<T>* n) {
		for (int i = 0; i < n->size; i++) {
			if(n->next[i]!=nullptr)
			 delete_node(n->next[i]);
		}
		delete[] n->next;
		delete n;
	}
	node<T>* find(bool (*compare)(T, T), T something, node<T>* croot = nullptr) {
		if (croot == nullptr) {
			croot = root;
		}
		if (compare(something, croot->data))
			return croot;
		for (int i = 0; i < croot->size;i++)
			if (croot->next[i] != nullptr)
				return find(compare, something, croot->next[i]);
	return nullptr;
	}
	void insert(node<T>* parent,node<T>* n, int index) {
		node<T>** new_array = new node<T>*[parent->size + 1];
		int j = 0;
		for (int i = 0; i < parent->size; ++i) {
			if (i == index) {
				new_array[i] = n;
				j++;
			}
			new_array[i+j] = parent->next[i];
		}
		if (index == parent->size)
			new_array[index] = n;
		delete[] parent->next;
		parent->next = new_array;
		parent->size++;
	}
	bool sswap(node<T>* a, node<T>* b, bool (*comp)(T, T)) {
	    if (comp)
			return !comp(a->data, b->data);
	    else
			return b->data < a->data;
	}

	void sort(node<T>* parent, bool (*comp)(T, T) = nullptr) {
		if (parent == nullptr || parent->size <= 1)
			return;
		for (int i = 1; i < parent->size; i++) {
			node<T>* key = parent->next[i];
			int j = i - 1;
			while (j >= 0 && sswap(parent->next[j], key, comp)) {
				parent->next[j + 1] = parent->next[j];
				j--;
			}
			parent->next[j + 1] = key;
		}
	}
	int count(node<T>* parent) {
		int total = 0;
		node<T>* a;
		if (parent == nullptr)
			a = root;
		else
			a = parent;
		for(int i=0; i<a->size;i++)
			if (a->next[i] != nullptr) {
				total++;
				total += count(a->next[i]);
			}
		return total + 1;
	}
};

