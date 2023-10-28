#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int n;
ll a[MaxN+1], k[MaxN+1];
struct StNode {
    ll val, cnt;
} st[4*MaxN+1];

void ReadData() {
    for (int i=1; i<n; i++)
        cin >> a[i];
    for (int i=1; i<n; i++)
        cin >> k[i];
}

StNode Combine(StNode n1, StNode n2) {
    if (n1.val > n2.val)
        return n1;
    if (n1.val < n2.val)
        return n2;
    return {n1.val, n1.cnt + n2.cnt};
}

void UpdateSt(int v, int tl, int tr, int id, ll val, ll cnt) {
    if (tl == tr)
        st[v] = {val, cnt};
    else {
        int tm = (tl + tr)/2;
        if (id <= tm)
            UpdateSt(v*2, tl, tm, id, val, cnt);
        else
            UpdateSt(v*2+1, tm+1, tr, id, val, cnt);
        st[v] = Combine(st[v*2], st[v*2+1]);
    }
}

StNode MaxQuery(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return {0, 0};
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = (tl + tr)/2;
    return Combine(MaxQuery(v*2, tl, tm, l, r), MaxQuery(v*2+1, tm+1, tr, l, r));
}

void Solve() {
    UpdateSt(1, 1, n, n, 0, 1);
    for (int i=n-1; i>=1; i--) {
        StNode tmp = MaxQuery(1, 1, n, i+1, min(1LL*n, i+k[i]));
        UpdateSt(1, 1, n, i, a[i] + tmp.val, tmp.cnt);
    }
    cout << st[1].val << ' ' << st[1].cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
