#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200
#define MaxK 5000
#define MaxM 20000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
struct Edge {
    int u, v;
    ll w;
};
int n, m, k;
vector<pll> g[MaxN+1];
ll d[MaxN+1][MaxN+1];
vector<Edge> q;
const ll inf = 1e10+7;

void ReadGraph() {
    cin >> n >> m;
    int u, v;
    ll w;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        g[u].push_back(pll(v, w));
        g[v].push_back(pll(u, w));
    }
    cin >> k;
    for (int i=1; i<=k; i++) {
        Edge tmp;
        cin >> tmp.u >> tmp.v >> tmp.w;
        q.push_back(tmp);
    }
}

void Init() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = inf;
        }
    }
}

void DijkStraFromSrc(int src) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(pll(0, src));
    while (!pq.empty()) {
        pll tmp = pq.top();
        pq.pop();
        int u = tmp.second;
        ll du = tmp.first;
        if (du > d[src][u])
            continue;
        for (pll tmpv: g[u]) {
            int v = tmpv.first;
            ll w = tmpv.second;
            if (d[src][v] > d[src][u] + w) {
                d[src][v] = d[src][u] + w;
                pq.push(pll(d[src][v], v));
            }
        }
    }
}

void DijkStraAll() {
    for (int i=1; i<=n; i++)
        DijkStraFromSrc(i);
}

void Solve() {
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            bool Check = true;
            for (Edge tmp: q) {
                if (tmp.w != min(d[tmp.u][tmp.v], min(d[tmp.u][i] + d[tmp.v][j], d[tmp.u][j] + d[tmp.v][i]))) {
                    Check = false;
                    break;
                }
            }
            if (Check) {
                cout << i << ' ' << j;
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BIFROST.INP", "r", stdin);
    freopen("BIFROST.OUT", "w", stdout);
    ReadGraph();
    Init();
    DijkStraAll();
    Solve();
    return 0;
}
