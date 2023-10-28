#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, c, d, n;
ll  tk1[1000001], tk2[1000001];

void MakeTK() {
    for (ll y = 0; y<=min(n/10, b); y++) {
        for (ll z = 0; z<=min(n/20, c); z++) {
            if (10*y + 20*z >= 0)
                tk1[10*y + 20*z]++;
        }
    }
    for (ll x = 0; x<=min(n/5, a); x++) {
        for (ll t = 0; t<=min(n/50, d); t++) {
            if (n - 5*x - 50*t >= 0)
                tk2[n - 5*x - 50*t]++;
        }
    }
}

ll Solution() {
    ll ans = 0;
    for (int i=0; i<=n; i++) {
        ans += (tk1[i] * tk2[i]);
    }
    return ans;
}

int main()
{
    freopen("ATM.INP", "r", stdin);
    freopen("ATM.OUT", "w", stdout);
    cin >> a >> b >> c >> d >> n;
    MakeTK();
    cout << Solution();
    return 0;
}
