#include <iostream>
#include <bits/stdc++.h>
#define MaxN 30000
using namespace std;
int p, c, n, ans = 0;
bool reported[MaxN+1], vis[MaxN+1];
vector<int> g[MaxN+1], Destroyed;

void ReadData() {
    for (int i=1; i<=c; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i=1; i<=n; i++) {
        int rep;
        cin >> rep;
        reported[rep] = true;
    }
}

void BFS1(int src) {
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        bool Stop = false;
        for (int v: g[u]) {
            if (reported[v])  {
                Stop = true;
                break;
            }
        }
        if (Stop)
            continue;
        ans++;
        for (int v: g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

/*int BFSCnt(int src) {
    int ans = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans++;
        vis[u] = true;
        for (int v: g[u])
            if (!vis[v])
                q.push(v);
    }
    return ans;
}

int Solution() {
    int ans = 0;
    for (int u: Destroyed) {
        ans += BFSCnt(u);
        if (u == 1)
            ans--;
    }
    return ans;
}*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("DONGDAT.INP", "r", stdin);
    //freopen("DONGDAT.OUT", "w", stdout);
    cin >> p >> c >> n;
    ReadData();
    BFS1(1);
    cout << p - ans;
    return 0;
}
