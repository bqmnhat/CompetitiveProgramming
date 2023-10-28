#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100005
#define MaxLR 1000005
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii; // first = sum; second = right
int n;
pii st[4*MaxLR+1];
vector<pii> a[MaxLR+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        int L, R, w;
        cin >> L >> R >> w;
        a[R].push_back(pii(L, w));
    }
}

pii Combine(pii a, pii b) {
    pii res;
    res.first = a.first + b.first;
    res.second = max(b.second, a.second + b.first);
    return res;
}

void UpdateSt(int v, int tl, int tr, int id, ll val) {
    if (tl == tr) {
        st[v].first += val;
        st[v].second += val;
    }
    else {
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            UpdateSt(v*2, tl, tm, id, val);
        else
            UpdateSt(v*2+1, tm+1, tr, id, val);
        st[v] = Combine(st[v*2], st[v*2+1]);
    }
}

ll Solution() {
    ll ans = 0;
    for (int i=1; i<=MaxLR; i++) {
        for (pii tmp: a[i])
            UpdateSt(1, 0, MaxLR, tmp.first, tmp.second);
        ans = max(ans, st[1].second);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SSEQ.INP", "r", stdin);
    freopen("SSEQ.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
