#include <iostream>
#include <bits/stdc++.h>
#define MaxN 35
using namespace std;
typedef long long ll;
int n, h;
ll dp[MaxN+5][MaxN+5];// dp[i][j]: number of binsearch trees formed from nodes from 1->i and height <=j

ll Solution() {
    for (int i=0; i<=n; i++)
        dp[0][i] = 1;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            for (int k=0; k<i; k++)
                dp[i][j] += (dp[k][j-1]*dp[i-k-1][j-1]);
    return (dp[n][n] - dp[n][h-1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> h;
    cout << Solution();
    return 0;
}
