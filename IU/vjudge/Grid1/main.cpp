#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef long long ll;
string s[MaxN+1];
int h, w;
const ll Mod = 1e9 + 7;
ll dp[MaxN+1][MaxN+1];

void ReadData() {
    for (int i=1; i<=h; i++) {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }
}

ll Solution() {
    dp[1][1] = 1;
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
            if ((i == 1) && (j == 1))
                continue;
            if (s[i][j] == '#')
                continue;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%Mod;
        }
    }
    return dp[h][w];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> h >> w;
    ReadData();
    cout << Solution();
    return 0;
}
