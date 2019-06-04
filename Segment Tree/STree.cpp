#include "STree.h"



STree::STree(int arr[], int _len)
{
	v = arr;
	len = _len;
	
	int h = ceil(log(len));//altura segment tree
	size = 2 * (1 << h) - 1;
	segtree  = new int[size];
	lazytree = new int[size];

	for (int i = 0; i < size; i++) {
		lazytree[i] = 0; //CORREGIR PARA SETEAR 0 PARA TODO EL ARRAY
	}

	buildTree(v, segtree, 0, len-1, 0);
}


STree::~STree()
{
	delete []segtree;
	delete[]lazytree;
}

void STree::buildTree(int arr[], int segT[],int low, int high, int pos) { //high y low delimitan el rango que representa cada nodo
	if (low == high) {
		segT[pos] = arr[low]; //Cuando llega a una hoja
		return;
	}

	int m = (low + high) / 2;


	buildTree(arr, segT, low, m, 2 * pos + 1); //2 * pos + 1 es posicion de hijo izquierdo
	buildTree(arr, segT, m + 1, high, 2 * pos + 2); //2 * pos + 2 es posicion de hijo izquierdo

	segT[pos] = min(segT[2 * pos + 1], segT[2 * pos + 2]); //minimo entre hijo izquierdo y derecho 11072013

}

void STree::printSTArray() {
	for (int i = 0; i < size; i++) {
		cout << segtree[i] << " ";
	}
}

void STree::printLazyArray() {
	for (int i = 0; i < size; i++) {
		cout << lazytree[i] << " ";
	}
}

void STree::update(int segment[], int lazT[], int startRan, int endRan, int value, int low, int high, int pos) {
	if (low > high) return;

	if (lazT[pos] != 0) {
		segment[pos] = lazT[pos]; //Actualizar si lazy es diferente de 0
		if (low != high) { //No es nodo hoja
			lazT[2 * pos + 1] = lazT[pos];
			lazT[2 * pos + 2] = lazT[pos];
		}
		lazT[pos] = 0;
	}

	//Si no está dentro de rango
	if (startRan > high || endRan < low) {
		return;
	}

	//Si está totalmente dentro de rango
	if (startRan <= low && endRan >= high) {
		segment[pos] = value;
		if (low != high) {
			lazT[2 * pos + 1] = value;
			lazT[2 * pos + 2] = value;
		}
		return;
	}

	int m = (low + high) / 2;
	update(segment, lazT, startRan, endRan, value, low, m, 2 * pos + 1);
	update(segment, lazT, startRan, endRan, value, m+1, high, 2 * pos + 2);
	segment[pos] = min(segment[2 * pos + 1], segment[2 * pos + 2]);
}

void STree::update(int a, int b, int val) {
	update(segtree, lazytree, a, b, val, 0, len-1, 0);
}

int STree::rmq(int segT[], int lazT[], int qlow, int qhigh, int low, int high, int pos) {
	if (low > high) return (1<<30);
	
	if (lazT[pos] != 0) {
		segT[pos] = lazT[pos];
		if (low != high) { //no es hoja
			lazT[2 * pos + 1] = lazT[pos];
			lazT[2 * pos + 2] = lazT[pos];
		}
		lazT[pos] = 0;
	}

	//fuera de intervalo
	if (qlow > high || qhigh < low) return (1<<30);

	//totalmente dentro de intervalo
	if (qlow <= low && qhigh >= high) {
	//	cout << "prueba " << segT[pos]<<endl;
		return segT[pos];
	}

	//intersecta con inervalo
	int m = (low + high) / 2;
	//cout << "prueba b " << min(rmq(segT, lazT, qlow, qhigh, low, m, 2 * pos + 1), rmq(segT, lazT, qlow, qhigh, m + 1, high, 2 * pos + 2)) << endl;
	return min(rmq(segT, lazT, qlow, qhigh, low, m, 2 * pos + 1), rmq(segT, lazT, qlow, qhigh, m + 1, high, 2 * pos + 2));
}

int STree::rmq(int a, int b) {
	return rmq(segtree, lazytree, a, b, 0, len - 1, 0);
}