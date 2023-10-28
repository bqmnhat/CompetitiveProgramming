#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef long long ll;
int n;
ll Mod, a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll FastPow(ll base, ll e, ll Mod) {
    ll ans = 1;
    while (e > 0) {
        if (e&1)
            ans = (ans*base)%Mod;
        base = (base*base)%Mod;
        e >>= 1LL;
    }
    return ans;
}

ll CalPhi(ll n) {
    ll OriN = n;
    vector<ll> Factors;
    Factors.clear();
    int m = sqrt(n), i = 2;
    while ((i <= m) && (n > 1)) {
        if (n%i == 0)
            Factors.push_back(i);
        while (n%i == 0)
            n/=i;
        i++;
    }
    if (n > 1)
        Factors.push_back(n);
    ll ans = OriN;
    for (int x: Factors)
        ans /= x;
    for (int x: Factors)
        ans = ans*(x-1LL);
    return ans;
}

ll CalSolution(int i, ll ModVal) {
    if (i == n)
        return a[i]%ModVal;
    ll PhiModVal = CalPhi(ModVal);
    return FastPow(a[i], PhiModVal + CalSolution(i+1, PhiModVal), ModVal);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> Mod;
    ReadData();
    cout << CalSolution(1, Mod);
    return 0;
}
