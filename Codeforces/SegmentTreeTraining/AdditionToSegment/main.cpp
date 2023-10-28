#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int n, m;
ll st[4*MaxN+1];

void Update(int v, int tl, int tr, int l, int r, ll AddVal) {
    if (l > r)
        return;
    if ((l == tl) && (r == tr))
        st[v] += AddVal;
    else {
        int tm = (tl + tr)/2;
        Update(v*2, tl, tm, l, min(r, tm), AddVal);
        Update(v*2+1, tm+1, tr, max(l, tm+1), r, AddVal);
    }
}

ll GetVal(int v, int tl, int tr, int id) {
    if (tl == tr)
        return st[v];
    else {
        int tm = (tl + tr)/2;
        if (id <= tm)
            return st[v] + GetVal(v*2, tl, tm, id);
        else
            return st[v] + GetVal(v*2+1, tm+1, tr, id);
    }
}

void Solve() {
    int cmd;
    for (int i=1; i<=m; i++) {
        cin >> cmd;
        if (cmd == 1) {
            int l, r;
            ll v;
            cin >> l >> r >> v;
            l++;
            Update(1, 1, n, l, r, v);
        } else {
            int id;
            cin >> id;
            id++;
            cout << GetVal(1, 1, n, id) << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    Solve();
    return 0;
}
