#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
int n, q;
struct DSU {
    int par[MaxN+1];
    void MakeSet(int u) {
        if (par[u] == 0)
            par[u] = u;
    }
    int FindSet(int u) {
        if (par[u] == u)
            return u;
        if (par[u] == 0)
            return -1;
        return (par[u] = FindSet(par[u]));
    }
    void UnionSet(int u, int v) {
        u = FindSet(u);
        v = FindSet(v);
        if (u != v)
            par[u] = v;
    }
} dsu;
vector<int> children[MaxN+1];

void Solve() {
    for (int i=1; i<=n; i++)
        dsu.MakeSet(i);
    for (int i=1; i<=q; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int u, v;
            cin >> u >> v;
            dsu.UnionSet(u, v);
        }
        else if (cmd == 2) {
            int x, y;
            cin >> x >> y;
            children[x].push_back(y);
            children[y].push_back(x);
        }
        else {
            int ans = 0, k;
            cin >> k;
            for (auto x: children[k]) {
                int u = dsu.FindSet(x), v = dsu.FindSet(k);
                if (u == v)
                    ans++;
            }
            cout << ans << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    Solve();
    return 0;
}
