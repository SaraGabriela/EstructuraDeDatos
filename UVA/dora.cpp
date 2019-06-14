//DORA THE EXPLORER II
#include <iostream>
using namespace std;

int main(){
	unsigned int a, b,n,L;

while (true){
    cin>>a>>b;
	
	if (a == 0)break;
	L = (a + b) - 1;
	if (L % 2 == 0) { n = a; }
	else { n = b; }

	L--;
	n = n + (L*(L + 1)) / 2;
	cout << n << endl;

}





return 0;}