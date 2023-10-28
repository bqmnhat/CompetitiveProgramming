#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100005
using namespace std;
typedef pair<int, int> pii;
int n, m, k, ans[MaxN+1], Time = 0;
vector<pii> st[4*MaxN+17];
map<pii, int> sta;
struct Data {
    int time, u, par, Comp;
};
struct DSU { // Rollback DSU
    int Comp;
    vector<int> par;
    vector<Data> changes;
    DSU(int n): par(n+5, -1) {}
    int FindSet(int u) {
        while (par[u] >= 0)
            u = par[u];
        return u;
    }

    bool UnionSet(int u, int v, int t) {
        u = FindSet(u);
        v = FindSet(v);
        if (u == v)
            return false;
        if (par[u] < par[v])
            swap(u, v);
        changes.push_back({t, v, par[v], Comp});
        par[v] += par[u];
        changes.push_back({t, u, par[u], Comp});
        par[u] = v;
        Comp--;
        return true;
    }

    void Rollback(int t) {
        while ((!changes.empty()) && (changes.back().time > t)) {
            par[changes.back().u] = changes.back().par;
            Comp = changes.back().Comp;
            changes.pop_back();
        }
    }
};
DSU dsu(MaxN);

void Add(int v, int tl, int tr, int l, int r, pii edge) {
    if (l > r)
        return;
    if ((tl == l) && (tr == r)) {
        st[v].push_back(edge);
        return;
    }
    int tm = ((tl + tr) >> 1);
    Add(v*2, tl, tm, l, min(tm, r), edge);
    Add(v*2+1, tm+1, tr, max(l, tm+1), r, edge);
}

void ReadData() {
    sta.clear();
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        sta[pii(u, v)] = 0;
    }
    for (int i=1; i<=k; i++) {
        int cmd, u, v;
        cin >> cmd >> u >> v;
        if (u > v)
            swap(u, v);
        if (cmd == 1)
            sta[pii(u, v)] = i;
        else {
            int stTime = sta[pii(u, v)], edTime = i-1;
            sta.erase(sta.find(pii(u, v)));
            Add(1, 0, k+1, stTime, edTime, pii(u, v));
        }
    }
    for (auto it: sta) {
        int stTime = it.second;
        pii e = it.first;
        int edTime = k;
        Add(1, 0, k+1, stTime, edTime, e);
    }
}

void ITWalk(int v, int tl, int tr) {
    Time++;
    int CurT = Time;
    for (pii e: st[v]) {
        Time++;
        dsu.UnionSet(e.first, e.second, Time);
    }
    if (tl == tr) {
        ans[tl] = dsu.Comp;
        dsu.Rollback(CurT);
        return;
    }
    int tm = ((tl + tr) >> 1);
    ITWalk(v*2, tl, tm);
    ITWalk(v*2+1, tm+1, tr);
    dsu.Rollback(CurT);
}

void Solve() {
    dsu.Comp = n;
    ITWalk(1, 0, k+1);
    for (int i=0; i<=k; i++)
        cout << ans[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    ReadData();
    Solve();
    return 0;
}
