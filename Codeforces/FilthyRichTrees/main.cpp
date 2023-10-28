#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300005
using namespace std;
typedef long long ll;
typedef long double ld;
int n, q, tin[MaxN+1], tout[MaxN+1], counter = 0;
vector<int> g[MaxN+1];
ld st[4*MaxN+1]; // stores log2 of values

void ReadData() {
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void DFSPreprocess(int u, int p) {
    counter++;
    tin[u] = counter;
    for (int v: g[u])
        if (v != p)
            DFSPreprocess(v, u);
    tout[u] = counter;
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr)
        st[v] = log2(1);
    else {
        int tm = ((tl + tr) >> 1);
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = st[v*2] + st[v*2+1];
    }
}

void UpdateSt(int v, int tl, int tr, int id, ld val) {
    if (tl == tr)
        st[v] = val;
    else {
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            UpdateSt(v*2, tl, tm, id, val);
        else
            UpdateSt(v*2+1, tm+1, tr, id, val);
        st[v] = st[v*2] + st[v*2+1];
    }
}

ld GetLogOfVal(int v, int tl, int tr, int l, int r) {
    if ((l > tr) || (r < tl))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = ((tl + tr) >> 1);
    return (GetLogOfVal(v*2, tl, tm, l, r) + GetLogOfVal(v*2+1, tm+1, tr, l, r));
}

void Solve() {
    cout << fixed << setprecision(9);
    BuildSt(1, 1, n);
    DFSPreprocess(1, -1);
    for (int i=1; i<=q; i++) {
        int cmd, x;
        ll y;
        cin >> cmd >> x >> y;
        if (cmd == 1)
            UpdateSt(1, 1, n, tin[x], log2(y));
        else {
            ld XSub = GetLogOfVal(1, 1, n, tin[x], tout[x]);
            ld YSub = GetLogOfVal(1, 1, n, tin[y], tout[y]);
            ld Log2OfAns = XSub - YSub;
            if (Log2OfAns >= log2(1000000000))
                cout << "1000000000\n";
            else {
                ld ans = pow(2.0, Log2OfAns);
                cout << ans << '\n';
            }
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
    Solve();
    return 0;
}
