#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m;

void Solve() {
    while ((cin >> n >> m) && ((n != 0) || (m != 0))) {
        if (n > m)
            cout << "0.000000";
        else if (n == 0)
            cout << "1.000000";
        else {
            ld ans = ld(m - n + 1LL)/(ld(m + 1LL));
            cout << fixed << setprecision(6) << ans;
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
