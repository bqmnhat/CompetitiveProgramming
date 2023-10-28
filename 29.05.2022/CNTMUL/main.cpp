#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll L, H, a, b;

ll Solution() {
    ll ans = 0, lcm = (a*b)/__gcd(a, b);
    ans = ((H/a) - ((L-1)/a)) + ((H/b) - ((L-1)/b)) - 2*((H/lcm) - ((L-1)/lcm));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CNTMUL.INP", "r", stdin);
    freopen("CNTMUL.OUT", "w", stdout);
    cin >> L >> H >> a >> b;
    cout << Solution();
    return 0;
}
