#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int t;
ll n;
const ll Constant = 1e9;

ll Solution() {
    ld tmp = 1.0 - (1.0/(ld(n) + 1.0));
    return (1.0 - tmp)*Constant;
}

void Solve() {
    cout << fixed << setprecision(9);
    for (int i=1; i<=t; i++) {
        cin >> n;
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
