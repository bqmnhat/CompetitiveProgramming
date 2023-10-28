#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
ll cost[MaxN+1];
vector<int> g[MaxN+1], SCC[MaxN+1];
int CntSCC = 0, InSCC[MaxN+1], n, m, counter = 0, low[MaxN+1], num[MaxN+1];
ll MinCostInSCC[MaxN+1];
stack<int> stk;
map<ll, int> CostCntInSCC[MaxN+1];
const ll Mod = 1e9 + 7;

void ReadData() {
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> cost[i];
    cin >> m;
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
}

void Init() {
    for (int i=1; i<=n; i++)
        MinCostInSCC[i] = 1e12+7;
}

void DFS(int u) {
    counter++;
    low[u] = num[u] = counter;
    stk.push(u);
    for (int v: g[u]) {
        if (!InSCC[v]) {
            if (num[v])
                low[u] = min(num[v], low[u]);
            else {
                DFS(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if (low[u] == num[u]) {
        int v;
        CntSCC++;
        do {
            v = stk.top();
            stk.pop();
            InSCC[v] = CntSCC;
            MinCostInSCC[CntSCC] = min(MinCostInSCC[CntSCC], cost[v]);
            CostCntInSCC[CntSCC][cost[v]]++;
        } while (v != u);
    }
}

void Solve() {
    ll ans = 0, cnt = 1;
    for (int i=1; i<=n; i++)
        if (!num[i])
            DFS(i);
    for (int i=1; i<=CntSCC; i++) {
        ans += MinCostInSCC[i];
        cnt = (cnt * CostCntInSCC[i][MinCostInSCC[i]])%Mod;
    }
    cout << ans << ' ' << cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ReadData();
    Init();
    Solve();
    return 0;
}
