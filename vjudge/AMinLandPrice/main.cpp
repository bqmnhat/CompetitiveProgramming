#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50
using namespace std;
typedef long long ll;
ll a[MaxN+1];
int t, n;
const ll MaxBudget = 5 * ll(1e6);

void ReadData() {
    n = 1;
    while ((cin >> a[n]) && (a[n] != 0))
        n++;
    n--;
}

ll Solution() {
    sort(a+1, a+1+n, greater<ll>());
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        ans += (2*powl(a[i], i));
        if (ans > MaxBudget)
            return -1;
    }
    if (ans > MaxBudget)
        return -1;
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        ReadData();
        ll ans = Solution();
        if (ans == -1)
            cout << "Too expensive\n";
        else
            cout << ans << '\n';
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
