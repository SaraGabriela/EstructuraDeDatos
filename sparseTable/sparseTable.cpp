#include "sparseTable.h"



sparseTable::sparseTable(int arr[], int n)
{
	len = n;
	v = arr;
	preproc();

}


sparseTable::~sparseTable()
{
}

void sparseTable::preproc() {
	sTable = new int*[len];
	for (int i = 0; i < len; i++) {
		sTable[i] = new int[log(len) + 1];
	}

	for (int i = 0; i < len; i++) {
		sTable[i][0] = i;
	}

	for (int j = 1; (1 << j) <= len; j++) {
		for (int i = 0; (i + (1 << j) - 1) < len; i++) {
			int aux1 = v[sTable[i][j - 1]];
			int aux2 = v[sTable[i + (1 << (j - 1))][j - 1]];
			//cout << "prueba" << endl;
			//cout << aux1 <<endl<< aux2<<endl;
			if (aux1 < aux2) {
				sTable[i][j] = sTable[i][j - 1];
			}
			else {
				sTable[i][j] = sTable[i + (1 << (j - 1))][j - 1];
			}
		}
	}

}

void sparseTable::printTable() {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < log(len) + 1; j++) {
			cout << sTable[i][j] << " ";
		}
		cout << endl;
	}
}