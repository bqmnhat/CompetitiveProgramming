#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, a[200001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void Solve() {
    if ((a[1] != n) && (a[n] != n))
        cout << "-1" << '\n';
    else {
        for (int i=n; i>=1; i--)
            cout << a[i] << ' ';
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        Solve();
    }
    return 0;
}
