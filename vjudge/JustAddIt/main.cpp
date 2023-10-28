#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
const ll Mod = 1e7 + 7;

ll FastPow(ll x, ll e) {
    ll ans = 1;
    while (e > 0) {
        if (e&1)
            ans = (ans * x)%Mod;
        x = (x*x)%Mod;
        e=e/2;
    }
    return ans;
}

ll Solution(ll n, ll k) {
    return ((FastPow(n, k) + FastPow(n, n))%Mod + (2*FastPow(n-1, k) + 2*FastPow(n-1, n-1))%Mod)%Mod;
}

void Solve() {
    while ((cin >> n >> k) && (n != 0) && (k != 0))
        cout << Solution(n, k) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
