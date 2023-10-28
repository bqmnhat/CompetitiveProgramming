#include <iostream>
#include <bits/stdc++.h>
#define MaxK 100
using namespace std;
typedef long long ll;
ll n, a[MaxK+1];
int k;

void ReadData() {
    for (int i=0; i<k; i++)
        cin >> a[i];
}

ll LCM(ll a, ll b) {
    ll ans = (a/__gcd(a, b));
    ans = ans * b;
    return ans;
}

ll Solution() {
    ll ans = 0;
    if (k > 20) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<k; j++) {
                if (i % a[j] == 0) {
                    ans++;
                    break;
                }
            }
        }
    }
    else {
        for (int i=1; i<(1 << k); i++) {
            ll lcm = 1, cnt = 0;
            bool Overload = false;
            for (int j=0; j<k; j++) {
                if (i & (1 << j)) {
                    cnt++;
                    lcm = LCM(lcm, a[j]);
                    if ((lcm < 0) || (lcm > n))
                        Overload = true;
                }
            }
            if (Overload)
                lcm = n+1LL;
            if (cnt%2)
                ans = ans + (n/lcm);
            else
                ans = ans - (n/lcm);
        }
    }
    return (n - ans);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    cout << Solution();
    return 0;
}
