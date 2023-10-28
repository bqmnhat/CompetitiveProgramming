#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
#define MaxA 1000000
using namespace std;
typedef long long ll;
int n;
ll a[MaxN+1], st[4*MaxA+1];
const ll Mod = 1e9 + 7;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void UpdateSt(int v, int tl, int tr, int id, ll val) {
    if (tl == tr)
        st[v] = val%Mod;
    else {
        int tm = (tl + tr)/2;
        if (id <= tm)
            UpdateSt(v*2, tl, tm, id, val);
        else
            UpdateSt(v*2+1, tm+1, tr, id, val);
        st[v] = (st[v*2]%Mod + st[v*2+1]%Mod)%Mod;
    }
}

ll SumQuery(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = (tl + tr)/2;
    return (SumQuery(v*2, tl, tm, l, r)%Mod + SumQuery(v*2+1, tm+1, tr, l, r)%Mod)%Mod;
}

ll Solution() {
    for (int i=1; i<=n; i++) {
        ll tmp = SumQuery(1, 1, MaxA, 1, a[i]);
        tmp = ((tmp*a[i])%Mod + a[i])%Mod;
        UpdateSt(1, 1, MaxA, a[i], tmp);
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
    cout << Solution();
    return 0;
}
