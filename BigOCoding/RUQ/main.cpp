#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int n, q;
ll x[MaxN+2], ft[MaxN+2];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i];
}

void UpdateFt(ll ft[], int v, ll val) {
    while (v <= n) {
        ft[v] += val;
        v += (v & -v);
    }
}

ll GetSum(ll ft[], int v) {
    ll sum = 0;
    while (v > 0) {
        sum += ft[v];
        v -= (v & -v);
    }
    return sum;
}

void UpdateRange(int l, int r, ll val) {
    UpdateFt(ft, l, val);
    UpdateFt(ft, r+1, -val);
}

void Solve() {
    for (int i=1; i<=q; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            UpdateRange(l, r, x);
        }
        else {
            int k;
            cin >> k;
            cout << x[k] + GetSum(ft, k) << '\n';
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
