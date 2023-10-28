#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
int n;
pii v[MaxN+1];
ll st[4*MaxN+1];

void ReadData() {
    ll ri, hi;
    for (int i=1; i<=n; i++) {
        cin >> ri >> hi;
        v[i] = pii(ri*ri*hi, i);
    }
}

void UpdateSt(ll st[], int v, int tl, int tr, int id, ll val) {
    if (tl == tr)
        st[v] = val;
    else {
        int tm = (tl + tr)/2;
        if (id <= tm)
            UpdateSt(st, v*2, tl, tm, id, val);
        else
            UpdateSt(st, v*2+1, tm+1, tr, id, val);
        st[v] = max(st[v*2], st[v*2+1]);
    }
}

ll MaxQuery(ll st[], int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = (tl + tr)/2;
    return max(MaxQuery(st, v*2, tl, tm, l, r), MaxQuery(st, v*2+1, tm+1, tr, l, r));
}

bool CmpPii(pii a, pii b) {
    return ((a.first < b.first) || ((a.first == b.first) && (a.second > b.second)));
}

double Solution() {
    sort(v+1, v+1+n, CmpPii);
    for (int i=1; i<=n; i++) {
        int id = v[i].second;
        ll tmp = MaxQuery(st, 1, 1, n, 1, id-1) + v[i].first;
        UpdateSt(st, 1, 1, n, id, tmp);
    }
    double pi = acos(-1);
    double ans = pi*(double)st[1];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << setprecision(9) << fixed << Solution();
    return 0;
}
