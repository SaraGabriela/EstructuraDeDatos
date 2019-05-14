#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Tree
{
private:
	vector<int> data;
	int size;
public:
	Tree(vector<int> pdata = {});
	void upIt(int i);
	void _push(int a);
	void show();

	void downIt(int i);
	~Tree();
};

