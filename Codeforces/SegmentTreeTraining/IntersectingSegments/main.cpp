#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, a[2*MaxN+1], stleft[8*MaxN+1], stright[8*MaxN+1], LeftPos[MaxN+1], RightPos[MaxN+1], res[MaxN+1];

void ReadData() {
    for (int i=1; i<=2*n; i++) {
        cin >> a[i];
        if (LeftPos[a[i]] == 0)
            LeftPos[a[i]] = i;
        else
            RightPos[a[i]] = i;
    }
}

void UpdateById(int st[], int v, int tl, int tr, int id) {
    if (tl == tr)
        st[v] = 1;
    else {
        int tm = (tl + tr)/2;
        if (id <= tm)
            UpdateById(st, v*2, tl, tm, id);
        else
            UpdateById(st, v*2+1, tm+1, tr, id);
        st[v] = st[v*2] + st[v*2+1];
    }
}

int Sum(int st[], int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if ((l == tl) && (r == tr))
        return st[v];
    int tm = (tl + tr)/2;
    return (Sum(st, v*2, tl, tm, l, min(r, tm)) + Sum(st, v*2+1, tm+1, tr, max(l, tm+1), r));
}

void Solve() {
    for (int i=1; i<=2*n; i++) {
        if (i == LeftPos[a[i]]) {
            res[a[i]] += Sum(stleft, 1, 1, 2*n, LeftPos[a[i]], RightPos[a[i]]);
            UpdateById(stleft, 1, 1, 2*n, RightPos[a[i]]);
        }
    }
    for (int i=2*n; i>=1; i--) {
        if (i == RightPos[a[i]]) {
            res[a[i]] += Sum(stright, 1, 1, 2*n, LeftPos[a[i]], RightPos[a[i]]);
            UpdateById(stright, 1, 1, 2*n, LeftPos[a[i]]);
        }
    }
    for (int i=1; i<=n; i++)
        cout << res[i] << ' ';
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
