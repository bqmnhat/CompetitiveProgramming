#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, ls = 0;
ll Time[200002], staff[200001];

ll Solution() {
    for (int i=1; i<=n; i++) {
        ll ti, k;
        cin >> ti >> k;
        Time[i+1] = Time[i] + ti;
        for (int j=1; j<=k; j++) {
            ll x;
            cin >> x;
            ls++;
            staff[ls] = max(0LL, x - Time[i]);
        }
    }
    sort(staff+1, staff+1+ls);
    ll ans = Time[n+1] + staff[m];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie();
    freopen("BUS.INP", "r", stdin);
    freopen("BUS.OUT", "w", stdout);
    cin >> n >> m;
    cout << Solution();
    return 0;
}
