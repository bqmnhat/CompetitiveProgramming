#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200010
using namespace std;
typedef long long ll;
const ll Mod = 1e9;
int n, h, a[MaxN+5], Sieve[MaxN+5];

void MakeSieve() {
    for (int i=2; i*i<=MaxN; i++)
        if (Sieve[i] == 0)
            for (int j=i; i*j<=MaxN; j++)
                Sieve[i*j] = i;
}

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void Factorize(ll val, vector<ll>& cnt) {
    while (val > 1LL) {
        ll p = Sieve[val];
        if (p == 0)
            p = val;
        cnt[p]++;
        val/=p;
    }
}

ll FastPow(ll base, ll e, const ll Mod) {
    ll ans = 1;
    while (e) {
        if (e&1)
            ans = (ans*base)%Mod;
        base = (base*base)%Mod;
        e >>= 1LL;
    }
    return ans;
}

int SolutionForQuery1() {
    int ans = 2;
    for (int i=n-1; i>=1; i--) {
        if (a[i] > a[i+1])
            break;
        ans++;
    }
    return ans;
}

ll SolutionForQuery2() { // It's actually the (n+1)th Catalan number
    ll ans = 1;
    vector<ll> Denom(2*MaxN+5, 0), Nume1(2*MaxN+5, 0), Nume2(2*MaxN+5, 0);
    for (ll i=1; i<=2*n+2; i++) {
        if (i <= n+1)
            Factorize(i, Nume1);
        if (i <= n+2)
            Factorize(i, Nume2);
        Factorize(i, Denom);
    }
    for (int i=1; i<=MaxN; i++) {
        Denom[i] -= Nume1[i] + Nume2[i];
        ans = (ans*FastPow(i, Denom[i], Mod))%Mod;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> h;
    ReadData();
    MakeSieve();
    cout << SolutionForQuery1() << '\n';
    cout << SolutionForQuery2();
    return 0;
}
