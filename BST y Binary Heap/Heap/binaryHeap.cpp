// binaryHeap.cpp: define el punto de entrada de la aplicación de consola.
#include <vector>
#include "Tree.h"

using namespace std;

int main()
{
	//vector<int> A = { 101,97,32,81,17,21,5,40,6 };

	Tree * bh = new Tree({ 101,97,32,81,17,21,5,40,6 });

	bh->_push(45);
	bh->show();
    return 0;
}

