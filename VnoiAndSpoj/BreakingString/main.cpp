#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000
using namespace std;
int n, m, a[MaxN+1], pos[MaxN+1], dp[MaxN+1][MaxN+1], K[MaxN+1][MaxN+1], pref[MaxN+1];
const int INF = 1e9 + 7;

void ReadData() {
    for (int i=1; i<=m; i++)
        cin >> pos[i];
}

void SplitData() {
    pos[m+1] = n;
    for (int i=1; i<=m+1; i++) {
        a[i] = pos[i] - pos[i-1];
        pref[i] = pref[i-1] + a[i];
    }
}

int Solution() {
    m++;
    for (int i=1; i<=m; i++) {
        for (int j=i; j<=m; j++) {
            dp[i][j] = INF;
            K[i][j] = 0;
        }
    }
    for (int i=1; i<=m; i++) {
        dp[i][i] = 0;
        K[i][i] = i;
    }
    for (int i=m-1; i>=1; i--) {
        for (int j=i+1; j<=m; j++) {
            for (int k=K[i][j-1]; k<=K[i+1][j]; k++) {
                int NewCost = pref[j] - pref[i-1] + dp[i][k-1] + dp[k][j];
                if (NewCost <= dp[i][j]) {
                    dp[i][j] = NewCost;
                    K[i][j] = k;
                }
            }
        }
    }
    return dp[1][m];
}

void Solve() {
    while (cin >> n >> m) {
        ReadData();
        SplitData();
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
