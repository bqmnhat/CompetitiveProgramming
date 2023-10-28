#include <iostream>
#include <bits/stdc++.h>
#define MaxN 3000000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int t, n;
pll a[2*MaxN+1];
ll BulletLeft[2*MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i+n] = a[i];
    }
}

void FindBulletLeft() {
    for (int i=2; i <= 2*n; i++) {
        ll HpLeft = max(0LL, a[i].first - a[i-1].second);
        BulletLeft[i] = BulletLeft[i-1] + HpLeft;
    }
}

ll Solution() {
    ll ans = 1e18;
    for (int i=1; i<=n; i++) {
        ll BulletUsed = BulletLeft[i+n-1] - BulletLeft[i] + a[i].first;
        ans = min(BulletUsed, ans);
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        FindBulletLeft();
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
