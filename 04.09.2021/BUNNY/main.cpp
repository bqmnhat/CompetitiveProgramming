#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long n, Mod = 1000000;

ll Solution() {
    ll a = ll(n/3) + 1;
    ll ans = a*n - 3*(a*(a-1)/2);
    if (n % 2 == 0)
        ans = (ans - a/2)/2;
    else
        ans = (ans - (a-1)/2-1)/2;
    ans = ans + a;
    return ans%Mod;
}

int main()
{
    freopen("BUNNY.INP", "r", stdin);
    freopen("BUNNY.OUT", "w", stdout);
    cin >> n;
    cout << Solution();
    return 0;
}
