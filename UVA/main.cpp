#include <iostream>
#include <vector>
#include <string>

using namespace std;

void buildTree(vector<int> arr, vector <int> segT, int low, int high, int pos) { //high y low delimitan el rango que representa cada nodo
	/*cout << "low "<<low<<endl;
	cout << "high " << high<<endl;*/
	if (low == high) {
		segT[pos] = arr[low]; //Cuando llega a una hoja
		cout << "segT "<<pos<<": "<< segT[pos]<<"deberia ser " << arr[low] << endl;
		return;
	}

	int m = (low + high) / 2;


	buildTree(arr, segT, low, m, 2 * pos + 1); //2 * pos + 1 es posicion de hijo izquierdo
	buildTree(arr, segT, m + 1, high, 2 * pos + 2); //2 * pos + 2 es posicion de hijo izquierdo

	int a = 2 * pos + 1;
	int b = 2 * pos + 2;
	cout << "segT[2 * pos + 1]:" << segT[a] <<" a: "<<a<< endl;
	cout << "segT[2 * pos + 2]:" << segT[b] << endl;
	segT[pos] = segT[a] + segT[b]; //suma entre hijo izquierdo y derecho
	cout << "segT " << pos << ": " << segT[pos]<<endl;

}

void update(vector <int> segment, vector<int> lazT, int startRan, int endRan, int value, int low, int high, int pos) {
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
	update(segment, lazT, startRan, endRan, value, m + 1, high, 2 * pos + 2);
	segment[pos] = segment[2 * pos + 1]+ segment[2 * pos + 2];
}

int sum(vector<int> segT, vector<int>lazT, int qlow, int qhigh, int low, int high, int pos) {
	if (low > high) return (1 << 30);

	if (lazT[pos] != 0) {
		segT[pos] = lazT[pos];
		if (low != high) { //no es hoja
			lazT[2 * pos + 1] = lazT[pos];
			lazT[2 * pos + 2] = lazT[pos];
		}
		lazT[pos] = 0;
	}

	//fuera de intervalo
	if (qlow > high || qhigh < low) return (1 << 30);

	//totalmente dentro de intervalo
	if (qlow <= low && qhigh >= high) {
		//	cout << "prueba " << segT[pos]<<endl;
		return segT[pos];
	}

	//intersecta con inervalo
	int m = (low + high) / 2;
	//cout << "prueba b " << min(rmq(segT, lazT, qlow, qhigh, low, m, 2 * pos + 1), rmq(segT, lazT, qlow, qhigh, m + 1, high, 2 * pos + 2)) << endl;
	return sum(segT, lazT, qlow, qhigh, low, m, 2 * pos + 1) + sum(segT, lazT, qlow, qhigh, m + 1, high, 2 * pos + 2);
}


int main() {
	int val,a,b,i=1,n;
	vector <vector<int>> cases;

	while (cin >> n) {
		if (n == 0) {
			break;
		}
		vector <int> v,r;
		string in;

		
		for (int i = 0; i < n; i++) {
			cin >> val;
			v.push_back(val);
		}

		int h = ceil(log(n));
		int size = 2 * (1 << h) - 1;
		vector <int> st(size);
		vector <int> lazy(size);
		buildTree(v, st, 0, n - 1, 0);

		cout << endl;
		for (int u = 0; u < st.size(); u++) {
			cout << st[u] << " " << endl;
		}

		while (cin >> in) {
			if (in == "END") {
				break;
			}
			cin >> a >> b;

			if (in == "S") {
				update(st, lazy, a, a, b, 0, n - 1, 0);
			}

			else if (in == "M") {
				r.push_back(sum(st, lazy, a, b, 0, n - 1, 0));
			}
			cout << sum(st, lazy, a, b, 0, n - 1, 0);

			a = b = NULL;
		}

		cases.push_back(r);

		i++;
		v.clear();
		r.clear();
		st.clear();
		lazy.clear();
	}

	for (int j = 0; j < cases.size(); j++) {
		cout << "Case " << j + 1 << ":" << endl;
		for (int g = 0; g < cases[j].size(); g++) {
			cout << cases[j][g] << endl;
		}
		cout << endl;
	}

	return 0;
}