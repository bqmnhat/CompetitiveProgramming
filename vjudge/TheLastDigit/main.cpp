#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = 10;
int t;
ll a, b;

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

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> a >> b;
        cout << FastPow(a, b, Mod) << '\n';
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
