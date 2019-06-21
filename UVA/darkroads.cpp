#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Calle
{
	int u, v, length;
};

bool comp(const Calle &s1, const Calle &s2)
{
	return s1.length < s2.length;
}

int esGrupo(const vector<int> &grupo, int u)
{
	if (grupo[u] == u) {
		return u;
	}
	else { esGrupo(grupo, grupo[u]); }
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		if (m == 0 && n == 0) { break; }
		vector<Calle> streets;
		vector<int> groups(m);
		int nroCalles = 0;
		int maximo = 0, cost = 0;

		for (int i = 0; i < n; ++i)
		{
			Calle ca;
			cin >> ca.u >> ca.v >> ca.length;
			streets.push_back(ca);
			maximo += ca.length;
		}

		sort(streets.begin(), streets.end(), comp);
		for (int i = 0; i < m; ++i)
			groups[i] = i;
   
		for (size_t i = 0; i < streets.size() && nroCalles < m - 1; ++i)
		{
			Calle &st = streets[i];
			int groupU = esGrupo(groups, st.u);
			int groupV = esGrupo(groups, st.v);
			if (groupU != groupV)
			{
				cost += st.length;
				groups[groupV] = groupU;
				++nroCalles;
			}
		}
		cout << maximo - cost << endl;
	}
	return 0;
}