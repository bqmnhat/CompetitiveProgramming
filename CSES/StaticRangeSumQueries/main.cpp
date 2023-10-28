#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n, q;
ll x[MaxN+1], st[4*MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i];
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr)
        st[v] = x[tl];
    else {
        int tm = ((tl + tr) >> 1);
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = st[v*2] + st[v*2+1];
    }
}

ll SumQuery(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = ((tl + tr) >> 1);
    return (SumQuery(v*2, tl, tm, l, r) + SumQuery(v*2+1, tm+1, tr, l, r));
}

void Solve() {
    BuildSt(1, 1, n);
    int a, b;
    for (int i=1; i<=q; i++) {
        cin >> a >> b;
        cout << SumQuery(1, 1, n, a, b) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    ReadData();
    Solve();
    return 0;
}
