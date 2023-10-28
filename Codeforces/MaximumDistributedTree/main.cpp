#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
#define MaxM 60000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
struct Edge {
    int u, v;
    ll Constribution; // The value that this Edge will contribute to the answer
};
int t, n, m, par[MaxN+1];
vector<int> g[MaxN+1];
vector<Edge> Edges;
ll p[MaxM+1], dp[MaxN+1], Weight[MaxN+1]; // dp[u]: the amount of vertices in the substring of u
const ll Mod = 1e9 + 7;

void ReadData() {
    cin >> n;
    int u, v;
    Edges.clear();
    for (int i=0; i<=n; i++) {
        g[i].clear();
        dp[i] = 0;
        Weight[i] = 1;
        par[i] = -1;
    }
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        Edges.push_back({u, v, 0LL});
    }
    cin >> m;
    for (int i=1; i<=m; i++)
        cin >> p[i];
}

void DFSDp(int u, int p) {
    dp[u] = 1;
    par[u] = p;
    for (int v: g[u]) {
        if (v == p)
            continue;
        DFSDp(v, u);
        dp[u] += dp[v];
    }
}

bool CmpEdges(Edge a, Edge b) {
    return (a.Constribution > b.Constribution);
}

ll Solution() {
    ll ans = 0;
    for (int i=0; i<n-1; i++) {
        Edge tmp = Edges[i];
        if (tmp.u == par[tmp.v])
            Edges[i].Constribution = dp[tmp.v]*(1LL*n - dp[tmp.v]);
        else
            Edges[i].Constribution = dp[tmp.u]*(1LL*n - dp[tmp.u]);
    }
    sort(Edges.begin(), Edges.end(), CmpEdges);
    sort(p+1, p+1+m, greater<ll>());
    if (m <= n-1) {
        for (int i=1; i<=m; i++)
            Weight[i-1] *= p[i];
    }
    else {
        for (int i=1; i<=m-n+2; i++)
            Weight[0] = (Weight[0]*p[i])%Mod;
        int j = 1;
        for (int i=m-n+3; i<=m; i++) {
            Weight[j] = (Weight[j]*p[i])%Mod;
            j = (j+1)%(n-1);
        }
    }
    for (int i=0; i<n-1; i++)
        ans = (ans + ((Edges[i].Constribution%Mod)*Weight[i])%Mod)%Mod;
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        ReadData();
        DFSDp(1, -1);
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
