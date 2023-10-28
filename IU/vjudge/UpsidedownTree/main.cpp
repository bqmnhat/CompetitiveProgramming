#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
using namespace std;
int n, deg[MaxN+1], par[MaxN+1], mcnt[MaxN+1];

void Init() {
    for (int i=1; i<=n; i++)
        deg[i] = par[i] = mcnt[i] = 0;
    par[0] = 1e9;
}

void ReadData() {
    int u, w, d;
    for (int i=1; i<=n; i++) {
        cin >> u >> w >> d;
        mcnt[i] = w;
        int v;
        for (int i=1; i<=d; i++) {
            cin >> v;
            par[v] = u;
            deg[u]++;
        }
    }
}

int Solution() {
    int ans = 0;
    queue<int> q;
    for (int i=1; i<=n; i++)
        if (deg[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int u;
        u = q.front();
        q.pop();
        ans += abs(mcnt[u] - 1);
        mcnt[par[u]] += (mcnt[u] - 1);
        deg[par[u]]--;
        if (deg[par[u]] == 0)
            q.push(par[u]);
    }
    return ans;
}

void Solve() {
    while ((cin >> n) && (n != 0)) {
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
    Solve();
    return 0;
}
