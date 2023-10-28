#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, c[21], a[21];

int LCS(int c[], int a[]) {
    int dp[21][21] = {};
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (c[i] == a[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}

void Solve() {
    string s;
    cin >> n;
    cin.ignore();
    while (n != 0) {
        getline(cin, s);
        stringstream ss(s);
        for (int i=1; i<=n; i++) {
            int tmp;
            ss >> tmp;
            c[tmp] = i;
        }
        while (true) {
            bool flag = false;
            if (!getline(cin, s)) {
                n = 0;
                break;
            }
            stringstream ss(s);
            for (int i=1; i<=n; i++) {
                int tmp;
                if (!(ss >> tmp)) {
                    n = tmp;
                    flag = true;
                    break;
                }
                a[tmp] = i;
            }
            if (flag)
                break;
            cout << LCS(c, a) << '\n';
        }
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
