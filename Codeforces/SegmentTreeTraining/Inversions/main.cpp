#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, p[MaxN+1], st[4*MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> p[i];
}

void UpdateById(int v, int tl, int tr, int id) {
    if (tl == tr)
        st[v] = 1;
    else {
        int tm = (tl + tr)/2;
        if (id <= tm)
            UpdateById(v*2, tl, tm, id);
        else
            UpdateById(v*2+1, tm+1, tr, id);
        st[v] = st[v*2] + st[v*2+1];
    }
}

int Sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if ((l == tl) && (r == tr))
        return st[v];
    int tm = (tl + tr)/2;
    return (Sum(v*2, tl, tm, l, min(tm, r)) + Sum(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void Solve() {
    for (int i=1; i<=n; i++) {
        cout << Sum(1, 1, n, p[i], n) << ' ';
        UpdateById(1, 1, n, p[i]);
    }
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
