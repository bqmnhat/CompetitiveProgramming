#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
int t, n;
ll s[MaxN+1], stGCD[4*MaxN+1];
pii stMin[4*MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> s[i];
}

int GCD(int a, int b) {
    int g =__gcd(a, b);
    return g;
}

pii Combine(pii a, pii b) {
    if (a.first < b.first)
        return a;
    else if (a.first > b.first)
        return b;
    else
        return pii(a.first, a.second + b.second);
}

void BuildSt(int v, int tl, int tr, bool IsGCD) {
    if (tl == tr) {
        if (IsGCD)
            stGCD[v] = s[tl];
        else
            stMin[v] = pii(s[tl], 1);
    }
    else {
        int tm = (tl + tr)/2;
        BuildSt(v*2, tl, tm, IsGCD);
        BuildSt(v*2+1, tm+1, tr, IsGCD);
        if (IsGCD)
            stGCD[v] = GCD(stGCD[v*2], stGCD[v*2+1]);
        else
            stMin[v] = Combine(stMin[v*2], stMin[v*2+1]);
    }
}

int QueryGCD(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return 0;
    if ((l <= tl) && (tr <= r))
        return stGCD[v];
    int tm = (tl + tr)/2;
    return GCD(QueryGCD(v*2, tl, tm, l, r), QueryGCD(v*2+1, tm+1, tr, l, r));
}

pii QueryMin(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return pii(1e9 + 1, 0);
    if ((l <= tl) && (tr <= r))
        return stMin[v];
    int tm = (tl + tr)/2;
    return Combine(QueryMin(v*2, tl, tm, l, r), QueryMin(v*2+1, tm+1, tr, l, r));
}

void Solve() {
    BuildSt(1, 1, n, true);
    BuildSt(1, 1, n, false);
    for (int i=1; i<=t; i++) {
        int l, r;
        cin >> l >> r;
        ll g = QueryGCD(1, 1, n, l ,r);
        pii tmp = QueryMin(1, 1, n, l, r);
        int ans = r - l + 1;
        if (tmp.first == g)
            ans -= tmp.second;
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cin >> t;
    Solve();
    return 0;
}
