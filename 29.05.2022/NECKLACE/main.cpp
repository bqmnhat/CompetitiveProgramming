#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50
using namespace std;
int t, n, deg[MaxN+1], st, g[MaxN+1][MaxN+1];
vector<int> ans;
bool Exist[MaxN+1];

void Init() {
    st = 0;
    for (int i=1; i<=MaxN; i++) {
        Exist[i] = false;
        deg[i] = 0;
        for (int j=1; j<=MaxN; j++)
            g[i][j] = 0;
    }
}

void ReadData() {
    int u, v;
    for (int i=1; i<=n; i++) {
        cin >> u >> v;
        Exist[u] = Exist[v] = true;
        if (st == 0)
            st = u;
        deg[u]++;
        deg[v]++;
        g[u][v]++;
        g[v][u]++;
    }
}

bool CheckValid() {
    for (int i=1; i<=MaxN; i++) {
        if (!Exist[i])
            continue;
        if ((deg[i]%2 == 1) || (deg[i] == 0))
            return false;
    }
    return true;
}

void FindEulerCycle(int u) {
    for (int v = 1; v <= MaxN; v++) {
        if (g[u][v] > 0) {
            g[u][v]--;
            g[v][u]--;
            FindEulerCycle(v);
        }
    }
    ans.push_back(u);
}

void SolveTestCase() {
    if (!CheckValid()) {
        cout << "NO\n";
        return;
    }
    ans.clear();
    FindEulerCycle(st);
    if (ans.size() != n + 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 1; i<(int)ans.size(); i++)
        cout << ans[i-1] << ' ' << ans[i] << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        Init();
        ReadData();
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("NECKLACE.INP", "r", stdin);
    freopen("NECKLACE.OUT", "w", stdout);
    cin >> t;
    Solve();
    return 0;
}
