#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n, q;
ll StSum[4*MaxN+1], StDif[4*MaxN+1], p[MaxN+1];
const ll NegInf = -1e18 + 7;
const ll inf = 1e18 + 7;

void ReadData() {
    for (int i = 1; i<=n; i++)
        cin >> p[i];
}

void BuildSt(ll St[4*MaxN+1], int v, int tl, int tr, bool Sum) {
    if (tl == tr) {
        if (Sum)
            St[v] = p[tl] + tl;
        else
            St[v] = p[tl] - tl;
    }
    else {
        int tm = ((tl + tr) >> 1);
        BuildSt(St, v*2, tl, tm, Sum);
        BuildSt(St, v*2+1, tm + 1, tr, Sum);
        St[v] = min(St[v*2], St[v*2+1]);
    }
}

void UpdateSt(ll St[4*MaxN+1], int v, int tl, int tr, int id, ll val) {
    if (tl == tr)
        St[v] = val;
    else {
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            UpdateSt(St, v*2, tl, tm, id, val);
        else
            UpdateSt(St, v*2+1, tm+1, tr, id, val);
        St[v] = min(St[v*2], St[v*2+1]);
    }
}

ll MinQuerry(ll St[4*MaxN+1], int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return inf;
    if ((l <= tl) && (tr <= r))
        return St[v];
    int tm = ((tl + tr) >> 1);
    return min(MinQuerry(St, v*2, tl, tm, l, r), MinQuerry(St, v*2+1, tm+1, tr, l, r));
}

void Solve() {
    BuildSt(StSum, 1, 1, n, true);
    BuildSt(StDif, 1, 1, n, false);
    int cmd;
    for (int i=1; i <= q; i++) {
        cin >> cmd;
        if (cmd == 1) {
            int k;
            ll x;
            cin >> k >> x;
            UpdateSt(StSum, 1, 1, n, k, x + k);
            UpdateSt(StDif, 1, 1, n, k, x - k);
        }
        else {
            int k;
            cin >> k;
            ll ans = min(MinQuerry(StSum, 1, 1, n, k + 1, n) - k, MinQuerry(StDif, 1, 1, n, 1, k) + k);
            cout << ans << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    ReadData();
    Solve();
    return 0;
}
