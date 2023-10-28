#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct PPDSU {
    vector<int> par, t_unite;
    PPDSU(int n): par(n+1, -1), t_unite(n+1, INT_MAX){};

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
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
