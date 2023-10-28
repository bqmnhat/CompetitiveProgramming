#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
#define MaxM 100
#define MaxK 500
using namespace std;
typedef long long ll;
int n, m, k;
ll dp[MaxM+5][MaxK+5], f[MaxM+5][MaxK+5], cntRoom[MaxM+5];

void ReadData() {
    for (int i=1; i<=n; i++) {
        int ai;
        cin >> ai;
        cntRoom[ai]++;
    }
}

void MakeF() {
    for (int i=1; i<=m; i++) {
        for (ll j=0; j<=k; j++) {
            ll tmp = cntRoom[i]/(j+1LL);
            ll y = cntRoom[i]%(j+1LL); // Number of groups that have tmp + 1 students
            ll x = (j+1LL) - y; // Number of groups that have tmp students
            f[i][j] = ((x*tmp*(tmp+1LL))>> 1LL) + ((y*(tmp+1LL)*(tmp+2LL))>> 1LL) ;
        }
    }
}

ll Solution() {
    for (int i=0; i<=k; i++)
        dp[1][i] = f[1][i];
    for (int i=2; i<=m; i++) {
        for (int j=0; j<=k; j++) {
            dp[i][j] = dp[i-1][j] + f[i][0];
            for (int c=1; c<=j; c++)
                dp[i][j] = min(dp[i][j], dp[i-1][j-c] + f[i][c]);
        }
    }
    return dp[m][k];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    ReadData();
    MakeF();
    cout << Solution();
    return 0;
}
