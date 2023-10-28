#include <iostream>
#include <bits/stdc++.h>
#define MaxN 21
using namespace std;
typedef long long ll;
int n, a[MaxN+1][MaxN+1], dp[MaxN+1][(1 << MaxN)];
const ll Mod = 1e9 + 7;

void ReadData() {
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];
}

ll Solution() {
    dp[0][0] = 1;
    for (int i=0; i<n; i++)
        for (int mask = 0; mask < (1 << n); mask++)
            if (i == __builtin_popcount(mask))
                for (int j=0; j<n; j++)
                    if ((a[i][j]) && (!(mask&(1 << j))))
                        dp[i+1][mask | (1 << j)] = (dp[i+1][mask | (1 << j)] + dp[i][mask])%Mod;
    return (dp[n][(1 << n) - 1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
