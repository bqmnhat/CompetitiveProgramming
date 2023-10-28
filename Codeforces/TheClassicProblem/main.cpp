#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
#define INF 1000000000000001
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int n, m, s, t, trace[MaxN+1];
vector<pll> graph[MaxN+1];

void ReadData() {
    for (int i=1; i<=m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        graph[u].push_back(pll(v, w));
        graph[v].push_back(pll(u, w));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cin >> s >> t;
    Dijkstra(s);
    Solve();
    return 0;
}
