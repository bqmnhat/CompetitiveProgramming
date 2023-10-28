#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
int n, t;
string s[MaxN+5];
vector<int> g[MaxN+5], ans[MaxN+5];
bool vis[MaxN+5], MarkAns[MaxN+5][MaxN+5], IsSt[MaxN+5];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> s[i];
}

void Init() {
    memset(vis, false, sizeof(vis));
    memset(IsSt, false, sizeof(IsSt));
    memset(MarkAns, false, sizeof(MarkAns));
    for (int i=1; i<=n; i++) {
        g[i].clear();
        ans[i].clear();
    }
}

void MakeGraph() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (s[i][j] == '1') {
                g[j+1].push_back(i+1);
                IsSt[i+1] = true;
            }
        }
    }
}

void FindAns(int u) {
    vis[u] = true;
    for (int v: g[u]) {
        if (!vis[v])
            FindAns(v);
        for (int x: ans[v]) {
            if (!MarkAns[u][x]) {
                MarkAns[u][x] = true;
                ans[u].push_back(x);
            }
        }
    }
}

void SolveTestCase() {
    for (int i=1; i<=n; i++) {
        MarkAns[i][i] = true;
        ans[i].push_back(i);
    }
    for (int i=1; i<=n; i++)
        if (!IsSt[i])
            FindAns(i);
    for (int i=1; i<=n; i++) {
        cout << ans[i].size() << ' ';
        for (int x: ans[i])
            cout << x << ' ';
        cout << '\n';
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        MakeGraph();
        SolveTestCase();
        Init();
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
