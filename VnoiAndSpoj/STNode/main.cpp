#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
#define MaxM 100000
using namespace std;
typedef long long ll;
const ll INF = 1e18;
int n, m, s, t, trace[MaxN+5], dist[MaxN+5];
bool vis[MaxN+5];
queue<int> q;
vector<int> g[MaxM+5];

void ReadData() {
    int u, v;
    for (int i=1; i<=m; i++) {
        scanf("%d%d\n", &u, &v);
        g[u].push_back(v);
    }
}

void FindPath(int src, int fin, vector<int>& path) {
    q.push(src);
    trace[src] = src;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: g[u]) {
            if (trace[v] == 0) {
                trace[v] = u;
                q.push(v);
            }
        }
    }
    int u = fin;
    while (u != src) {
        path.push_back(u);
        u = trace[u];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
}

int MaxDistFromU(int u) {
    q.push(u);
    vis[u] = true;
    int d = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: g[u]) {
            if ((!vis[v]) && (dist[v] == 0)) {
                vis[v] = true;
                q.push(v);
            }
            else
                d = max(d, dist[v]);
        }
    }
    return d;
}

int Solution() {
    vector<int> path;
    FindPath(s, t, path);
    for (int i = 0; i<(int)path.size(); i++)
        dist[path[i]] = i+1;
    int MaxDistOnPath = 0, res = 0;
    for (int u: path) {
        if ((u != s) && (u != t) && (MaxDistOnPath <= dist[u]))
            res++;
        MaxDistOnPath = max(MaxDistOnPath, MaxDistFromU(u));
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%d%d%d%d\n", &n, &m, &s, &t);
    ReadData();
    cout << Solution();
    return 0;
}
