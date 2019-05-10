#include "RBtree.h"
#include <time.h>
using namespace std;

int main() {

	RBTree<int, int> tree;

	for (int i = 1; i < 30; i++) {
		tree.insert(i, 1);
	}


	return 0;
}