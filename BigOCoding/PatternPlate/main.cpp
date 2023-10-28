#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
using namespace std;
typedef long double ld;
int n, r, R;
const ld pi = acos(-1);

void Solve() {
    if (r > R) {
        cout << "NO";
        return;
    }
    if (2*r > R) {
        if (n <= 1)
            cout << "YES";
        else
            cout << "NO";
        return;
    }
    ld Ratio = r/ld(R-r);
    ld tmp = sin(pi/n);
    ld dif = Ratio - tmp;
    if (dif <= 1e-10)
        cout << "YES";
    else
        cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> R >> r;
    Solve();
    return 0;
}
