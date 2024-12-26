#include <iostream>
#define MaxN 200000
using namespace std;
typedef long long ll;
const ll Mod = 998244353;
int t;
ll n, m, k;
ll Fact[MaxN+5], InvFact[MaxN+5];

ll FastPow(ll base, ll e, const ll& Mod) {
    ll ans = 1;
    while (e > 0) {
        if (e&1LL)
            ans = (ans*base)%Mod;
        base = (base*base)%Mod;
        e >>= 1LL;
    }
    return ans;
}

ll InverseMod(ll x, const ll& Mod) {
    return FastPow(x, Mod-2, Mod);
}

void MakeFac() {
    Fact[0] = 1;
    for (ll i = 1; i <= MaxN; i++) {
        Fact[i] = (Fact[i-1]*i)%Mod;
        InvFact[i] = InverseMod(Fact[i], Mod);
    }
}

ll nCk(ll n, ll k) {
    if (n < k)
        return 0;
    if ((k == 0) || (k == n))
        return 1;
    ll ans = ((Fact[n] * InvFact[k])%Mod * InvFact[n-k])%Mod;
    return ans;
}

ll Solution() {
    ll ans = 0, MinusOne = 1;
    for (ll i = 0; i<=m; i++) {
        ll mCi = nCk(m, i);
        ll tmp = nCk(m+k - i*n - 1LL, m-1LL);
        ans = (ans + (((MinusOne*mCi + Mod)%Mod)*tmp)%Mod)%Mod;
        MinusOne = MinusOne * (-1LL);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeFac();
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        cout << Solution() << '\n';
    }
    return 0;
}
