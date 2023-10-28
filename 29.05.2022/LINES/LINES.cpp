#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef pair<int, int> pii;
int dp[MaxN+1], trace[MaxN+1], a[MaxN+1], b[MaxN+1], id[MaxN+1], n, arr[MaxN+1];
pii st[4*MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        id[a[i]] = i;
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
        arr[i] = id[b[i]];
    }
}

pii Combine(pii a, pii b) {
    if (a.first > b.first)
        return a;
    return b;
}

void UpdateSt(int v, int tl, int tr, int id, int val, int arrid) {
    if (tl == tr)
        st[v] = pii(val, arrid);
    else {
        int tm = (tl + tr)/2;
        if (id <= tm)
            UpdateSt(v*2, tl, tm, id, val, arrid);
        else
            UpdateSt(v*2+1, tm+1, tr, id, val, arrid);
        st[v] = Combine(st[v*2], st[v*2+1]);
    }
}

pii MaxQuery(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return pii(0, 0);
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = (tl + tr)/2;
    return Combine(MaxQuery(v*2, tl, tm, l, r), MaxQuery(v*2+1, tm+1, tr, l, r));
}

void LIS() {
    dp[0] = 0;
    for (int i=1; i<=n; i++) {
        pii tmp = MaxQuery(1, 1, n, 1, arr[i] - 1);
        trace[i] = tmp.second;
        dp[i] = tmp.first + 1;
        UpdateSt(1, 1, n, arr[i], dp[i], i);
    }
    int ans = st[1].first, i = st[1].second;
    cout << ans << '\n';
    vector<int> lines;
    lines.clear();
    while (i != 0) {
        lines.push_back(a[arr[i]]);
        i = trace[i];
    }
    sort(lines.begin(), lines.end());
    for (auto x: lines)
        cout << x << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("LINES.INP", "r", stdin);
    freopen("LINES.OUT", "w", stdout);
    cin >> n;
    ReadData();
    LIS();
    return 0;
}
