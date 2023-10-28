#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int n, x[MaxN+1], p[MaxN+1], st[4*MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i];
    for (int i=1; i<=n; i++)
        cin >> p[i];
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr)
        st[v] = 1;
    else {
        int tm = ((tl + tr) >> 1);
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = st[v*2] + st[v*2+1];
    }
}

void UpdateSt(int v, int tl, int tr, int id, int val) {
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

int SumQuery(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = ((tl + tr) >> 1);
    return (SumQuery(v*2, tl, tm, l, r) + SumQuery(v*2+1, tm+1, tr, l, r));
}

int BinSearch(int id) {
    int lo = 1, hi = n, ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi)/2;
        if (SumQuery(1, 1, n, 1, mid) >= id) {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=n; i++) {
        int AnsId = BinSearch(p[i]);
        cout << x[AnsId] << ' ';
        UpdateSt(1, 1, n, AnsId, 0);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    BuildSt(1, 1, n);
    Solve();
    return 0;
}
