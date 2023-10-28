#include <iostream>
#include <bits/stdc++.h>
#define MaxC 26
using namespace std;
int t, n, k;
string s;
struct DSU {
    int par[MaxC+1];
    void MakeSet(int v) {
        if (par[v] == -1)
            par[v] = v;
    }
    int FindSet(int v) {
        if (par[v] == -1)
            return -1;
        if (par[v] == v)
            return v;
        return (par[v] = FindSet(par[v]));
    }
    void UnionSet(int u, int v) {
        u = FindSet(u);
        v = FindSet(v);
        if (u != v)
            par[u] = v;
    }
};

void SolveTestCase() {
    DSU dsu;
    for (int i=0; i<=MaxC; i++)
        dsu.par[i] = -1;
    for (int i=0; i<=MaxC; i++)
        dsu.MakeSet(i);
    char p = 'a';
    for (int i=0; i<n; i++) {
        if (s[i] <= p)
            continue;
        int t = min(k, s[i] - p);
        char Beg = s[i] - t + 1;
        for (char c = Beg; c<=s[i]; c++)
            dsu.UnionSet(c - 'a', s[i] - t - 'a');
        p = s[i];
        k = k - t;
        if (k == 0)
            break;
    }
    for (int i=0; i<n; i++)
        cout << char('a' + dsu.par[s[i] - 'a']);
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k >> s;
        SolveTestCase();
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
