#include "STree.h"

int main() {
	int a[] = { 2,3,-1,4 };
	STree arbol(a, 4);
	arbol.printSTArray();
	//arbol.printLazyArray();

	cout << endl;
	cout << arbol.rmq(0, 1);
	return 0;
}