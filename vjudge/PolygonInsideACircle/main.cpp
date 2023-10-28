#include <iostream>
#include <bits/stdc++.h>
#define MaxN 20000
using namespace std;
typedef long long ll;
typedef long double ld;
ld r;
ll n;
const ld Pi = acos(-1LL);

ld Solution() {
    ld alpha = ((2.00*Pi)/ld(n));
    ld tri = 0.5*ld(r)*ld(r)*sin(alpha);
    ld ans = tri*ld(n);
    return ans;
}

void Solve() {
    while (cin >> r >> n)
        cout << setprecision(3) << fixed << Solution() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
