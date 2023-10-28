#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

void Solve() {
    for (ll k=1; k<=n; k++) {
        ll ans = ((k*k)*((k*k)-1LL)/2) - 4*(k-1LL)*(k-2);
        cout << ans << '\n';
    }
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
