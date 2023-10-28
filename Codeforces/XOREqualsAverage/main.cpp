#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n;

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        if (n&1) {
            for (int i=1; i<=n; i++)
                cout << 16 << ' ';
        }
        else {
            cout << 6 << ' ' << 2 << ' ';
            for (int i=1; i<=n-2; i++)
                cout << 4 << ' ';
        }
        cout << '\n';
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
