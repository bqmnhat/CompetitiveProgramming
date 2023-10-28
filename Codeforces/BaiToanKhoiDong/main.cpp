#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, n, Mod;

ll LargeMul(ll a, ll b, ll Mod) {
    if (b == 1LL)
        return a%Mod;
    if (b&1)
        return (LargeMul(a, b-1, Mod) + a)%Mod;
    return (LargeMul(a, b/2, Mod)*2)%Mod;
}

ll SolutionSub1() {
    ll ans = 0;
    for (int i=0; i<=n; i++) {
        ll tmpans = 0, Cur = 1;
        for (int j=0; j<=i; j++) {
            tmpans += Cur;
            tmpans %= Mod;
            Cur = (Cur*a)%Mod;
        }
        ans += tmpans;
        ans %= Mod;
    }
    return ans;
}

ll FastPow(ll base, ll e, ll Mod) {
    ll ans = 1;
    base%=Mod;
    while (e > 0) {
        if (e&1LL)
            ans = LargeMul(ans, base, Mod);
        base = LargeMul(base, base, Mod);
        e >>= 1LL;
    }
    return (ans%Mod);
}

ll InvMod(ll base, ll Mod) {
    return (FastPow(base, Mod-2, Mod));
}

ll Solution() {
    ll NumePart1 = (FastPow(a, n+2, Mod) - a%Mod + Mod)%Mod, NumePart2 = LargeMul(n+1LL, a-1LL, Mod);
    ll Deno = InvMod(LargeMul(a-1LL, a-1LL, Mod), Mod);
    ll ans =  LargeMul((NumePart1 - NumePart2 + Mod)%Mod, Deno, Mod);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> n >> Mod;
    if ((n <= 1000) && (a <= 1000) && (Mod <= 1000))
        cout << SolutionSub1();
    else
        cout << Solution();
    return 0;
}
