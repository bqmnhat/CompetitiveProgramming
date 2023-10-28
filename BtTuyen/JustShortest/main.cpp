#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n, m, dist[1001];
vector<long long> g[1001];

void Init() {
    for (int i = 2; i <= n; i++)
		dist[i] = 1e10;
}

void BFS(int v)
{
	for (int i = 0; i < g[v].size(); i++)
	{
		int u = g[v][i];
		if (dist[u]>dist[v] + 1)
		{
			dist[u] = dist[v] + 1;
			BFS(u);
		}
	}
}

void Solve() {
    for (int i = 1; i <= m; i++) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int x;
			cin >> x;
			if (dist[x] >= 1e9)
				cout << -1;
			else
				cout << dist[x];
			cout << '\n';
		}
		if (cmd == 2) {
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
			if (dist[y] > dist[x] + 1) {
				dist[y] = dist[x] + 1;
				BFS(y);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	Init();
	Solve();
	return 0;
}
