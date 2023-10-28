#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n, a[61], la = -1;

ll Solution() {
    ll ans = 0;
    while (n > 0) {
        la++;
        if (n%2 == 1)
            a[la] = 1;
        else
            a[la] = 0;
        n = n/2;
    }
    for (ll i=0; i<=la; i++) {
        if (a[i] == 1)
            ans += ((1LL << i+1) - 1);
    }
    return ans;
}

int main()
{
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n;
        la = -1;
        cout << Solution() << '\n';
    }
    return 0;
}
