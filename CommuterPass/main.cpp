#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll INF = 1e15 + 7;
int n, m, s, t, U, V;
ll DistST[MaxN+5], RevDistST[MaxN+5], DistUV[MaxN+5][2], DistV[MaxN+5];
vector<pii> g[MaxN+5];
struct PQNode {
    ll d;
    int used, u;

    bool operator > (const PQNode& other) const {
        return (d > other.d);
    }
};

void ReadData() {
    int u, v;
    ll w;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        g[u].push_back(pii(v, w));
        g[v].push_back(pii(u, w));
    }
}

void Init() {
    for (int i=1; i<=n; i++)
        DistST[i] = RevDistST[i] = DistUV[i][0] = DistUV[i][1] = DistV[i] = INF;
}

void DijkstraST(int src, ll dist[MaxN+5]) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push(pii(dist[src], src));
    while (!pq.empty()) {
        pii tmp = pq.top();
        pq.pop();
        ll d = tmp.first;
        int u = tmp.second;
        if (d > dist[u])
            continue;
        for (pii tmpe: g[u]) {
            int v = tmpe.first;
            ll w = tmpe.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(pii(dist[v], v));
            }
        }
    }
}

bool IsInST(int u, int v, ll w) {
    return ((DistST[u] + w + RevDistST[v]) == DistST[t]);
}

void DijkstraUV(int src) {
    priority_queue<PQNode, vector<PQNode>, greater<PQNode>> pq;
    DistUV[src][0] = DistUV[src][1] = 0;
    pq.push({DistUV[src][0], 0, src});
    pq.push({DistUV[src][1], 1, src});
    while (!pq.empty()) {
        PQNode tmp = pq.top();
        pq.pop();
        ll d = tmp.d;
        int used = tmp.used, u = tmp.u;
        if (d > DistUV[u][used])
            continue;
        for (pii tmpe: g[u]) {
            int v = tmpe.first;
            ll w = tmpe.second;
            if (used == 0) {
                if (IsInST(u, v, w)) {
                    if (DistUV[v][1] > DistUV[u][0]) {
                        DistUV[v][1] = DistUV[u][0];
                        pq.push({DistUV[v][1], 1, v});
                    }
                }
                else {
                    if (DistUV[v][0] > DistUV[u][0] + w) {
                        DistUV[v][0] = DistUV[u][0] + w;
                        pq.push({DistUV[v][0], 0, v});
                    }
                }
            }
            else {
                if (IsInST(u, v, w)) {
                    if (DistUV[v][1] > DistUV[u][1]) {
                        DistUV[v][1] = DistUV[u][1];
                        pq.push({DistUV[v][1], 1, v});
                    }
                }
                else {
                    if (DistUV[v][0] > DistUV[u][1] + w) {
                        DistUV[v][0] = DistUV[u][1] + w;
                        pq.push({DistUV[v][0], 0, v});
                    }
                }
            }
        }
    }
}

ll Solution() {
    DijkstraUV(U);
    ll ans = min(DistUV[V][0], DistUV[V][1]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s >> t >> U >> V;
    ReadData();
    Init();
    DijkstraST(s, DistST);
    DijkstraST(t, RevDistST);
    DijkstraST(V, DistV);
    if (s == U) {
        ll ans = INF;
        for (int i=1; i<=n; i++) {
            if (DistST[i] + RevDistST[i] == DistST[t])
                ans = min(ans, DistV[i]);
            else
                ans = min(ans, DistST[i] + DistV[i]);
        }
        cout << ans;
    }
    else
        cout << Solution();
    return 0;
}
