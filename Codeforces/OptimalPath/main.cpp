#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n, m;

ll Solution() {
    ll ans = (m*(m+1))/2 + (m*(n+1)*n)/2 - m;
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> m;
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
