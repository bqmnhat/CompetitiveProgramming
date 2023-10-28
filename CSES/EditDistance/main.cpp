#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000
using namespace std;
int t, dp[MaxN+1][MaxN+1];
string A, B;

int Solution() {
    dp[0][0] = 0;
    int lenA = A.length(), lenB = B.length();
    for (int i=0; i<=lenA; i++) {
        for (int j=0; j<=lenB; j++) {
            if ((i == 0) && (j == 0))
                continue;
            dp[i][j] = 1e9;
            if ((i > 0) && (j > 0) && (A[i-1] == B[j-1]))
                dp[i][j] = dp[i-1][j-1];
            else {
                if ((i > 0) && (j > 0))
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
                if (i > 0)
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                if (j > 0)
                    dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            }
        }
    }
    return dp[lenA][lenB];
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
