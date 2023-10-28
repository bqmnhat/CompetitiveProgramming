#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000
using namespace std;
string A, B;
int dp[MaxN+5][MaxN+5];

int Solution() {
    int n = A.length(), m = B.length();
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (A[i-1] == B[j-1])
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][m];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B;
    cout << Solution();
    return 0;
}
