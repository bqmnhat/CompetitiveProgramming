#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a, p;

ll LargeMul(ll a, ll b) {
    if (b == 1LL)
        return a%p;
    if (b&1)
        return (LargeMul(a, b-1LL) + a)%p;
    return (LargeMul(a, b/2)*2)%p;
}

ll FastPow(ll base, ll e) {
    ll ans = 1;
    while (e > 0) {
        if (e&1LL)
            ans = LargeMul(ans, base)%p;
        base = LargeMul(base, base)%p;
        e >>= 1LL;
    }
    return ans%p;
}

ll InverseModulo(ll val, ll Mod) {
    return FastPow(val, Mod - 2);
}

ll Solution2Sub() {
    ll val = 1, num = n+1, ans = 0;
    for (int i=0; i<=n; i++) {
        ans = (ans + (val*(num%p)%p))%p;
        val = (val*a)%p;
        num = num-1LL;
    }
    return ans;
}

ll SolutionLast2Sub() {
    return LargeMul((LargeMul((FastPow(a, n + 2)%p - a%p + p)%p, InverseModulo(a-1LL, p)%p)%p - (n + 1LL)%p + p)%p, InverseModulo(a-1LL, p)%p)%p;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("WARMUP.INP", "r", stdin);
    freopen("WARMUP.OUT", "w", stdout);
    cin >> a >> n >> p;
    if (n <= 1000000)
        cout << Solution2Sub();
    else
        cout << SolutionLast2Sub();
    return 0;
}
