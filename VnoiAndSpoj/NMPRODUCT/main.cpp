#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
ll n, m;
map<ll, ll> Fac;

ll FastPow(ll x, ll pow) {
    ll res = 1;
    x %= Mod;
    while (pow > 0) {
        if (pow&1LL)
            res = (res*x)%Mod;
        x = (x*x)%Mod;
        pow >>= 1LL;
    }
    return res;
}

ll InvMod(ll x) {
    return (FastPow(x, Mod - 2));
}

ll CHOOSE(ll n, ll k)  {
    ll res = 1;
    for (int i=1; i<=k; i++)
        res = ((res * (n - k + i))%Mod*InvMod(i))%Mod;
    return res;
}

void Factorise(ll x) {
    ll tmp = sqrt(x), i = 2;
    while ((x > 1) && (i <= tmp)) {
        while (x % i == 0) {
            Fac[i]++;
            x /=i;
        }
        i++;
    }
    if (x > 1LL)
        Fac[x]++;
}

ll Solution() {
    ll ans = 1;
    for (auto i = Fac.begin(); i != Fac.end(); i++)
        ans = (ans * (CHOOSE(n + (*i).second - 1LL, n-1LL)))%Mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    Factorise(m);
    cout << Solution();
    return 0;
}
