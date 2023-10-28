#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s,t;
int dp[2001][2001];

int Solution() {
    int ls = s.length(), lt = t.length();
    for (int i=1; i<=ls; i++) {
        for (int j = 1; j<=lt; j++) {
            if (s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[ls][lt];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> t;
    cout << Solution();
    return 0;
}
