#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100001
using namespace std;
struct DSU {
    struct Node {
        int par, y, g;
    } parent[MaxN];
    void MakeSet(int v, int col) {
        if (parent[v].par == 0) {
            parent[v].par = v;
            parent[v].y = parent[v].g = 0;
            if (col == 0)
                parent[v].y++;
            else
                parent[v].g++;
        }
    }
    int FindSet(int v) {
        if (parent[v].par == 0)
            return -1;
        if (parent[v].par == v)
            return v;
        return (parent[v].par = FindSet(parent[v].par));
    }
    void UnionSet(int u, int v) {
        u = FindSet(u);
        v = FindSet(v);
        if (u != v) {
            parent[v].par = u;
            parent[u].y += parent[v].y;
            parent[u].g += parent[v].g;
        }
    }
}dsu;
int n,m,k;

void Solve() {
    int MinYTime = 0, MinGTime = 0;
    for (int i=1; i<=k; i++)
        dsu.MakeSet(i, 0);
    for (int i=k+1; i<=n; i++)
        dsu.MakeSet(i, 1);
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        u = dsu.FindSet(u);
        v = dsu.FindSet(v);
        dsu.UnionSet(u, v);
        if ((dsu.parent[u].y == k) && (MinYTime == 0))
            MinYTime = i;
        if ((dsu.parent[u].g == n - k) && (MinGTime == 0))
            MinGTime = i;
    }
    cout << MinYTime << ' ' << MinGTime;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("YG.INP", "r", stdin);
    freopen("YG.OUT", "w", stdout);
    cin >> n >> m >> k;
    Solve();
    return 0;
}
