#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200005
using namespace std;
int n, a[MaxN+1], DpDown[MaxN+1], DpUp[MaxN+1], ans[MaxN+1];
vector<int> g[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i] == 0)
            a[i] = -1;
    }
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

int CalDpDown(int u, int p) {
    if (DpDown[u] != -1)
        return DpDown[u];
    int res = a[u];
    for (int v: g[u]) {
        if (v == p)
            continue;
        res = max(res, res + CalDpDown(v, u));
    }
    return DpDown[u] = res;
}

void CalDpUp(int u, int p) {
    int FromUp = 0, AddedVal = -1e9;
    if (p != -1) {
        if ((DpDown[p] >= 0) && (DpDown[u] > 0))
            AddedVal = max(AddedVal, DpDown[p] - DpDown[u]);
        else
            AddedVal = max(AddedVal, DpDown[p]);
        FromUp = max(0, DpUp[p] + AddedVal);
    }
    DpUp[u] = max(0, FromUp);
    ans[u] = DpDown[u] + DpUp[u];
    for (int v: g[u])
        if (v != p)
            CalDpUp(v, u);
}

void Solve() {
    memset(DpDown, -1, sizeof(DpDown));
    CalDpDown(1, -1);
    CalDpUp(1, -1);
    for (int i=1; i<=n; i++)
        cout << ans[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
