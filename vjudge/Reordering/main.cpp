#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000
#define MaxC 26
using namespace std;
typedef long long ll;
ll dp[MaxC+1][MaxN+1], Fac[2*MaxN+1], InvFac[2*MaxN+1];
int cnt[MaxC+1];
string s;
const ll Mod = 998244353;

ll FastPow(ll base, ll e, ll Mod) {
    ll ans = 1;
    while (e > 0) {
        if (e&1LL)
            ans = (ans*base)%Mod;
        base = (base*base)%Mod;
        e >>= 1LL;
    }
    return ans;
}

ll InvMod(ll base, ll Mod) {
    return FastPow(base, Mod-2, Mod);
}

void MakeFac() {
    Fac[0] = 1;
    InvFac[0] = InvMod(1, Mod);
    for (int i=1; i<=2*MaxN; i++) {
        Fac[i] = (Fac[i-1]*1LL*i)%Mod;
        InvFac[i] = InvMod(Fac[i], Mod);
    }
}

ll Factorial(int x) {
    if (x < 0)
        return 0;
    return Fac[x];
}

ll InvFactorial(int x) {
    if (x < 0)
        return 0;
    return InvFac[x];
}

ll nCk(int n, int k) {
    if (n < k)
        return 0;
    ll ans = ((Factorial(n)*InvFactorial(n-k))%Mod*InvFactorial(k))%Mod;
    return ans;
}

ll Solution() {
    int l = s.length();
    for (int i = 0; i<l; i++)
        cnt[s[i] - 'a' + 1]++;
    dp[0][0] = 1;
    for (int i=1; i<=MaxC; i++)
        for (int j=0; j<=l; j++)
            for (int k=0; k<=min(cnt[i], j); k++)
                dp[i][j] = (dp[i][j] + (dp[i-1][j-k]*nCk(j, k))%Mod)%Mod;
    ll ans = 0;
    for (int j=1; j<=l; j++)
        ans = (ans + dp[MaxC][j])%Mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeFac();
    cin >> s;
    cout << Solution();
    return 0;
}
