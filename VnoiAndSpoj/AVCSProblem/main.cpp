#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
struct PPDSU {
    vector<int> par, t_unite;
    PPDSU(int n): par(n+5, -1), t_unite(n+5, INT_MAX){};

    int FindSet(int t, int u) {
        if (t_unite[u] > t)
            return u;
        return FindSet(t, par[u]);
    }

    bool Merge(int t, int u, int v) {
        u = FindSet(t, u);
        v = FindSet(t, v);
        if (u == v)
            return false;
        if (par[u] > par[v])
            swap(u, v);
        par[u] += par[v];
        par[v] = u;
        t_unite[v] = t;
        return true;
    }
};
PPDSU dsu(MaxN);
int q, n;

void Solve() {
    int CurT = 1;
    for (int i=1; i<=q; i++) {
        char cmd;
        cin >> cmd;
        if (cmd == 'A') {
            int u, v;
            cin >> u >> v;
            dsu.Merge(CurT, u, v);
        }
        else if (cmd == '?') {
            int u, v;
            cin >> u >> v;
            if (dsu.FindSet(CurT, u) == dsu.FindSet(CurT, v))
                cout << "Y";
            else
                cout << "N";
        }
        else if (cmd == 'C')
            CurT++;
        else {
            int s, u, v;
            cin >> s >> u >> v;
            if (dsu.FindSet(s, u) == dsu.FindSet(s, v))
                cout << "Y";
            else
                cout << "N";
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
