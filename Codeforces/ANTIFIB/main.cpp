#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

void Solve() {
    long long f1, f2, fn;
    for (int i=1; i<=n; i++) {
        f1 = 1;
        f2 = 2;
        cout << f1 << ' ' << f2 << ' ';
        for (int j=3; j<=n; j++) {
            fn = f1 + f2 + i;
            f1 = f2;
            f2 = fn;
            cout << fn << ' ';
        }
        cout << '\n';
    }
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
