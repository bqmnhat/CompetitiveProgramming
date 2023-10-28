#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n, m, a, d, Div[5];

ll LCM(ll a, ll b) {
    ll g = __gcd(a, b);
    return ((a*b)/g);
}

ll Solution() {
    ll ans = m - n + 1LL;
    for (int i = 0; i<5; i++)
        Div[i] = a + 1LL*i*d;
    for (int i=1; i<(1 << 5); i++) {
        ll lcm = 1;
        int cnt = -1, tmp = i, cntOnes = 0;
        while (tmp > 0) {
            cnt++;
            if (tmp&1LL) {
                lcm = LCM(lcm, Div[cnt]);
                cntOnes++;
            }
            tmp >>= 1LL;
        }
        if (cntOnes&1)
            ans -= ((m/lcm) - ((n-1LL)/lcm));
        else
            ans += ((m/lcm) - ((n-1LL)/lcm));
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> m >> a >> d;
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
