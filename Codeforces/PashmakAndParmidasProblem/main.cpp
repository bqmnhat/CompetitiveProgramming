#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000005
using namespace std;
typedef long long ll;
int n;
ll a[MaxN+5], st[4*MaxN+5], rem[MaxN+5];
unordered_map<ll, ll> ma;

void ReadData() {
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void UpdateSt(int v, int tl, int tr, int id, ll val) {
    if (tl == tr) {
        st[v] += val;
    } else {
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            UpdateSt(v*2, tl, tm, id, val);
        else
            UpdateSt(v*2 + 1, tm + 1, tr, id, val);
        st[v] = st[v*2] + st[v*2 + 1];
    }
}

ll GetSum(int v, int tl, int tr, int l, int r) {
    if ((tr < l) || (tl > r))
        return 0LL;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = ((tl + tr) >> 1);
    return (GetSum(v*2, tl, tm, l, r) + GetSum(v*2 + 1, tm + 1, tr, l, r));
}

ll Solution() {
    // Calculating Prefix
    for (int i = n; i >= 1; i--) {
        ma[a[i]]++;
        rem[i] = ma[a[i]];
        UpdateSt(1, 0, n, ma[a[i]], 1);
    }
    ll ans = 0;
    ma.clear();
    // Calculating Suffix
    for (int i = 1; i <= n; i++) {
        UpdateSt(1, 0, n, rem[i], -1);
        ma[a[i]]++;
        ans += GetSum(1, 0, n, 0, ma[a[i]] - 1);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
