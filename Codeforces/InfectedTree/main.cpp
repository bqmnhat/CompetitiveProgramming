#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300000
using namespace std;
int t, n, DpDown[MaxN+5], DpInf[MaxN+5];
vector<int> g[MaxN+5];

void ReadData() {
    for (int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void Init() {
    for (int i=1; i<=n; i++)
        g[i].clear();
    memset(DpInf, 0, sizeof(DpInf));
    memset(DpDown, 0, sizeof(DpDown));
}

void CalDp(int u, int p) {
    DpInf[u] = DpDown[u] = 0;
    int Inf[3], Down[3], cnt = 0;
    for (int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if (v != p) {
            CalDp(v, u);
            DpDown[u] += DpDown[v] + 1;
            cnt++;
            Inf[cnt] = DpInf[v];
            Down[cnt] = DpDown[v];
        }
    }
    if (cnt == 0)
        return;
    if (cnt == 1)
        DpInf[u] = Down[1];
    else
        DpInf[u] = max(Inf[1] + Down[2], Inf[2] + Down[1]);
}

int Solution() {
    int ans = 0;
    CalDp(1, -1);
    return DpInf[1];
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        Init();
        ReadData();
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
