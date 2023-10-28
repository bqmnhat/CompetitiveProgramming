#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000
#define MaxC 26
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
int n, a[MaxN+5], la = 0;
ll dp[MaxN+5][MaxC+5], Fact[MaxN+5], InvFact[MaxN+5];
// Idea: String will always consist of consecutive characters => Compress the string s to Structure string cstr => Then base on the structure and count number of different strings using BinCoef
// dp[i][c] = numbers of different substrings t of length i of the compressed string cstr which any two consecutive char will be different
// Number of string of len n which can be built using substrings t of length i of cstr = (n-1)C(i-1) * Sum for all c(dp[i][c])
// Remember it is (n-1)C(i-1) but not nCi because the first char of the structure substring will definitely be at the first pos in string s
void ReadData() {
    string s;
    cin >> s;
    for (int i=0; i<n; i++) {
        int curC = s[i] - 'a' + 1;
        if (a[la] != curC) {
            la++;
            a[la] = curC;
        }
    }
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

ll InvMod(ll val, const ll Mod) {
    return FastPow(val, Mod-2, Mod);
}

void MakeFact() {
    Fact[0] = 1;
    InvFact[0] = InvMod(1, Mod);
    for (int i=1; i<=MaxN; i++) {
        Fact[i] = (Fact[i-1]*i)%Mod;
        InvFact[i] = InvMod(Fact[i], Mod);
    }
}

ll nCk(ll n, ll k) {
    if (n < k)
        return 0;
    ll ans = ((Fact[n]*InvFact[k])%Mod * InvFact[n-k])%Mod;
    return ans;
}

ll Solution() {
    dp[0][0] = 1;
    for (int i=1; i<=la; i++) {
        int curC = a[i];
        for (int j=i; j>=1; j--) {
            ll tmp = 0;
            for (int c=0; c<=26; c++)
                if (c != curC)
                    tmp = (tmp + dp[j-1][c])%Mod;
            dp[j][curC] = tmp;
        }
    }
    ll ans = 0;
    for (int i=1; i<=la; i++) {
        ll StructCnt = 0;
        for (int c=1; c<=26; c++)
            StructCnt = (StructCnt + dp[i][c])%Mod;
        ans = (ans + (nCk(n-1, i-1)*StructCnt)%Mod)%Mod;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    MakeFact();
    cout << Solution();
    return 0;
}
