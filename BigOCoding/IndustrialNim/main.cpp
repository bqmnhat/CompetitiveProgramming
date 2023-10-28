#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int n;
ll x[MaxN+1], m[MaxN+1];

ll FindXor(ll x) {
    ll Mod = x%4;
    if (Mod == 0)
        return x;
    else if (Mod == 1)
        return 1;
    else if (Mod == 2)
        return x+1LL;
    else
        return 0;
}

ll XorRange(ll l, ll r) {
    return (FindXor(l - 1LL)^FindXor(r));
}

void Solve() {
    ll tmp = 0;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> m[i];
        tmp ^= XorRange(x[i], x[i] + m[i] - 1LL);
    }
    if (tmp == 0)
        cout << "bolik";
    else
        cout << "tolik";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Solve();
    return 0;
}
