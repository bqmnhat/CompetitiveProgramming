#include <iostream>
#include <bits/stdc++.h>
#define MaxN 105
using namespace std;
typedef long long ll;
struct Edge {
    int u, v;
    ll flow, cap, cost;
};
int n, m, s, f, pre[MaxN+1];
ll k, dist[MaxN+1];
bool InQ[MaxN+1];
vector<int> g[MaxN+1];
vector<Edge> edges;
queue<int> q, nxt[MaxN+1];
const ll INF = 1e18 + 7;

void AddEdge(int u, int v, ll c, ll cost) {
    edges.push_back({u, v, 0, c, cost});
    g[u].push_back(edges.size()-1);
    edges.push_back({v, u, 0, 0, -cost});
    g[v].push_back(edges.size()-1);
}

void ReadData() {
    for (int i=1; i<=m; i++) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        AddEdge(u, v, 1, c);
        AddEdge(v, u, 1, c);
    }
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
    while ((MaxFlow < k) && (spfa(s, t))) {
        int cur = t, id;
        NewFlow = INF;
        while (cur != s) {
            id = pre[cur];
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
    if (MaxFlow != k)
        return -1;
    return MinCost;
}

void PrintAns() {
    for (Edge e: edges) {
        if (e.flow <= 0)
            continue;
        nxt[e.u].push(e.v);
    }
    while (!nxt[s].empty()) {
        int cur = s;
        vector<int> ans;
        ans.clear();
        do {
            ans.push_back(cur);
            int PreCur = cur;
            cur = nxt[cur].front();
            nxt[PreCur].pop();
        } while (cur != f);
        ans.push_back(f);
        cout << ans.size() << ' ';
        for (int x: ans)
            cout << x << ' ';
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> s >> f;
    ReadData();
    ll res = MinCostMaxFlow(s, f);
    cout << res << '\n';
    if (res != -1)
        PrintAns();
    return 0;
}
