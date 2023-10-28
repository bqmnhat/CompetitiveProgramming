#include <iostream>
#include <bits/stdc++.h>
#define MaxN 400000
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
string s;
ll Fact[MaxN+5], InvFact[MaxN+5];
int cntOpen[MaxN+5], cntClose[MaxN+5];

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

ll InvMod(ll val, const ll Mod) {
    return FastPow(val, Mod-2, Mod);
}

void MakeFact() {
    Fact[0] = 1;
    InvFact[0] = InvMod(1, Mod);
    for (ll i=1; i<=MaxN; i++) {
        Fact[i] = (Fact[i-1]*i)%Mod;
        InvFact[i] = InvMod(Fact[i], Mod);
    }
}

ll nCk(ll n, ll k, const ll Mod) {
    if (n < k)
        return 0;
    if (k == 0)
        return 1;
    ll ans = ((Fact[n]*InvFact[k])%Mod*InvFact[n-k])%Mod;
    return ans;
}

void CountCloseAndOpen() {
    for (int i=1; i<=s.length(); i++)
        cntOpen[i] = cntOpen[i-1] + (s[i-1] == '(');
    for (int i=s.length(); i>=1; i--)
        cntClose[i] = cntClose[i+1] + (s[i-1] == ')');
}

ll Solution() {
    int l = -1, len = s.length()-1;
    CountCloseAndOpen();
    ll ans = 0;
    for (int i=1; i<=len; i++) {
        if (s[i-1] != '(')
            continue;
        ans = (ans + nCk(cntOpen[i] + cntClose[i] - 1LL, cntOpen[i], Mod))%Mod;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeFact();
    cin >> s;
    cout << Solution();
    return 0;
}
