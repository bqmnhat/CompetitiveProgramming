#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string X, Y;
int dp[5001][5001];

int Solution() {
    int lX = X.length(), lY = Y.length();
    for (int i=1; i<=lX; i++) {
        for (int j=1; j<=lY; j++) {
            if (X[i-1] == Y[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[lX][lY];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("33.INP", "r", stdin);
    freopen("33.OUT", "w", stdout);
    cin >> X >> Y;
    cout << Solution();
    return 0;
}
