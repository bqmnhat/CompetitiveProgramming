#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000
using namespace std;
typedef pair<int, int> pii;
int n, m, InDeg[MaxN+5], ans[MaxN+5], posVal[MaxN+5], p[MaxN+5];
vector<int> g[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> p[i];
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
    }
}

void Solve() {
    for (int i=1; i<=n; i++) {
        memset(InDeg, 0, sizeof(InDeg));
        for (int u=1; u<=n; u++)
            for (int v: g[u])
                InDeg[v]++;
        priority_queue<pii> pq;
        for (int u=1; u<=n; u++)
            if ((InDeg[u] == 0) && (u != i))
                pq.push(pii(p[u], u));
        for (int j=n; j>=1; j--) {
            if ((pq.empty()) || (pq.top().first < j)) {
                if ((j <= p[i]) && (InDeg[i] == 0))
                    ans[i] = j;
                break;
            }
            int u = pq.top().second;
            pq.pop();
            for (int v: g[u]) {
                InDeg[v]--;
                if ((InDeg[v] == 0) && (v != i))
                    pq.push(pii(p[v], v));
            }
        }
    }
    for (int i=1; i<=n; i++)
        cout << ans[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
