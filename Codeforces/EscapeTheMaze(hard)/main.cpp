#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, k, x[200001], DistToFr[200001];
vector<int> g[200001];

void Init() {
    for (int i=1; i<=n; i++)
        DistToFr[i] = n+1;
    for (int i=1; i<=n; i++) {
        while (!g[i].empty())
            g[i].pop_back();
    }
}

void ReadData() {
    for (int i=1; i<=k; i++) {
        cin >> x[i];
        DistToFr[x[i]] = 0;
    }
    int u,v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

int Solution(int u, int dist, int p) {
    bool IsThereChild = true;
    int ans = 0;
    for (int v: g[u]) {
        if (v == p)
            continue;
        int tmp = Solution(v, dist+1, u);
        if (tmp == -1)
            IsThereChild = false;
        DistToFr[u] = min(DistToFr[u], DistToFr[v] + 1);
        if (tmp != -1)
            ans += tmp;
    }
    if (DistToFr[u] <= dist)
        return 1;
    if ((ans == 0) || (!IsThereChild))
        return -1;
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
        Init();
        ReadData();
        cout << Solution(1, 0, -1) << '\n';
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
