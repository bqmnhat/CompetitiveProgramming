#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300000
#define MaxK 15
using namespace std;
typedef long long ll;
struct StNode {
    int val, ForPos[MaxK+1];
} st[2][4*MaxN+1];
int n, q, k, tin[MaxN+1], tout[MaxN+1], counter = 0, lvl[MaxN+1], NodeOfTin[MaxN+1], lazy[2][4*MaxN+1];
vector<int> g[MaxN+1];

void ReadData() {
    int p;
    for (int i=2; i<=n; i++) {
        cin >> p;
        g[p].push_back(i);
        g[i].push_back(p);
    }
}

void DFSEulerTour(int u, int p, int l) {
    counter++;
    tin[u] = counter;
    lvl[u] = l;
    NodeOfTin[counter] = u;
    for (int v: g[u])
        if (v != p)
            DFSEulerTour(v, u, l+1);
    tout[u] = counter;
}

void Combine(const StNode& Left, const StNode& Right, StNode& res) {
    res.ForPos[0] = 0;
    int i = 1, j = 1, ls = Left.ForPos[0], rs = Right.ForPos[0];
    while ((i <= ls) && (j <= rs) && (res.ForPos[0] < MaxK)) {
        res.ForPos[0]++;
        if (Left.ForPos[i] > Right.ForPos[j]) {
            res.ForPos[res.ForPos[0]] = Left.ForPos[i];
            i++;
        }
        else {
            res.ForPos[res.ForPos[0]] = Right.ForPos[j];
            j++;
        }
    }
    for (i; i<=ls && res.ForPos[0] < MaxK; i++) {
        res.ForPos[0]++;
        res.ForPos[res.ForPos[0]] = Left.ForPos[i];
    }
    for (j; j<=rs && res.ForPos[0] < MaxK; j++) {
        res.ForPos[0]++;
        res.ForPos[res.ForPos[0]] = Right.ForPos[j];
    }
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr) {
        int WhichTree = lvl[NodeOfTin[tl]]%2;
        st[WhichTree][v].ForPos[0] = 1;
        st[WhichTree][v].ForPos[1] = 0;
    }
    else {
        int tm = ((tl + tr) >> 1);
        BuildSt((v << 1LL), tl, tm);
        BuildSt(((v << 1LL)^1), tm+1, tr);
        Combine(st[1][(v << 1LL)], st[1][((v << 1LL)^1)], st[1][v]);
        Combine(st[0][(v << 1LL)], st[0][((v << 1LL)^1)], st[0][v]);
    }
}

void Down(int code, int v, int tl, int tr) {
    if (lazy[code][v] == 0)
        return;
    int tm = ((tl + tr) >> 1);
    lazy[code][(v << 1LL)] += lazy[code][v];
    lazy[code][((v << 1LL)^1)] += lazy[code][v];
    if (tl == tm)
        st[code][(v << 1LL)].val += lazy[code][v];
    if (tm + 1 == tr)
        st[code][((v << 1LL)^1)].val += lazy[code][v];
    int l = st[code][(v << 1LL)].ForPos[0];
    for (int i=1; i<=l; i++)
        st[code][(v << 1LL)].ForPos[i] += lazy[code][v];
    l = st[code][((v << 1LL)^1)].ForPos[0];
    for (int i=1; i<=l; i++)
        st[code][((v << 1LL)^1)].ForPos[i] += lazy[code][v];
    lazy[code][v] = 0;
}

void UpdateSt(int code, int v, int tl, int tr, int l, int r, int val) {
    if ((tl > r) || (tr < l))
        return;
    if ((l <= tl) && (tr <= r)) {
        lazy[code][v] += val;
        if (tl == tr)
            st[code][v].val += val;
        for (int i=1; i<=st[code][v].ForPos[0]; i++)
            st[code][v].ForPos[i] += val;
        return;
    }
    Down(code, v, tl, tr);
    int tm = ((tl + tr) >> 1);
    UpdateSt(code, (v << 1LL), tl, tm, l, r, val);
    UpdateSt(code, ((v << 1LL)^1), tm+1, tr, l, r, val);
    Combine(st[code][(v << 1LL)], st[code][((v << 1LL)^1)], st[code][v]);
}

ll GetVal(int code, int v, int tl, int tr, int id) {
    if (tl == tr)
        return st[code][v].val;
    Down(code, v, tl, tr);
    int tm = ((tl + tr) >> 1);
    if (id <= tm)
        return GetVal(code, (v << 1LL), tl, tm, id);
    else
        return GetVal(code, ((v << 1LL)^1), tm+1, tr, id);
}

StNode GetAllNode(int code, int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return {0, {}};
    if ((l <= tl) && (tr <= r))
        return st[code][v];
    Down(code, v, tl ,tr);
    int tm = ((tl + tr) >> 1);
    StNode tmp;
    Combine(GetAllNode(code, (v << 1LL), tl, tm, l, r), GetAllNode(code, ((v << 1LL)^1), tm+1, tr, l, r), tmp);
    return tmp;
}

int PosQuery(int u, int k) {
    StNode tmp1 = GetAllNode((lvl[u]&1), 1, 1, n, tin[u], tout[u]), tmp2 = GetAllNode((!(lvl[u]&1)), 1, 1, n, tin[u], tout[u]);
    int i = 1, j = 1, tl1 = tmp1.ForPos[0], tl2 = tmp2.ForPos[0], cnt = 0, cur = 0;
    while ((i <= tl1) && (j <= tl2) && (cnt < k)) {
        if (tmp1.ForPos[i] > tmp2.ForPos[j]) {
            cur = tmp1.ForPos[i];
            i++;
        }
        else {
            cur = tmp2.ForPos[j];
            j++;
        }
        cnt++;
    }
    for (i; i<=tl1 && cnt < k; i++) {
        cur = tmp1.ForPos[i];
        cnt++;
    }
    for (j; j<=tl2 && cnt < k; j++) {
        cur = tmp2.ForPos[j];
        cnt++;
    }
    if (cnt < k)
        return 0;
    return cur;
}

void Solve() {
    for (int i=1; i<=q; i++) {
        string cmd;
        cin >> cmd;
        if (cmd[0] == 'a') {
            int u, val;
            cin >> u >> val;
            UpdateSt((lvl[u]&1), 1, 1, n, tin[u], tout[u], val);
            UpdateSt((!(lvl[u]&1)), 1, 1, n, tin[u], tout[u], (-1LL)*val);
        }
        else if (cmd[0] == 'g') {
            int u;
            cin >> u;
            cout << GetVal((lvl[u]&1), 1, 1, n, tin[u]) << ' ';
        }
        else {
            int u, k;
            cin >> u >> k;
            cout << PosQuery(u, k) << ' ';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cin >> q;
    DFSEulerTour(1, -1, 0);
    BuildSt(1, 1, n);
    Solve();
    return 0;
}
