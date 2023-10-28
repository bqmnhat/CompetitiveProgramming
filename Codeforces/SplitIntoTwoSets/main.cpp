#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int t, n, Size[3], cntNum[MaxN+5];
bool vis[MaxN+5];
vector<int> g[MaxN+5];

void Init() {
    memset(vis, false, sizeof(vis));
    for (int i=1; i<=n; i++)
        g[i].clear();
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        int u, v;
        cin >> u >> v;
        cntNum[u]++;
        cntNum[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

bool BFS(int src) {
    queue<int> q;
    vis[src] = true;
    bool vis2[MaxN+5];
    memset(vis2, false, sizeof(vis2));
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: g[u]) {
            if (!vis2[v]) {
                vis2[v] = true;
                vis[v] = true;
                q.push(v);
            }
            else
                return false;
        }
    }
    return true;
}

bool Solution() {
    for (int i=1; i<=n; i++) {
        if (cntNum[i] == 0)
            continue;
        if (cntNum[i] != 2)
            return false;
    }
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            if (!BFS(i))
                return false;
            cnt++;
        }
    }
    if (cnt != 2)
        return false;
    return true;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        Init();
        ReadData();
        if (Solution())
            cout << "YES\n";
        else
            cout << "NO\n";
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
