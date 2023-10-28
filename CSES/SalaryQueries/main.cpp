#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
#define MaxVal 600000
using namespace std;
typedef long long ll;
struct query {
    char cmd;
    int k;
    ll a, b, x;
} Q[MaxN+1];
int n, q, Nl = 0;
ll p[MaxN+1], st[4*MaxVal + 1], Nums[MaxVal+1];
unordered_map<ll, int> encode;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> p[i];
        Nl++;
        Nums[Nl] = p[i];
    }
    for (int i=1; i<=q; i++) {
        cin >> Q[i].cmd;
        if (Q[i].cmd == '!') {
            cin >> Q[i].k >> Q[i].x;
            Nl++;
            Nums[Nl] = Q[i].x;
        }
        else {
            cin >> Q[i].a >> Q[i].b;
            Nl++;
            Nums[Nl] = Q[i].a;
            Nl++;
            Nums[Nl] = Q[i].b;
        }
    }
}

void Compress() {
    sort(Nums + 1, Nums + 1 + Nl);
    int cnt = 1;
    encode[Nums[1]] = 1;
    for (int i=2; i <= Nl; i++) {
        if (Nums[i] != Nums[i-1]) {
            cnt++;
            encode[Nums[i]] = cnt;
        }
    }
    for (int i=1; i<=n; i++)
        p[i] = encode[p[i]];
    for (int i=1; i<=q; i++) {
        if (Q[i].cmd == '!')
            Q[i].x = encode[Q[i].x];
        else {
            Q[i].a = encode[Q[i].a];
            Q[i].b = encode[Q[i].b];
        }
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

int SumQuery(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = ((tl + tr) >> 1);
    return (SumQuery(v*2, tl, tm, l, r) + SumQuery(v*2+1, tm+1, tr, l, r));
}

void Solve() {
    for (int i=1; i<=n; i++)
        UpdateSt(1, 1, MaxVal, p[i], 1);
    for (int i=1; i<=q; i++) {
        if (Q[i].cmd == '!') {
            UpdateSt(1, 1, MaxVal, p[Q[i].k], -1);
            p[Q[i].k] = Q[i].x;
            UpdateSt(1, 1, MaxVal, Q[i].x, 1);
        }
        else
            cout << SumQuery(1, 1, MaxVal, Q[i].a, Q[i].b) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("SLQ.INP", "r", stdin);
    //freopen("SLQ.OUT", "w", stdout);
    cin >> n >> q;
    ReadData();
    if (!((q == 1) && (Q[1].cmd == '!'))) {
        Compress();
        Solve();
    }
    return 0;
}
