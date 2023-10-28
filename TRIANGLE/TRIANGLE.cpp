#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[102][102], s[102][102], n;

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            cin >> a[i][j];
        }
    }
}

void Solve() {
    long long tmp = 0;
    for (int i=1; i<=n ; i++) {
        for (int j=1; j<=i; j++) {
            s[i][j] = max(s[i-1][j], s[i-1][j-1]) + a[i][j];
            if ((i == n) && (s[i][j] > tmp)) {
                    tmp = s[i][j];
            }
        }
    }
    cout << tmp;
}

int main()
{
    freopen("TRIANGLE.INP", "r", stdin);
    freopen("TRIANGLE.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
