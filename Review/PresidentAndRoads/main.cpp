#include <iostream>
#include <bits/stdc++.h>
#define INF 1e15
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
struct Edge {
    int u,v;
    ll w;
};
int n,m,s,t;
vector<pll> g[100001], revg[100001];
vector<Edge> edges;
ll ds[100001], dt[100001], cnts[100001], cntt[100001], MOD = 1987654321;

void ReadGraphs() {
    for (int i=1; i<=m; i++) {
        int a,b,l;
        cin >> a >> b >> l;
        g[a].push_back(pll(b,l));
        revg[b].push_back(pll(a,l));
        edges.push_back({a,b,l});
    }
}

void Init() {
    for (int i=1; i<=n; i++) {
        ds[i] = dt[i] = INF;
        cnts[i] = cntt[i] = 0;
    }
}

void Dijkstra(int st, vector<pll> graph[100001], ll dist[100001], ll cnt[100001]) {
    set <pll> setds;
    setds.insert(pll(0, st));
    dist[st] = 0;
    cnt[st] = 1;
    while (!setds.empty()) {
        pll tmp = (*setds.begin());
        setds.erase(setds.begin());
        int u = tmp.second;
        for (auto i: graph[u]) {
            int v = i.first;
            ll w = i.second;
            if (dist[v] > dist[u] + w) {
                cnt[v] = cnt[u]%MOD;
                if (dist[v] != INF)
                    setds.erase(setds.find(pll(dist[v], v)));
                dist[v] = dist[u] + w;
                setds.insert(pll(dist[v], v));
            }
            else if (dist[v] == dist[u] + w)
                cnt[v] = (cnt[v] + cnt[u])%MOD;
        }
    }
}

void Solve() {
    Dijkstra(s, g, ds, cnts);
    Dijkstra(t, revg, dt, cntt);
    for (auto e: edges) {
        ll fix = ds[t] - ds[e.u] - dt[e.v] - 1;
        if ((ds[e.u] + e.w + dt[e.v] == ds[t]) && ((cnts[e.u]*cntt[e.v])%MOD == cnts[t]))
            cout << "YES";
        else if (fix > 0)
            cout << "CAN " << (e.w - fix);
        else
            cout << "NO";
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s >> t;
    Init();
    ReadGraphs();
    Solve();
    return 0;
}
