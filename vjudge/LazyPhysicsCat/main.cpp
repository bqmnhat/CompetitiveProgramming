#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int t;
ll L, A;
const ld Pi = acos(-1);

ld Solution() {
    ld ans = ((((ld(A)/180.0) * Pi)/(2.0*Pi)) * Pi * ld(L*L)) - (0.5 * sin(((ld(A)/180.0) * Pi)) * ld(L*L));
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> L >> A;
        cout << fixed << setprecision(6) << Solution() << '\n';
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
