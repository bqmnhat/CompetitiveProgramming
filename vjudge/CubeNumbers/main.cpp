#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
#define MaxJ 50
using namespace std;
typedef long long ll;
int n;
ll dp[MaxN+1];

void CalculateDp() {
    dp[1] = 1;
    for (int i=2; i<=MaxN; i++) {
        dp[i]= 1e9;
        for (int j=1; j<=MaxJ; j++)
            if (i - j*j*j >= 0)
                dp[i] = min(dp[i - j*j*j] + 1, dp[i]);
    }
}

void Solve() {
    int cnt = 0;
    while (cin >> n) {
        cnt++;
        cout << "Case #" << cnt << ": " << dp[n] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    CalculateDp();
    Solve();
    return 0;
}
