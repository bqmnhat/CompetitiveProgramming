#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
using namespace std;
int n, m;
struct DSU {
    int par[MaxN+1], Rank[MaxN+1];
    void MakeSet(int v) {
        if (par[v] == 0) {
            par[v] = v;
            Rank[v] = 0;
        }
    }
    int FindSet(int v) {
        if (par[v] == 0)
            return -1;
        if (par[v] == v)
            return v;
        return (par[v] = FindSet(par[v]));
    }
    bool UnionSet(int u, int v) {
        u = FindSet(u);
        v = FindSet(v);
        if (u != v) {
            if (Rank[u] < Rank[v])
                swap(u, v);
            par[v] = u;
            if (Rank[u] == Rank[v])
                Rank[u]++;
            return true;
        }
        else
            return false;
    }
} dsu;

bool Solution() {
    int u, v;
    for (int i=1; i<=n; i++)
        dsu.MakeSet(i);
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        if (!dsu.UnionSet(u, v))
            return false;
    }
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (dsu.par[i] == i)
            cnt++;
        if (cnt > 1)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    if (Solution())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
