#include <iostream>
#include <bits/stdc++.h>
#define INF 100000000007
using namespace std;
typedef pair<long long, long long> pii;
typedef long long ll;
int n, m, path[100001], a[100001];
ll dist[100001];
vector<pii> g[100001];

void ReadData() {
    for (int i=1; i<=m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back(pii(b,w));
        g[b].push_back(pii(a,w));
    }
}

void Init() {
    for (int i=1; i<=n; i++)
        dist[i] = INF;
}

void Dijkstra(int src) {
    set<pii> setds;
    setds.insert(pii(0, src));
    dist[src] = 0;
    path[src] = -1;
    while (!setds.empty()) {
        pii tmpu = *(setds.begin());
        setds.erase(setds.begin());
        int u = tmpu.second;
        for (auto tmpv : g[u]) {
            int v = tmpv.first;
            ll w = tmpv.second;
            if (dist[v] > dist[u] + w) {
                if (dist[v] != INF)
                    setds.erase(setds.find(pii(dist[v], v)));
                dist[v] = dist[u] + w;
                path[v] = u;
                setds.insert(pii(dist[v], v));
            }
        }
    }
}

void PrintPath() {
    int i = n, la = 0;
    while (i != -1) {
        la++;
        a[la] = i;
        i = path[i];
    }
    for (int i=la; i>=1; i--)
        cout << a[i] << ' ';
}

void Solve() {
    Init();
    Dijkstra(1);
    if (dist[n] == INF)
        cout << "-1";
    else
        PrintPath();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
