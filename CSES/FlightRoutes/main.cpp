#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll INF = 1e16 + 7;
int n, m, k;
vector<pii> g[MaxN+5];
priority_queue<ll> BestDist[MaxN+5];

void ReadData() {
    int u, v;
    ll w;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        g[u].push_back(pii(v, w));
    }
}

void Dijkstra(int src) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, src));
    BestDist[src].push(0);
    while (!pq.empty()) {
        pii tmp = pq.top();
        pq.pop();
        ll d = tmp.first;
        int u = tmp.second;
        if (d > BestDist[u].top())
            continue;
        for (pii tmpe: g[u]) {
            int v = tmpe.first;
            ll w = tmpe.second;
            ll NewDist = d + w;
            if (BestDist[v].size() < k) {
                BestDist[v].push(NewDist);
                pq.push(pii(NewDist, v));
            }
            else if (NewDist < BestDist[v].top()) {
                BestDist[v].pop();
                BestDist[v].push(NewDist);
                pq.push(pii(NewDist, v));
            }
        }
    }
}

void Solve() {
    Dijkstra(1);
    vector<ll> Ans;
    Ans.clear();
    while (!BestDist[n].empty()) {
        Ans.push_back(BestDist[n].top());
        BestDist[n].pop();
    }
    reverse(Ans.begin(), Ans.end());
    for (ll x: Ans)
        cout << x << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    ReadData();
    Solve();
    return 0;
}
