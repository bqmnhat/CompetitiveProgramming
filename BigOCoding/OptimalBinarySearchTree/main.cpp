#include <iostream>
#include <bits/stdc++.h>
#define MaxN 255
using namespace std;
int n, f[MaxN+1], pref[MaxN+1], dp[MaxN+1][MaxN+1], K[MaxN+1][MaxN+1];
const int INF = 1e9 + 7;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> f[i];
        pref[i] = pref[i-1] + f[i];
    }
}

int Solution() {
    for (int i=1; i<=MaxN; i++) {
        for (int j=i; j<=MaxN; j++) {
            dp[i][j] = INF;
            K[i][j] = 0;
        }
    }
    for (int i=1; i<=n; i++) {
        dp[i][i] = 0;
        K[i][i] = i;
    }
    for (int i=n-1; i>=1; i--) {
        for (int j=i+1; j<=n; j++) {
            for (int k=K[i][j-1]; k<=K[i+1][j]; k++) {
                int NewCost = pref[j] - pref[i-1] + dp[i][k-1] + dp[k+1][j] - f[k];
                if (NewCost <= dp[i][j]) {
                    dp[i][j] = NewCost;
                    K[i][j] = k;
                }
            }
        }
    }
    return dp[1][n];
}

void Solve() {
    while (cin >> n) {
        ReadData();
        cout << Solution() << '\n';
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
