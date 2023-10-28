#include <iostream>
#include <bits/stdc++.h>
#define MaxN 31
using namespace std;
typedef long long ll;
int n;
ll dp[MaxN+1] = {0, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504, 927, 1705, 3136, 5768, 10609, 19513, 35890, 66012, 121415, 223317, 410744, 755476, 1389537, 2555757, 4700770, 8646064, 15902591, 29249425, 53798080, 98950096};

ll Solution() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i=4; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cout << dp[n];
    return 0;
}
