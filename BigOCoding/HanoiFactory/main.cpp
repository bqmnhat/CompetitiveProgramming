#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
struct Disks {
    int a, b;
    ll h;
} d[MaxN+1];
int n;
ll st[8*MaxN+5];
vector<int> UseForCompress;
map<int, int> m;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> d[i].a >> d[i].b >> d[i].h;
        UseForCompress.push_back(d[i].a);
        UseForCompress.push_back(d[i].b);
    }
}

void Compress() {
    UseForCompress.push_back(0);
    sort(UseForCompress.begin(), UseForCompress.end());
    int l = UseForCompress.size(), cnt = 0;
    for (int i=1; i<l; i++) {
        if (UseForCompress[i] != UseForCompress[i-1])
            cnt++;
        m[UseForCompress[i]] = cnt;
    }
}

void ChangeData() {
    for (int i=1; i<=n; i++) {
        d[i].a = m[d[i].a];
        d[i].b = m[d[i].b];
    }
}

void UpdateSt(int v, int tl, int tr, int id, ll val) {
    if (tl == tr)
        st[v] = val;
    else {
        int tm = (tl + tr)/2;
        if (id <= tm)
            UpdateSt(v*2, tl, tm, id, val);
        else
            UpdateSt(v*2+1, tm+1, tr, id, val);
        st[v] = max(st[v*2], st[v*2+1]);
    }
}

ll MaxQuery(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = (tl + tr)/2;
    return max(MaxQuery(v*2, tl, tm, l, r), MaxQuery(v*2+1, tm+1, tr, l, r));
}

bool CmpDisks(Disks a, Disks b) {
    return ((a.b > b.b) || ((a.b == b.b) && (a.a > b.a)));
}

ll Solution() {
    sort(d+1, d+1+n, CmpDisks);
    for (int i=1; i<=n; i++) {
        ll tmp = MaxQuery(1, 0, 2*MaxN, 0, d[i].b - 1) + d[i].h;
        UpdateSt(1, 0, 2*MaxN, d[i].a, tmp);
    }
    return st[1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Compress();
    ChangeData();
    cout << Solution();
    return 0;
}
