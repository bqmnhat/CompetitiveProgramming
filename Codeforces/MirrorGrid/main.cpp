#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
using namespace std;
int t, n, ma[2];
string a[MaxN+1];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> a[i];
}

int Solution() {
    int ans = 0;
    for (int i=0; i<n/2; i++) {
        for (int j=0; j < n/2; j++) {
            for (int i=0; i<2; i++)
                ma[i] = 0;
            ma[a[i][j] - '0']++;
            ma[a[j][n-1-i] - '0']++;
            ma[a[n-1-j][i] - '0']++;
            ma[a[n-1-i][n-1-j] - '0']++;
            int tmp = 8;
            for (int i=0; i<2; i++)
                tmp = min(tmp, ma[i]);
            ans += tmp;
        }
    }
    if (n%2 == 1) {
        for (int i=0; i < n/2; i++) {
            for (int i=0; i<2; i++)
                ma[i] = 0;
            ma[a[n/2][i] - '0']++;
            ma[a[n/2][n-1-i] - '0']++;
            ma[a[n-1-i][n/2] - '0']++;
            ma[a[i][n/2] - '0']++;
            int tmp = 8;
            for (int i=0; i<2; i++)
                tmp = min(tmp, ma[i]);
            ans += tmp;
        }
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        cout << Solution() << '\n';
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
