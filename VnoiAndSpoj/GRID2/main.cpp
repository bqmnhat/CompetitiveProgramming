#include <iostream>
#include <bits/stdc++.h>
#define MaxSize 200000
#define MaxN 3010
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n;
ll h, w, Fac[MaxSize+1], InvFac[MaxSize+1], dp[MaxN+1];
pii Pos[MaxN+1];
const ll Mod = 1e9 + 7;

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

void FacCal() {
    Fac[0] = 1;
    InvFac[0] = FastPow(Fac[0], Mod - 2, Mod);
    for (int i=1; i<=MaxSize; i++) {
        Fac[i] = (Fac[i-1] * 1LL * i)%Mod;
        InvFac[i] = FastPow(Fac[i], Mod - 2, Mod);
    }
}

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> Pos[i].first >> Pos[i].second;
    n++;
    Pos[n] = pii(h, w);
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

ll FromAtoB(pii A, pii B) {
    ll Deno = B.first - A.first + B.second - A.second;
    ll Nume1 = B.first - A.first, Nume2 = B.second - A.second; // Nume = Nume1! * Nume2!
    return (((Factorial(Deno)*InvFactorial(Nume1))%Mod*InvFactorial(Nume2))%Mod);
}

ll Solution() {
    sort(Pos+1, Pos+1+n);
    for (int i=1; i<=n; i++) {
        dp[i] = FromAtoB(pii(1, 1), Pos[i]);
        for (int j=1; j<i; j++)
            dp[i] = (dp[i] - (dp[j]*FromAtoB(Pos[j], Pos[i]))%Mod + Mod)%Mod;
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> h >> w >> n;
    FacCal();
    ReadData();
    cout << Solution();
    return 0;
}
