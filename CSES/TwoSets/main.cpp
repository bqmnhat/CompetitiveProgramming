#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

void Solve() {
    vector<ll> g1, g2;
    if (((n*(n+1LL))/2)&1LL) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    ll sum1 = 0, sum2 = 0;
    for (int i=n; i>0; i-=2) {
        ll a1 = i, a2 = i-1;
        if (sum1 < sum2) {
            g1.push_back(a1);
            g2.push_back(a2);
            sum1 += a1;
            sum2 += a2;
        }
        else {
            g1.push_back(a2);
            g2.push_back(a1);
            sum1 += a2;
            sum2 += a1;
        }
    }
    if (g1.back() == 0)
        g1.pop_back();
    if (g2.back() == 0)
        g2.pop_back();
    sort(g1.begin(), g1.end());
    sort(g2.begin(), g2.end());
    cout << g1.size() << '\n';
    for (ll x: g1)
        cout << x << ' ';
    cout << '\n' << g2.size() << '\n';
    for (ll x: g2)
        cout << x << ' ';
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
