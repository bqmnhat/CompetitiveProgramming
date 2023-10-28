#include <iostream>
#include <bits/stdc++.h>
#define INF 1e15
#define MOD 987654321
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
struct Edge {
    int u,v;
    ll w;
};
ll n,m,s,t,cntS[100001],cntT[100001];
vector<pll> g[100001], revg[100001];
vector<Edge> edges;

void ReadData() {
    for (int i=1; i<=m; i++) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        g[a].push_back(pll(b,w));
        revg[b].push_back(pll(a,w));
        edges.push_back({a,b,w});
    }
}

void Dijkstra(int st, vector<ll> &dist, vector<pll> g[100001], ll cnt[100001]) {
    set<pll> setds;
    setds.insert(pll(0LL, st));
    dist[st] = 0LL;
    cnt[st] = 1LL;
    while (!setds.empty()) {
        pll tmp = *(setds.begin());
        setds.erase(setds.begin());
        int u  = tmp.second;
        for (auto i: g[u]) {
            int v = i.first;
            ll wei = i.second;
            if (dist[v] > dist[u] + wei) {
                if (dist[v] != INF)
                    setds.erase(setds.find(pll(dist[v], v)));
                cnt[v] = cnt[u]%MOD;
                dist[v] = dist[u] + wei;
                setds.insert(pll(dist[v], v));
            }
            else if (dist[v] == dist[u] + wei)
                cnt[v] = (cnt[v] + cnt[u])%MOD;
        }
    }
}

void Solve() {
    vector<ll> d1(n+1, INF), d2(n+1, INF);
    for (int i=1; i<=100000; i++)
        cntS[i] = cntT[i] = 0;
    Dijkstra(s, d1, g, cntS);
    Dijkstra(t, d2, revg, cntT);
    for (auto i : edges) {
        int u = i.u, v = i.v;
        ll w = i.w, NewW = d1[t] - d1[u] - d2[v] - 1, PathVal = d1[u] + w + d2[v], dt = d1[t];
        if ((PathVal == dt) && ((cntS[u]*cntT[v])%MOD == cntS[t]))
            cout << "YES\n";
        else if (NewW > 0)
            cout << "CAN " << (w - NewW) << '\n';
        else
            cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s >> t;
    ReadData();
    Solve();
    return 0;
}
