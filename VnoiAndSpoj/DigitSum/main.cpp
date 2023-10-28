#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10005
#define MaxMod 105
using namespace std;
typedef long long ll;
string k;
ll dp[MaxN+1][MaxMod+1][2], d;
int n;
const ll Mod = 1e9 + 7;

ll Solution() {
    n = k.length();
    for (int i=0; i<=(k[0] - '0'); i++)
        dp[1][i%d][i == (k[0] - '0')] = 1;
    for (int i=1; i<n; i++) {
        for (int tight = 0; tight < 2; tight++) {
            for (int j=0; j<d; j++) {
                if (dp[i][j][tight] == 0)
                    continue;
                int limit = tight ? (k[i] - '0') : 9;
                for (int x = 0; x<=limit; x++)
                    dp[i+1][(j + x)%d][tight && x == limit] = (dp[i+1][(j + x)%d][tight && x == limit] + dp[i][j][tight])%Mod;
            }
        }
    }
    return (dp[n][0][0] + dp[n][0][1] - 1 + Mod)%Mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k >> d;
    cout << Solution();
    return 0;
}
