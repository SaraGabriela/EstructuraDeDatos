#include "sparseTable.h"

int main() {
	int l[10] = { 5, 6, 1, 8, -2, 4, 11, 9,3, 0 };
	sparseTable t(l, 10);
	t.printTable();

	cout << t.rmq(1, 3);
	return 0;
}