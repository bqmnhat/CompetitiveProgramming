#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, tc;
long long s, a[200001], cd[200001], t[800002];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void MakeCD() {
    for (int i=1; i<=n; i++)
        cd[i] = cd[i-1] + a[i];
}

void build(int v, int tl, int tr) { //Initially v = 1, tl = 1, tr = n
    if (tl == tr) {
        t[v] = cd[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = min(t[v*2],t[v*2+1]);
    }
}

long long GetMin(int v, int tl, int tr, int l, int r) { //Initially v = 1, tl = 1, tr = n
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(GetMin(v*2, tl, tm, l, min(r, tm)),GetMin(v*2+1, tm+1, tr, max(l, tm+1), r));
}

bool Check(int m, int& id1, int& id2) {
    for (int i=m; i<=n; i++) {
        long long Min = GetMin(1,1,n,i-m+1, i);
        if (Min - cd[i-m] + s < 0)
            continue;
        if ((cd[i] - cd[i-m]) + s >= 0) {
            id1 = i-m+1;
            id2 = i;
            return true;
        }
    }
    return false;
}

void SolveTestCases() {
    int lo = 1, hi = n, id1 = -1, id2 = -1;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (Check(m,id1,id2))
            lo = m + 1;
        else
            hi = m - 1;
    }
    if (id1 == -1)
        cout << "-1\n";
    else
        cout << id1 << ' ' << id2 << '\n';
}

void Solve() {
    for (int i=1; i<=tc; i++) {
        cin >> n >> s;
        ReadData();
        MakeCD();
        build(1,1,n);
        SolveTestCases();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> tc;
    Solve();
    return 0;
}
