#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, q, i, j, x, y;

void SolveTestCase() {
    if ((i == x) && (j == y)) {
        cout << "0\n";
        return;
    }
    if (((i + j) % 2) != ((x + y) % 2)) {
        cout << "-1\n";
        return;
    }
    if (abs(i - x) == abs(j - y)) {
        cout << 1 << '\n' << x << ' ' << y << '\n';
        return;
    }
    cout << 2 << '\n';
    ll tmp = ((x - y) + (j - i))/2;
    if ((x - tmp >= 1) && (y + tmp <= n) && (x - tmp <= n) && (y + tmp >= 1)) {
        cout << x - tmp << ' ' << y + tmp << '\n';
        cout << x << ' ' << y << '\n';
        return;
    }
    tmp = ((i - j) + (y - x))/2;
    if ((x + tmp <= n) && (y - tmp >= 1) && (x + tmp >= 1) && (y - tmp <= n)) {
        cout << x + tmp << ' ' << y - tmp << '\n';
        cout << x << ' ' << y << '\n';
        return;
    }
    tmp = (i + j - x - y)/2;
    if ((x + tmp <= n) && (y + tmp <= n) && (x + tmp >= 1) && (y + tmp >= 1)) {
        cout << x + tmp << ' ' << y + tmp << '\n';
        cout << x << ' ' << y << '\n';
        return;
    }
    tmp = (x + y - i - j)/2;
    if ((x - tmp >= 1) && (y - tmp >= 1) && (x - tmp <= n) && (y - tmp <= n)) {
        cout << x - tmp << ' ' << y - tmp << '\n';
        cout << x << ' ' << y << '\n';
        return;
    }
}

void Solve() {
    cin >> n >> q;
    for (ll ii=1; ii<=q; ii++) {
        cin >> i >> j >> x >> y;
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
