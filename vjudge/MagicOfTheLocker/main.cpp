#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n;
const ll Mod = 1e9 + 7;

ll FastPow(ll x, ll e) {
    ll ans = 1;
    while (e > 0) {
        if (e&1)
            ans = (ans * x)%Mod;
        x = (x*x)%Mod;
        e=e/2;
    }
    return ans;
}

bool Cmp(ll pow21, ll pow31, ll pow22, ll pow32) {
    ll First = pow21 * log(2) + pow31 * log(3);
    ll Second = pow22 * log(2) + pow32 * log(3);
    return (First > Second);
}

ll Solution() {
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (n == 3)
        return 3;
    ll pow2 = 0, pow3 = 0;
    ll pow20, pow30, pow21, pow31, pow22, pow32;
    pow20 = pow30 = pow21 = pow31 = pow22 = pow32 = -1;
    if (n%3 == 0) {
        pow20 = 0;
        pow30 = n/3;
    }
    if ((n-2)%3 == 0) {
        pow21 = 1;
        pow31 = (n-2)/3;
    }
    if ((n-4)%3 == 0) {
        pow22 = 2;
        pow32 = (n-4)/3;
    }
    if (((pow20 != -1) && (pow30 != -1)) && (Cmp(pow20, pow30, pow2, pow3))) {
        pow2 = pow20;
        pow3 = pow30;
    }
    if (((pow21 != -1) && (pow31 != -1)) && (Cmp(pow21, pow31, pow2, pow3))) {
        pow2 = pow21;
        pow3 = pow31;
    }
    if (((pow22 != -1) && (pow32 != -1)) && (Cmp(pow22, pow32, pow2, pow3))) {
        pow2 = pow22;
        pow3 = pow32;
    }
    ll ans = (FastPow(2, pow2)*FastPow(3, pow3))%Mod;
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
