#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c;
int t;

ll FastPow(ll base, ll e, const ll Mod) {
    ll ans = 1;
    while (e) {
        if (e&1LL)
            ans = (ans*base)%Mod;
        base = (base*base)%Mod;
        e>>=1LL;
    }
    return ans;
}

ll InvMod(ll val, const ll Mod) {
    return (FastPow(val, Mod-2, Mod));
}

bool SolutionExist(ll a, ll b, ll c) {
    ll g = __gcd(a, b);
    /*if (c%g != 0)
        return false;
    ll x0 = ((c/g)*InvMod(a/g, b/g))%(b/g);
    return (((c - a*x0)%b) == 0);*/
    return (c%g == 0);
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> a >> b >> c;
        cout << "Case " << i << ": ";
        if (SolutionExist(a, b, c))
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
