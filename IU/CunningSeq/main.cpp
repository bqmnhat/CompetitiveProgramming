#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef long long ll;
int n;
ll dp[MaxN+1];

ll Solution() {
    dp[0] = dp[1] = 1;
    for (int i=2; i<=n; i++) {
        if (i%2)
            dp[i] = dp[i-1] - dp[(i-1)/2];
        else
            dp[i] = dp[i/2] + 1;
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cout << Solution();
    return 0;
}
