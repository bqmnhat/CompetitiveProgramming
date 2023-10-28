#include <iostream>
#include <bits/stdc++.h>
#define MaxN 3000
using namespace std;
int n;
double p[MaxN+1], dp[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> p[i];
}

double Solution() {
    double ans = 0.0;
    dp[0] = 1;
    for (int i=1; i<=n; i++)
        for (int j=i; j>=0; j--)
            dp[j] = dp[j-1]*p[i] + dp[j]*(1.0-p[i]);
    for (int i=(n+1)/2; i<=n; i++)
        ans += dp[i];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << fixed << setprecision(9) << Solution();
    return 0;
}
