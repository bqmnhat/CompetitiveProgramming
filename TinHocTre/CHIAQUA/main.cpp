#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int n;
vector<ll> a;

void ReadData() {
    ll x;
    for (int i=1; i<=n; i++) {
        cin >> x;
        a.push_back(x);
    }
}

ll Solution() {
    ll ans = a[0];
    for (int i=1; i<n; i++)
        ans = __gcd(ans, a[i]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("chiaqua.inp", "r", stdin);
    freopen("chiaqua.out", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
