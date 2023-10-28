#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300000
using namespace std;
int n, a[MaxN+1], ans = 0, dpRed[MaxN+1], dpBlue[MaxN+1], SumRed = 0, SumBlue = 0;
vector<int> g[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i] == 1)
            SumRed++;
        else if (a[i] == 2)
            SumBlue++;
    }
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void CalDp(int u, int p = -1) {
    if (a[u] == 1)
        dpRed[u]++;
    else if (a[u] == 2)
        dpBlue[u]++;
    for (int v: g[u]) {
        if (v == p)
            continue;
        CalDp(v, u);
        bool Found = true;
        int RedDown = dpRed[v], BlueDown = dpBlue[v];
        if (((RedDown > 0) && (BlueDown > 0)) || ((SumRed - RedDown > 0) && (SumBlue - BlueDown > 0)))
            Found = false;
        if (Found)
            ans++;
        dpRed[u] += dpRed[v];
        dpBlue[u] += dpBlue[v];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    CalDp(1, -1);
    cout << ans;
    return 0;
}
