#include <iostream>
#include <bits/stdc++.h>
#define INF 1000000001;
using namespace std;
typedef pair<int, int> pii;
int n, w, dist[201];
bool vis[201];
vector<pii> g[201];

void Init() {
    for (int i=1; i<=n; i++) {
        dist[i] = INF;
        vis[i] = false;
    }
}

int Prim() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, 1));
    dist[1] = 0;
    while (!pq.empty()) {
        pii tmp = pq.top();
        pq.pop();
        int u = tmp.second;
        if (vis[u]) continue;
        vis[u] = true;
        for (auto i: g[u]) {
            int v = i.first, w = i.second;
            if ((!vis[v]) && (dist[v] > w)) {
                dist[v] = w;
                pq.push(pii(dist[v], v));
            }
        }
    }
    bool Imp = false;
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            Imp = true;
            break;
        }
        else
            ans += dist[i];
    }
    if (Imp)
        return -1;
    else
        return ans;
}

void Solve() {
    for (int i=1; i<=w; i++) {
        int u,v,we;
        cin >> u >> v >> we;
        g[u].push_back(pii(v, we));
        g[v].push_back(pii(u, we));
        Init();
        cout << Prim() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> w;
    Solve();
    return 0;
}
