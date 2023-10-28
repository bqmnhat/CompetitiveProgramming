#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n, m;
ll PowBase[MaxN+1];
string s1, s2;
pii st1[4*MaxN+1], st2[4*MaxN+1];
const ll Base = 37, Mod = 2e9+11;

void MakePowBase() {
    PowBase[0] = 1;
    for (int i=1; i<=MaxN; i++)
        PowBase[i] = (PowBase[i-1]*Base)%Mod;
}

pii Combine(pii Left, pii Right) {
    pii res;
    res.first = (Left.first*PowBase[Right.second] + Right.first)%Mod;
    res.second = Left.second + Right.second;
    return res;
}

void BuildSt(pii st[], int v, int tl, int tr, string& s) {
    if (tl == tr)
        st[v] = pii((s[tl] - 'a' + 1)%Mod, 1);
    else {
        int tm = ((tl + tr) >> 1);
        BuildSt(st, v*2, tl, tm, s);
        BuildSt(st, v*2+1, tm+1, tr, s);
        st[v] = Combine(st[v*2], st[v*2+1]);
    }
}

void UpdateSt(pii st[], int v, int tl, int tr, int id, string& s) {
    if (tl == tr)
        st[v] = pii((s[id] - 'a' + 1)%Mod, 1);
    else {
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            UpdateSt(st, v*2, tl, tm, id, s);
        else
            UpdateSt(st, v*2+1, tm+1, tr, id, s);
        st[v] = Combine(st[v*2], st[v*2+1]);
    }
}

pii GetPalin(pii st[], int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return pii(0, 0);
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = ((tl + tr) >> 1);
    return Combine(GetPalin(st, v*2, tl, tm, l, r), GetPalin(st, v*2+1, tm+1, tr, l, r));
}

void Solve() {
    s2 = s1;
    reverse(s2.begin(), s2.end());
    s2 = ' ' + s2;
    s1 = ' ' + s1;
    BuildSt(st1, 1, 1, n, s1);
    BuildSt(st2, 1, 1, n, s2);
    for (int i=1; i<=m; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int k;
            char x;
            cin >> k >> x;
            s1[k] = x;
            s2[n - k + 1] = x;
            UpdateSt(st1, 1, 1, n, k, s1);
            UpdateSt(st2, 1, 1, n, n - k + 1, s2);
        }
        else {
            int a, b;
            cin >> a >> b;
            if (GetPalin(st1, 1, 1, n, a, b) == GetPalin(st2, 1, 1, n, n - b + 1, n - a + 1))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s1;
    MakePowBase();
    Solve();
    return 0;
}
