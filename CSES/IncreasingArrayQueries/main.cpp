#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200005
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
int n, q;
ll a[MaxN+1], StSum[4*MaxN+1], NextMax[MaxN+1], LazySum[4*MaxN+1], pref[MaxN+1], ans[MaxN+1];
piii Queries[MaxN+1];
stack<pii> stk;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    a[n+1] = 1e18;
    for (int i=1; i<=q; i++) {
        cin >> Queries[i].first >> Queries[i].second.first;
        Queries[i].second.second = i;
    }
}

void MakePref() {
    for (int i=1; i<=n; i++)
        pref[i] = pref[i-1] + a[i];
}

void DownSum(int v, int tl, int tr) {
    if (LazySum[v] == 0)
        return;
    int tm = ((tl + tr) >> 1);
    LazySum[v*2] = LazySum[v];
    StSum[v*2] = LazySum[v]*(1LL*tm - 1LL*tl + 1LL) - (pref[tm] - pref[tl-1]);
    LazySum[v*2+1] = LazySum[v];
    StSum[v*2+1] = LazySum[v]*(1LL*tr - 1LL*tm) - (pref[tr] - pref[tm]);
    LazySum[v] = 0;
}

void UpdateSum(int v, int tl, int tr, int l, int r, ll val) {
    if (l > r)
        return;
    if ((l == tl) && (tr == r)) {
        LazySum[v] = val;
        StSum[v] = val*(1LL*tr - 1LL*tl + 1LL) - (pref[tr] - pref[tl - 1]);
        return;
    }
    DownSum(v, tl, tr);
    int tm = ((tl + tr) >> 1);
    UpdateSum(v*2, tl, tm, l, min(r, tm), val);
    UpdateSum(v*2+1, tm+1, tr, max(l, tm+1), r, val);
    StSum[v] = StSum[v*2] + StSum[v*2+1];
}

ll GetSum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if ((l <= tl) && (tr <= r))
        return StSum[v];
    DownSum(v, tl, tr);
    int tm = ((tl + tr) >> 1);
    return (GetSum(v*2, tl, tm, l, min(r, tm)) + GetSum(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void NextMaxProcess() {
    stk.push(pii(a[1], 1));
    for (int i=2; i<=n+1; i++) {
        while ((!stk.empty()) && (stk.top().first < a[i])) {
            int tmp = stk.top().second;
            stk.pop();
            NextMax[tmp] = i;
        }
        stk.push(pii(a[i], i));
    }
}

void Solve() {
    sort(Queries + 1, Queries + q + 1);
    int j = q;
    for (int i=n; i>=1; i--) {
        UpdateSum(1, 1, n, i+1, NextMax[i] - 1, a[i]);
        while ((j > 0) && (Queries[j].first > i))
            j--;
        while ((j > 0) && (Queries[j].first == i)) {
            ans[Queries[j].second.second] = GetSum(1, 1, n, Queries[j].first, Queries[j].second.first);
            j--;
        }
    }
    for (int i=1; i<=q; i++)
        cout << ans[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    ReadData();
    MakePref();
    NextMaxProcess();
    Solve();
    return 0;
}
