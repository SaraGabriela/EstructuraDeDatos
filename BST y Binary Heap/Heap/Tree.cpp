#include "Tree.h"



Tree::Tree(vector<int> pdata)
{
	data = pdata;
	size = data.size();
}


Tree::~Tree()
{
}

void Tree::upIt(int i)
{
	while (data[i] > data[(i - 1) / 2])
	{
		swap(data[i], data[(i - 1) / 2]);
		i = (i - 1) / 2;
		if (i == 0) return;
	}
}

void Tree::_push(int a)
{
	data.push_back(a);
	upIt(size++);
}

void Tree::show()
{
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << " ";
	}
}

void Tree::downIt(int i)
{
	int getH(int a)
	{
		int h;

	}
	int L = 2 * i + 1, R = 2 * i + 2, h;



}