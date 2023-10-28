#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[6] = {0, 1, 5, 10, 25, 50}, n;
vector<long long> dp(7490, 0);

void MakeDP() {
    dp[0] = 1;
    for (int i=1; i<=5; i++)
        for (int j=a[i]; j<=7489; j++)
            dp[j] += dp[j-a[i]];
}

void Solve() {
    while (cin >> n)
        cout << dp[n] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeDP();
    Solve();
    return 0;
}
