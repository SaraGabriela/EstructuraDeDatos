#include "sparseTable.h"

int main() {
	int l[10] = { 5, 6, 1, 8, 0, 4, 11, 9,3, 0 };
	sparseTable t(l, 10);
	t.printTable();
	return 0;
}