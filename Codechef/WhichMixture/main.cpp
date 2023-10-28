#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, a, b;

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> a >> b;
        if ((a > 0) && (b > 0)) {
            cout << "Solution" << '\n';
            continue;
        }
        if (b == 0) {
            cout << "Solid" << '\n';
            continue;
        }
        if (a == 0) {
            cout << "Liquid" << '\n';
            continue;
        }
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
