#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
#define MaxC 256
using namespace std;
int t, n;
bool vis[MaxC+5], used[MaxC+5];
string s;
char c[MaxC+5];
struct DSU {
    int par[MaxC+5];
    void MakeSet(int v) {
        if (par[v] == 0)
            par[v] = v;
    }
    int FindSet(int a) {
        if (par[a] == 0)
            return -1;
        if (par[a] == a)
            return a;
        return par[a] = FindSet(par[a]);
    }
    void UnionSet(int a, int b) {
        a = FindSet(a);
        b = FindSet(b);
        if (a != b)
            par[b] = a;
    }
} dsu;

void Init() {
    memset(vis, false, sizeof(vis));
    memset(used, false, sizeof(used));
    memset(dsu.par, 0, sizeof(dsu.par));
    for (int i=1; i<=MaxC+1; i++) {
        c[i] = '#';
        dsu.MakeSet(i);
    }
}

bool SameSubset(int u, int v) {
    return (dsu.FindSet(u) == dsu.FindSet(v));
}

void SolveTestCase() {
    int cntCharUsed = 0;
    for (int i=0; i<n; i++) {
        for (char x='a'; x<='z'; x++) {
            if ((!vis[s[i]]) && (!used[x]) && (x != s[i])) {
                if ((cntCharUsed < 25) && (SameSubset(x, s[i])))
                    continue;
                used[x] = true;
                vis[s[i]] = true;
                c[s[i]] = x;
                cntCharUsed++;
                dsu.UnionSet(x, s[i]);
                break;
            }
        }
    }
    for (int i=0; i<n; i++)
        cout << c[s[i]];
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        Init();
        cin >> n >> s;
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
