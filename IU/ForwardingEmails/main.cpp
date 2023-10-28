#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50010
using namespace std;
int t, n, dp[MaxN+1], CntSCC, InWhichSCC[MaxN+1], num[MaxN+1], low[MaxN+1], counter;
bool vis[MaxN+1];
vector<int> g[MaxN+1], NewG[MaxN+1], SCC[MaxN+1];
stack<int> stk;

void Init() {
    CntSCC = counter = 0;
    for (int i=1; i<=n; i++) {
        g[i].clear();
        NewG[i].clear();
        SCC[i].clear();
        InWhichSCC[i] = -1;
        num[i] = low[i] = dp[i] = 0;
        vis[i] = false;
    }
    while (!stk.empty())
        stk.pop();
}

void ReadData() {
    int u, v;
    for (int i=1; i<=n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
}

void DFSTarjan(int u) {
    counter++;
    num[u] = low[u] = counter;
    stk.push(u);
    for (int v: g[u]) {
        if (InWhichSCC[v] == -1) {
            if (!num[v]) {
                DFSTarjan(v);
                low[u] = min(low[u], low[v]);
            }
            else
                low[u] = min(low[u], num[v]);
        }
    }
    if (num[u] == low[u]) {
        int v;
        CntSCC++;
        do {
            v = stk.top();
            stk.pop();
            InWhichSCC[v] = CntSCC;
            SCC[CntSCC].push_back(v);
            num[v] = low[v] = INT_MAX;
        } while (v != u);
    }
}

void Tarjan() {
    for (int i=1; i<=n; i++)
        if (!num[i])
            DFSTarjan(i);
    for (int i=1; i<=n; i++) {
        if (InWhichSCC[i] == -1) {
            CntSCC++;
            InWhichSCC[i] = CntSCC;
            SCC[CntSCC].push_back(i);
        }
    }
    for (int i=1; i<=CntSCC; i++)
        sort(SCC[i].begin(), SCC[i].end());
}

void MakeNewG() {
    for (int u=1; u<=n; u++) {
        for (int v: g[u]) {
            if (InWhichSCC[u] != InWhichSCC[v])
                NewG[InWhichSCC[u]].push_back(InWhichSCC[v]);
        }
    }
}

void DFS(int u) {
    vis[u] = true;
    dp[u] = SCC[u].size();
    for (int v: NewG[u]) {
        if (!vis[v])
            DFS(v);
        dp[u] += dp[v];
    }
}

int TestCaseSolution() {
    int ans = 0, ansID;
    for (int i=1; i<=CntSCC; i++) {
        if (!vis[i])
            DFS(i);
        if (dp[i] > ans) {
            ans = dp[i];
            ansID = SCC[i][0];
        }
        else if (dp[i] == ans)
            ansID = min(ansID, SCC[i][0]);
    }
    return ansID;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        Init();
        ReadData();
        Tarjan();
        MakeNewG();
        cout << "Case " << i << ": " << TestCaseSolution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("FE.INP", "r", stdin);
    //freopen("FE.OUT", "w", stdout);
    cin >> t;
    Solve();
    return 0;
}
