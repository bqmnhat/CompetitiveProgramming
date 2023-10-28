#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200005
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int n, st[4*MaxN+1], MaxPoint;
map<int, int> encode;
vector<int> points;
pii a[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].first >> a[i].second;
        points.push_back(a[i].first);
        points.push_back(a[i].second);
    }
}

void Compress() {
    sort(points.begin(), points.end());
    int cnt = 1;
    encode[points[0]] = cnt;
    for (int i=1; i<points.size(); i++) {
        if (points[i] != points[i-1]) {
            cnt++;
            encode[points[i]] = cnt;
        }
    }
    MaxPoint = cnt;
    for (int i=1; i<=n; i++) {
        a[i].first = encode[a[i].first];
        a[i].second = encode[a[i].second];
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

ll SumQuery(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = ((tl + tr)>>1);
    return (SumQuery(v*2, tl, tm, l, r) + SumQuery(v*2+1, tm+1, tr, l, r));
}

bool CmpPiis(pii a, pii b) {
    if (a.first == b.first)
        return (a.second < b.second);
    return (a.first < b.first);
}

ll Solution() {
    ll ans = 0;
    sort(a+1, a+1+n, CmpPiis);
    for (int i=1; i<=n; i++) {
        ans += SumQuery(1, 1, MaxPoint, a[i].second+1, MaxPoint);
        UpdateSt(1, 1, MaxPoint, a[i].second, 1);
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
    Compress();
    cout << Solution();
    return 0;
}
