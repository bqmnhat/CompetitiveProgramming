#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
ll Fact[MaxN+5], InvFact[MaxN+5], cnt[MaxN+5][31];
int q, l, r, n;
string s;

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
        Fact[i] = (Fact[i-1] * i)%Mod;
        InvFact[i] = InvMod(Fact[i], Mod);
    }
}

void MakeCnt() {
    for (int i=1; i<=n; i++)
        cnt[i][s[i] - 'a' + 1]++;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=26; j++)
            cnt[i][j] += cnt[i-1][j];
}

ll Solution(int l, int r) {
    int cntOdd = 0, cntSum = 0;
    for (int i=1; i<=26; i++) {
        cntOdd += ((cnt[r][i] - cnt[l-1][i])%2);
        cntSum += (cnt[r][i] - cnt[l-1][i]) - ((cnt[r][i] - cnt[l-1][i])%2);
    }
    ll tmp = Fact[cntSum/2];
    for (int i=1; i<=26; i++)
        tmp = (tmp*InvFact[(cnt[r][i] - cnt[l-1][i])/2])%Mod;
    ll ans;
    if (cntOdd == 0)
        ans = tmp;
    else
        ans = (1LL*cntOdd*tmp)%Mod;
    return ans;
}

void Solve() {
    for (int i=1; i<=q; i++) {
        cin >> l >> r;
        cout << Solution(l, r) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeFact();
    cin >> s >> q;
    n = s.length();
    s = ' ' + s;
    MakeCnt();
    Solve();
    return 0;
}
