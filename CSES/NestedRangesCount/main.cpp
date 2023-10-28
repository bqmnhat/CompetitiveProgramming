#include <iostream>
#include <bits/stdc++.h>
#define MaxN 400000
using namespace std;
struct Range {
    int x, y, id;
};
int n, cover[MaxN+5], covered[MaxN+5], st[4*MaxN+5];
vector<Range> rngs;
vector<int> ForCompress;
map<int, int> ma;

void ReadData() {
    for (int i=1; i<=n; i++) {
        int x, y;
        cin >> x >> y;
        ForCompress.push_back(x);
        ForCompress.push_back(y);
        rngs.push_back({x, y, i});
    }
}

void Compress() {
    sort(ForCompress.begin(), ForCompress.end());
    int cnt = 0;
    for (int i=0; i<ForCompress.size(); i++) {
        if ((i == 0) || ((i > 0) && (ForCompress[i] != ForCompress[i-1]))) {
            cnt++;
            ma[ForCompress[i]] = cnt;
        }
    }
}

void MapValue() {
    for (int i=0; i<n; i++) {
        rngs[i].x = ma[rngs[i].x];
        rngs[i].y = ma[rngs[i].y];
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
    return (GetSum(v*2, tl, tm, l, r) + GetSum(v*2+1, tm+1, tr, l, r));
}

bool CmpRangesLess(Range a, Range b) {
    if (a.x == b.x)
        return (a.y > b.y);
    return (a.x < b.x);
}

bool CmpRangesMore(Range a, Range b) {
    if (a.x == b.x)
        return (a.y < b.y);
    return (a.x > b.x);
}

void Solve() {
    Compress();
    MapValue();
    sort(rngs.begin(), rngs.end(), CmpRangesLess);
    for (int i=0; i<n; i++) {
        int cnt = GetSum(1, 1, MaxN, rngs[i].y, MaxN);
        covered[rngs[i].id] = cnt;
        UpdateSt(1, 1, MaxN, rngs[i].y, 1);
    }
    sort(rngs.begin(), rngs.end(), CmpRangesMore);
    memset(st, 0, sizeof(st));
    for (int i=0; i<n; i++) {
        int cnt = GetSum(1, 1, MaxN, 1, rngs[i].y);
        cover[rngs[i].id] = cnt;
        UpdateSt(1, 1, MaxN, rngs[i].y, 1);
    }
    for (int i=1; i<=n; i++)
        cout << cover[i] << ' ';
    cout << '\n';
    for (int i=1; i<=n; i++)
        cout << covered[i] << ' ';
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
