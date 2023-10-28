#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a, k;

ll GCD(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x0, y0;
    ll g = GCD(b, a%b, x0, y0);
    x = y0;
    y = x0 - y0*(a/b);
    return g;
}

bool Diophantine(ll a, ll b, ll c, ll& x, ll& y, ll& g) {
    if ((a == 0) && (b == 0)) {
        x = 0;
        y = 0;
        return (c == 0);
    }
    ll xg, yg;
    g = GCD(abs(a), abs(b), xg, yg);
    if (c%g != 0)
        return false;
    x = xg*(c/g);
    y = yg*(c/g);
    if (a < 0)
        x *= (-1LL);
    if (b < 0)
        y *= (-1LL);
    return true;
}

void shift_solution(ll& x, ll& y, int a, int b, int cnt) {
    x += cnt*b;
    y -= cnt*a;
}

void SolveTestCase() {
    ll x, y, X = n - k - a, g;
    if (!Diophantine(a, -m, X, x, y, g))
        cout << "Impossible\n";
    else {
        if (((a == 0) || (m == 0)) && ((x < 0) || (y < 0))) {
            cout << "Impossible\n";
            return;
        }
        int sign_a = 1, sign_b = -1;
        ll b = -m;
        a/=g;
        b/=g;
        shift_solution(x, y, a, b, (0 - x)/(-m));
        if (x < 0)
            shift_solution(x, y, a, b, sign_b);
        ll lx1 = x;
        shift_solution(x, y, a, b, y/a);
        if (y < 0)
            shift_solution(x, y, a, b, -sign_a);
        ll lx2 = x;
        ll lx = max(lx1, lx2);
        ll ans = (k + a + a*lx);
        cout << ans << '\n';
    }
}

void Solve() {
    while ((cin >> n >> m >> a >> k) && ((n != 0) || (m != 0) || (a != 0) || (k != 0)))
        SolveTestCase();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
