#pragma once
#ifndef RBTree_H
#define RBTree_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

template <class K, class D>
class RBTree;

template <class K, class D>
class node
{
private:
	K key;
	D data;
	node<K, D> * p_child[2];
	bool color; //0 para negro, 1 para rojo

public:
	node(const K & _key, const D & _data);
	virtual ~node();
	bool getColor();
	void setColor(bool _color);

	friend class RBTree<K, D>;
};
template <class K, class D>
class RBTree
{
private:
	node<K, D> * root;

public:
	RBTree();
	virtual ~RBTree();
	void destructor(node<K, D> * n);

	bool insert(const K & _key, const D & _data);
	node<K, D>* insert(const K & key, const D & data, node<K, D> ** n, node<K, D> ** p);
	void toRB(node<K, D> **n, node<K, D> **p, bool side, node<K, D> *&ptr);
	void turn(node<K, D> **n, bool side);
	node<K, D>* successor(node<K, D> *p);

private:
	bool find(const K & _key, node<K, D> **& n);

};

#include "RBtree.inl"
#endif 