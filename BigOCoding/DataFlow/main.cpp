#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n, m, pre[MaxN+1];
ll dist[MaxN+1], k, d;
struct Edge {
    int u, v;
    ll flow, cap, cost;
};
vector<Edge> edges;
vector<int> g[MaxN+1];
queue<int> q;
bool InQ[MaxN+1];
const ll INF = 1e18 + 7;

void Init() {
    for (int i=1; i<=n; i++)
        g[i].clear();
    edges.clear();
}

void ReadData() {
    for (int i=1; i<=m; i++) {
        int u, v;
        ll t;
        cin >> u >> v >> t;
        edges.push_back({u, v, 0, -1, t});
        g[u].push_back(edges.size()-1);
        edges.push_back({v, u, 0, 0, -t});
        g[v].push_back(edges.size()-1);
        edges.push_back({v, u, 0, -1, t});
        g[v].push_back(edges.size()-1);
        edges.push_back({u, v, 0, 0, -t});
        g[u].push_back(edges.size()-1);
    }
    cin >> d >> k;
    for (int i=0; i<edges.size(); i++)
        if (edges[i].cap == -1)
            edges[i].cap = k;
}

bool spfa(int S, int T) {
    for (int i=1; i<=n; i++)
        dist[i] = INF;
    memset(InQ, false, sizeof(InQ));
    dist[S] = 0;
    q.push(S);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        InQ[u] = false;
        for (int i : g[u]) {
            int v = edges[i].v;
            ll cap = edges[i].cap, flow = edges[i].flow, cost = edges[i].cost;
            if ((dist[v] <= dist[u] + cost) || (cap <= flow))
                continue;
            dist[v] = dist[u] + cost;
            pre[v] = i;
            if (!InQ[v]) {
                q.push(v);
                InQ[v] = true;
            }
        }
    }
    return (dist[T] != INF);
}

ll MinCostMaxFlow(int s, int t) {
    ll MinCost, MaxFlow, NewFlow;
    MinCost = MaxFlow = 0;
    while ((MaxFlow < d) && (spfa(s, t))) {
        int cur = t;
        NewFlow = d - MaxFlow;
        while (cur != s) {
            int id = pre[cur];
            NewFlow = min(NewFlow, (edges[id].cap - edges[id].flow));
            cur = edges[id].u;
        }
        MaxFlow += NewFlow;
        MinCost += NewFlow*dist[t];
        cur = t;
        while (cur != s) {
            int id = pre[cur];
            edges[id].flow += NewFlow;
            edges[id^1].flow -= NewFlow;
            cur = edges[id].u;
        }
    }
    if (MaxFlow != d)
        return -1;
    return MinCost;
}

void Solve() {
    while (cin >> n >> m) {
        Init();
        ReadData();
        ll ans = MinCostMaxFlow(1, n);
        if (ans == -1) {
            cout << "Impossible.\n";
            continue;
        }
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
