#include <iostream>
#include <bits/stdc++.h>
#define MaxN 250000
using namespace std;
typedef long long ll;
ll n, m, fac[MaxN+1];

void MakeFac() {
    fac[0] = fac[1] = 1;
    for (int i=2; i<=MaxN; i++)
        fac[i] = (fac[i-1]*1LL*i)%m;
}

ll Solution() {
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        ll tmpans = ((((n - 1LL*i + 1LL)*fac[i])%m) * (((n - 1LL*i + 1LL)*fac[n - i])%m))%m;
        ans = (ans + tmpans)%m;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    MakeFac();
    cout << Solution();
    return 0;
}
