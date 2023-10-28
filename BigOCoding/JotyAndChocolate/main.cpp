#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a, b, p, q;

ll LCM(ll a, ll b) {
    ll g = __gcd(a, b);
    return ((a*b)/g);
}

ll Solution() {
    ll l = LCM(a, b);
    ll ans = (n/a)*p + (n/b)*q - min(p, q)*(n/l);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a >> b >> p >> q;
    cout << Solution();
    return 0;
}
