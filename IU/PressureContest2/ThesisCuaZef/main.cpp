#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
int t;
ll a, b, n, f[MaxN+1];
const ll Mod = 1e9 + 7;

ll FastPow(ll x, int p, const ll Mod) {
    ll ans = 1;
    x = x%Mod;
    while (p > 0) {
        if (p%2 == 1)
            ans = (ans*x)%Mod;
        x = (x*x)%Mod;
        p = p/2;
    }
    return ans;
}

ll InvMod(ll x, const ll Mod) {
    ll ans = FastPow(x, Mod-2, Mod);
    if ((ans*x)%Mod == 1)
        return ans;
    return -1;
}

bool IsCute(ll x, int a, int b) {
    while (x > 0){
        ll tmp = x%10;
        if ((tmp != a) && (tmp != b))
            return false;
        x = x/10;
    }
    return true;
}

void MakeFac() {
    f[0] = 1;
    for (int i=1; i<=MaxN; i++) {
        f[i] = (f[i-1]*i)%Mod;
    }
}

ll Solution() {
    ll ans = 0;
    for (int i=0; i<=n; i++) {
        int j = (n-i);
        if (!IsCute(1LL*i*a + 1LL*j*b, a, b))
            continue;
        ll tmp = (f[i] * f[j])%Mod;
        ll tmp2 = InvMod(tmp, Mod), tmpi = InvMod(f[i], Mod), tmpj = InvMod(f[j], Mod);
        if (tmp2 != -1) {
            ans += (f[n] * tmp2)%Mod;
            ans %= Mod;
        }
        else if ((tmpi != -1) && (tmpj != -1))
            ans += (f[n] * tmpi * tmpj)%Mod;
        else
            ans += ((f[n]/f[i])%Mod * (f[n]/f[j])%Mod);
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> a >> b >> n;
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeFac();
    cin >> t;
    Solve();
    return 0;
}
