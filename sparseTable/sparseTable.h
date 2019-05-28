#pragma once
#include <iostream>
#include <vector>
#include<math.h>

using namespace std;

class sparseTable
{
private:
	int len;
	int * v;
	int ** sTable;

	void preproc();
public:
	sparseTable(int arr[], int n);
	~sparseTable();
	void printTable();
	int rmq(int min, int max);
};

