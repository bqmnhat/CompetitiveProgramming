#include<iostream>
#include<bits/stdc++.h>
#define MaxN 100000
using namespace std;
int t, n, m, CntSCC, Cntter;
vector<int> graph[MaxN+1];
bool found[MaxN+1], vis[MaxN+1];
stack<int> stk;

void Init() {
    CntSCC = Cntter = 0;
  	while(!stk.empty())
      stk.pop();
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
        vis[i] = found[i] = false;
    }
}

void ReadData() {
    int a, b;
    for (int i = 1; i<=m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }
}

void DFS2(int u) {
    vis[u] = true;
    for (auto v: graph[u])
        if (!vis[v])
            DFS2(v);
}

void DFS(int u) {
    found[u] = true;
    for (auto v: graph[u])
        if (!found[v])
            DFS(v);
    stk.push(u);
}

void SolveTestCases() {
    for (int i=1; i<=n; i++)
        if (!found[i])
            DFS(i);
    while (!stk.empty()) {
        int u = stk.top();
        if (!vis[u]) {
            CntSCC++;
            DFS2(u);
        }
        stk.pop();
    }
    cout << CntSCC << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> m;
        Init();
        ReadData();
        SolveTestCases();
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
