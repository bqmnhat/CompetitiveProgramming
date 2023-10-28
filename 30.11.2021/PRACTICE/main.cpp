#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

ll Solution() {
    ll ans = 0, k = sqrt(n);
    for (int i=1; i<=k; i++)
        ans += (n/(i*1LL));
    ans = (2*ans) - (k*k);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PRACTICE.INP", "r", stdin);
    freopen("PRACTICE.OUT", "w", stdout);
    cin >> n;
    cout << Solution();
    return 0;
}
