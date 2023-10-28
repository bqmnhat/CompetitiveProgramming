#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int k, n, deg[MaxN+1], par[MaxN+1];
bool vis[MaxN+1];
vector<int> g[MaxN+1];
queue<int> q;

void ReadGraph() {
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
}

void BFSInitialization() {
    for (int i=1; i<=n; i++) {
        if (deg[i] == 1) {
            q.push(i);
            vis[i] = true;
        }
    }
}

int BFS() {
    int cnt = 0, sz = 0, ans = 0;
    while (!q.empty()) {
        cnt++;
        sz = q.size();
        while (sz--) {
            int u = q.front();
            q.pop();
            if (cnt % (k+1) == 0)
                ans++;
            for (int v: g[u]) {
                if (vis[v])
                    continue;
                vis[v] = true;
                q.push(v);
            }
        }
    }
    ans = max(ans, 1);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadGraph();
    BFSInitialization();
    cout << BFS();
    return 0;
}
