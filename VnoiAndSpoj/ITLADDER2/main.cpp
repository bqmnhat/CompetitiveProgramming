#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
struct LazyNode {
    ll SumA, SumBAndLA;
} lazy[4*MaxN+1];
ll st[4*MaxN+1];
const ll Mod = 1e9 + 7;
int n, m;

void down(int v, ll l, ll r)  {
    if (l > r)
        return;
    st[v] = (st[v] + ((((r+l)*(r-l+1LL)/2)%Mod)*lazy[v].SumA)%Mod + ((r-l+1LL)*lazy[v].SumBAndLA)%Mod)%Mod;
    if (l != r) {
        lazy[v*2] = {(lazy[v*2].SumA + lazy[v].SumA)%Mod, (lazy[v*2].SumBAndLA + lazy[v].SumBAndLA)%Mod};
        lazy[v*2+1] = {(lazy[v*2+1].SumA + lazy[v].SumA)%Mod, (lazy[v*2+1].SumBAndLA + lazy[v].SumBAndLA)%Mod};
    }
    lazy[v] = {0LL, 0LL};
}

void UpdateSt(int v, ll tl, ll tr, ll l, ll r, ll A, ll B) {
    if ((lazy[v].SumA != 0) || (lazy[v].SumBAndLA != 0))
        down(v, tl, tr);
    if ((tl > r) || (tr < l))
        return;
    if ((l <= tl) && (tr <= r)) {
        st[v] = (st[v] + ((((tr+tl)*(tr-tl+1LL)/2)%Mod)*A)%Mod + ((tr-tl+1LL)*((B - l*A + Mod * Mod)%Mod))%Mod)%Mod;
        if (l != r) {
            lazy[v*2] = {(lazy[v*2].SumA + A)%Mod, (lazy[v*2].SumBAndLA + (B - l*A + Mod * Mod)%Mod)%Mod};
            lazy[v*2+1] = {(lazy[v*2+1].SumA + A)%Mod, (lazy[v*2+1].SumBAndLA + (B - l*A + Mod * Mod)%Mod)%Mod};
        }
        return;
    }
    int tm = (tl + tr)/2;
    UpdateSt(v*2, tl, tm, l, r, A, B);
    UpdateSt(v*2+1, tm+1, tr, l, r, A, B);
    st[v] = (st[v*2] + st[v*2+1])%Mod;
}

ll SumQuery(int v, int tl, int tr, int l, int r) {
    if ((lazy[v].SumA != 0) || (lazy[v].SumBAndLA != 0))
        down(v, tl, tr);
    if ((tl > r) || (tr < l))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = (tl + tr)/2;
    return ((SumQuery(v*2, tl, tm, l, r) + SumQuery(v*2+1, tm+1, tr, l, r))%Mod);
}

void Solve() {
    for (int i=1; i<=m; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int l, r;
            ll A, B;
            cin >> l >> r >> A >> B;
            UpdateSt(1, 1, n, l, r, A, B);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << SumQuery(1, 1, n, l, r) << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    Solve();
    return 0;
}
