#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef long long ll;
const ll Mod = 1e9;
int n, m;
ll a[MaxN+5], b[MaxN+5];
unordered_map<ll, int> ExpA, ExpB;

void ReadData() {
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    cin >> m;
    for (int i=1; i<=m; i++)
        cin >> b[i];
}

ll FastPow(ll base, ll e, const ll Mod) {
    ll ans = 1;
    while (e) {
        if (e&1LL)
            ans = (ans*base)%Mod;
        base = (base*base)%Mod;
        e >>= 1LL;
    }
    return ans;
}

void Factorize(ll val, unordered_map<ll, int>& Exp) {
    ll tmp = sqrt(val), i = 2;
    while ((i <= tmp) && (val > 1)) {
        int cnt = 0;
        while (val%i == 0LL) {
            val/=i;
            cnt++;
        }
        Exp[i] += cnt;
        i++;
    }
    if (val > 1)
        Exp[val]++;
}

int CntDig(ll val) {
    int ans = 0;
    while (val > 0) {
        ans++;
        val/=10;
    }
    return ans;
}

void Solve() {
    ll ans = 1;
    for (int i=1; i<=n; i++)
        Factorize(a[i], ExpA);
    for (int i=1; i<=m; i++)
        Factorize(b[i], ExpB);
    bool MoreThan9 = false;
    for (auto it = ExpA.begin(); it != ExpA.end(); it++) {
        ll PrimeVal = (*it).first, ThisECnt = (*it).second;
        ll e = min(ThisECnt, 1LL*ExpB[PrimeVal]);
        ans = ans*(FastPow(PrimeVal, e, Mod));
        if (ans >= Mod) {
            ans %= Mod;
            MoreThan9 = true;
        }
    }
    if (!MoreThan9) {
        cout << ans;
        return;
    }
    int DigCnt = CntDig(ans);
    if (DigCnt == 9) {
        cout << ans;
        return;
    }
    else {
        for (int i=1; i<=9-DigCnt; i++)
            cout << "0";
        cout << ans;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ReadData();
    Solve();
    return 0;
}
