#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k;

bool IsSquare(ll x) {
    ll m = sqrt(x);
    return (m*m == x);
}

int Solution() {
    ll m = sqrt(k);
    int ans = 0;
    for (ll i = 1; i<=m; i++) {
        ll f1 = i*i;
        ll f2 = k - f1;
        if (IsSquare(f2))
            ans++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k;
    cout << Solution();
    return 0;
}
