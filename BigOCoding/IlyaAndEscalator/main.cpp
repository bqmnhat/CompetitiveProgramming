#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000
using namespace std;
int n, t;
double p, dp[MaxN+1][MaxN+1]; // dp[i][j] la xac suat co i nguoi tren thang may tai thoi diem j

double Solution() {
    dp[0][0] = 1;
    for (int i = 0; i<=n; i++) {
        for (int j=1; j<=t; j++) {
            if (i > 0)
                dp[i][j] = dp[i-1][j-1]*p;
            if (i < n) // van con nguoi dung cho thang may
                dp[i][j] += dp[i][j-1]*(1.00-p);
        }
    }
    double ans = 0;
    for (int i=1; i<=n; i++)
        ans += dp[i][t]*i;
    for (int i=1; i<t; i++)
        ans += dp[n][i]*n;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p >> t;
    cout << setprecision(6) << fixed << Solution();
    return 0;
}
