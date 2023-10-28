#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
#define MaxP 10
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n, m, p, pe[MaxP+1];
ll dist[MaxN+1][MaxN+1];
vector<pii> g[MaxN+1];
const ll INF = 1e12;

void ReadData() {
    int u, v, w;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        g[u].push_back(pii(v, w));
    }
}

void Init() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            dist[i][j] = INF;
}

void DijkStra(int src) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src][src] = 0;
    pq.push(pii(0, src));
    while (!pq.empty()) {
        pii tmpu = pq.top();
        pq.pop();
        int u = tmpu.second;
        if (tmpu.first > dist[src][u])
            continue;
        for (pii tmpv: g[u]) {
            int v = tmpv.first;
            ll w = tmpv.second;
            if (dist[src][v] > dist[src][u] + w) {
                dist[src][v] = dist[src][u] + w;
                pq.push(pii(dist[src][v], v));
            }
        }
    }
}

void FindAllDist() {
    Init();
    for (int i=1; i<=n; i++)
        DijkStra(i);
}

ll Solution() {
    ll ans = INF;
    for (int i=1; i<=p; i++)
        pe[i] = i;
    do {
        ll tmpans = dist[n][pe[1]];
        for (int i=2; i<=p; i++)
            tmpans += dist[pe[i-1]][pe[i]];
        tmpans += dist[pe[p]][n];
        ans = min(ans, tmpans);
    } while (next_permutation(pe+1, pe+1+p));
    if (ans >= INF)
        return -1;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DULICH.INP", "r", stdin);
    freopen("DULICH.OUT", "w", stdout);
    cin >> n >> m >> p;
    ReadData();
    FindAllDist();
    cout << Solution();
    return 0;
}
