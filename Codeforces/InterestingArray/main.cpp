#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, m, l[MaxN+1], r[MaxN+1], q[MaxN+1], sum[MaxN+1], a[MaxN+1], st[4*MaxN+1];
const int MaxBit = 30;

void ReadData() {
    for (int i=1; i<=m; i++)
        cin >> l[i] >> r[i] >> q[i];
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr)
        st[v] = a[tl];
    else {
        int tm = (tl + tr)/2;
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = (st[v*2]&st[v*2+1]);
    }
}

int Query(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return ((1LL << (MaxBit+1))-1);
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = (tl + tr)/2;
    return (Query(v*2, tl, tm, l, r) & Query(v*2+1, tm+1, tr, l, r));
}

void Solve() {
    for (int bit=0; bit<=MaxBit; bit++) {
        for (int i=1; i<=n; i++)
            sum[i] = 0;
        for (int i=1; i<=m; i++) {
            if ((q[i]>>bit)&1) {
                sum[l[i]]++;
                sum[r[i]+1]--;
            }
        }
        for (int i=1; i<=n; i++) {
            sum[i] += sum[i-1];
            if (sum[i] > 0)
                a[i] = (a[i] | (1 << bit));
        }
    }
    BuildSt(1, 1, n);
    bool Exist = true;
    for (int i=1; i<=m; i++) {
        int tmp = Query(1, 1, n, l[i], r[i]);
        if (tmp != q[i]) {
            Exist = false;
            break;
        }
    }
    if (!Exist)
        cout << "NO";
    else {
        cout << "YES" << '\n';
        for (int i=1; i<=n; i++)
            cout << a[i] << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
