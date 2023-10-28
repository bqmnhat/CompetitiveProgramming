#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, n, Mod, PhiMod;

int CalPhi(ll x) {
    int i = 2, m = sqrt(x), OriX = x;
    vector<int> Facts;
    while ((i <= m) && (x > 1)) {
        if (x%i == 0)
            Facts.push_back(i);
        while (x%i == 0)
            x/=i;
        i++;
    }
    if (x > 1)
        Facts.push_back(x);
    ll ans = OriX;
    for (ll tmp: Facts)
        ans /= tmp;
    for (ll tmp: Facts)
        ans *= (tmp-1LL);
    return ans;
}

ll FastPow(ll base, ll e, const ll Mod) {
    ll ans = 1LL%Mod;
    base %= Mod;
    while (e) {
        if (e&1LL)
            ans = (ans*base)%Mod;
        base = (base*base)%Mod;
        e >>= 1LL;
    }
    return ans;
}

ll Solution() {
    Mod = Mod*(x - 1LL);
    ll ans = (FastPow(x, n+1LL, Mod) - 1LL + Mod)%Mod;
    ans /= (x - 1LL);
    ans %= Mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> x >> n >> Mod;
    cout << Solution();
    return 0;
}
