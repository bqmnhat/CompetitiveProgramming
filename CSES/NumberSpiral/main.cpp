#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll y, x;

ll Solution() {
    ll k = max(x, y);
    ll ans = (k - 1LL)*(k-1LL);
    if (k&1) {
        if (x < y)
            ans += x;
        else
            ans += (k + (k - y));
    }
    else {
        if (y < x)
            ans += y;
        else
            ans += (k + (k - x));
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> y >> x;
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
