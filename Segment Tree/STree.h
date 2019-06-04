#pragma once
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

class STree
{
private:
	int * v;
	int * segtree;
	int * lazytree;
	int len;
	int size; //nro de nodos en ST

	void buildTree(int arr[], int segT[], int low, int high, int pos);
	void update(int arr[], int lazT[], int startRan, int endRan, int value, int high, int low, int pos);
	int rmq(int segT[], int lazT[], int qlow, int qhigh, int low, int high, int pos);

public:
	STree(int arr[], int _len);
	~STree();
	void printSTArray();
	void printLazyArray();
	void update(int a, int b, int val);
	int rmq(int a, int b);
	
};

