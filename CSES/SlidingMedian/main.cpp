#include <iostream>
#include <bits/stdc++.h>
#define MaxN 400000
using namespace std;
int k, n, x[MaxN+5], st[4*MaxN+5], Cnt[MaxN+5];
vector<int> ForCompress;
unordered_map<int, int> ma, Decode;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> x[i];
        ForCompress.push_back(x[i]);
    }
}

void Compress() {
    sort(ForCompress.begin(), ForCompress.end());
    int cnt = 0;
    for (int i=0; i<ForCompress.size(); i++) {
        if (ma.find(ForCompress[i]) == ma.end()) {
            cnt++;
            ma[ForCompress[i]] = cnt;
            Decode[cnt] = ForCompress[i];
        }
    }
    for (int i=1; i<=n; i++) {
        x[i] = ma[x[i]];
        Cnt[x[i]]++;
    }
}

void UpdateSt(int v, int tl, int tr, int id, int val) {
    if (tl == tr)
        st[v] += val;
    else {
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            UpdateSt(v*2, tl, tm, id, val);
        else
            UpdateSt(v*2+1, tm+1, tr, id, val);
        st[v] = st[v*2] + st[v*2+1];
    }
}

int GetSum(int v, int tl, int tr, int l, int r) {
    if ((l > tr) || (r < tl))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = ((tl + tr) >> 1);
    return GetSum(v*2, tl, tm, l, r) + GetSum(v*2+1, tm+1, tr, l, r);
}

int Count(int val, int st, int ed) {
    int res = GetSum(1, 1, MaxN, 1, val-1), cntEqual = Cnt[val];
    int tmp;
    if (k&1)
        tmp = k/2;
    else
        tmp = (k/2) - 1;
    if ((res < tmp) && (cntEqual > 0))
        res += min(tmp - res, cntEqual);
    return res;
}

int BinSearch(int st, int ed) {
    int lo = 1, hi = MaxN, ans = -1;
    int tmp;
    if (k&1)
        tmp = (k/2);
    else
        tmp = (k/2)-1;
    while (lo <= hi) {
        int mid = ((lo + hi) >> 1);
        int x = Count(mid, st, ed);
        if (x <= tmp) {
            if (x == tmp)
                ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<k; i++)
        UpdateSt(1, 1, MaxN, x[i], 1);
    for (int i=1; i<=n-k+1; i++) {
        if (i > 1)
            UpdateSt(1, 1, MaxN, x[i-1], -1);
        UpdateSt(1, 1, MaxN, x[i+k-1], 1);
        cout << Decode[BinSearch(i, i+k-1)] << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    Compress();
    Solve();
    return 0;
}
