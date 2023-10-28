#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
#define MaxW 50
using namespace std;
typedef pair<int, int> pii;
int n, m, dp[MaxN+1], d[MaxN+1][MaxW+1];
vector<pii> g[MaxN+1];
struct pqNode {
    int d1, d2, u, w;
};
const int inf = 1e9 + 1;

struct CmpPqNode {
    bool operator() (pqNode a, pqNode b) {
        if (a.d1 == b.d1)
            return (a.d2 > b.d2);
        return (a.d1 > b.d1);
    }
};

void ReadGraph() {
    int u, v, w;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        g[u].push_back(pii(v, w));
        g[v].push_back(pii(u, w));
    }
}

void Dijkstra(int src) {
    for (int i=0; i<=MaxN; i++) {
        dp[i] = inf;
        for (int j=0; j<=MaxW; j++)
            d[i][j] = inf;
    }
    priority_queue<pqNode, vector<pqNode>, CmpPqNode> pq;
    pq.push({0, inf, src, 0});
    dp[src] = 0;
    while (!pq.empty()) {
        pqNode tmpu = pq.top();
        pq.pop();
        int u = tmpu.u, PrevW = tmpu.w;
        if ((dp[u] < tmpu.d1) && (d[u][PrevW] < tmpu.d2))
            continue;
        for (auto tmpv: g[u]) {
            int v = tmpv.first, w = tmpv.second, NewD;
            NewD = dp[u] + w*w;
            int MinVal = inf;
            for (int j=0; j<=MaxW; j++)
                MinVal = min(MinVal, d[u][j] + 2*j*w + w*w);
            if ((MinVal < dp[v]) || (NewD < d[v][w])) {
                dp[v] = min(MinVal, dp[v]);
                d[v][w] = min(NewD, d[v][w]);
                pq.push({dp[v], d[v][w], v, w});
            }
        }
    }
}

void Solve() {
    for (int i=1; i<=n; i++) {
        if (dp[i] >= inf)
            cout << "-1 ";
        else
            cout << dp[i] << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadGraph();
    Dijkstra(1);
    Solve();
    return 0;
}
