#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, m, a[MaxN+1];
multiset<int> st[4*MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void BuildSt(int v, int l, int r) {
    if (l == r)
        st[v].insert(a[l]);
    else {
        int mid = (l + r)/2;
        BuildSt(2 * v, l, mid);
        BuildSt(2 * v + 1, mid + 1, r);
        st[v] = st[2 * v];
        for (auto x : st[2 * v + 1])
            st[v].insert(x);
    }
}

void UpdateSt(int v, int l, int r, int i, int OldVal, int NewVal) {
    if (l > i || r < i) return;
    if (l == r) {
        st[v].clear();
        st[v].insert(NewVal);
    }
    else {
        int mid = (l + r)/2;
        UpdateSt(2 * v, l, mid, i, OldVal, NewVal);
        UpdateSt(2 * v + 1, mid + 1, r, i, OldVal, NewVal);
        st[v].erase(st[v].find(OldVal));
        st[v].insert(NewVal);
    }
}

int Query(int v, int l, int r, int x, int y, int k) {
    if (l > y || r < x) return 1e9+1;
    if (l >= x && r <= y) {
        auto it = st[v].lower_bound(k);
        if (it == st[v].end())
            return 1e9+1;
        return *it;
    }
    int mid = (l + r)/2;
    return min(Query(2*v, l, mid, x, y, k), Query(2*v+1, mid+1, r, x, y, k));
}

void Solve() {
    BuildSt(1, 1, n);
    for (int i=1; i<=m; i++) {
        int CmdCode;
        cin >> CmdCode;
        if (CmdCode == 1) {
            int id, val;
            cin >> id >> val;
            UpdateSt(1, 1, n, id, a[id], val);
            a[id] = val;
        }
        else {
            int l, r, k;
            cin >> l >> r >> k;
            int tmp = Query(1, 1, n, l, r, k);
            if (tmp == 1e9+1)
                tmp = -1;
            cout << tmp << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
