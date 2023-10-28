#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p,q,r;

ll DecVal(ll a, ll base) {
    ll p = 1, ans = 0;
    while (a > 0) {
        ans += (a%10)*p;
        a = a/10;
        p = p*base;
    }
    return ans;
}

ll BaseVal(ll a, ll base) {
    ll ans = 0;
    int Bval[21], lb = -1;
    while (a > 0) {
        lb++;
        Bval[lb] = a%base;
        a = a/base;
        if (Bval[lb] > 9)
            return -1;
    }
    for (int i=lb; i>=0; i--) {
        ans = ans*10 + Bval[i];
    }
    return ans;
}

int MinB() {
    for (int i=2; i<=16; i++) {
        ll tmp = DecVal(p, i)*DecVal(q, i);
        if (BaseVal(tmp, i) == r)
            return i;
    }
    return 0;
}

int main()
{
    freopen("MULT.INP", "r", stdin);
    freopen("MULT.OUT", "w", stdout);
    cin >> p >> q >> r;
    cout << MinB();
    return 0;
}
