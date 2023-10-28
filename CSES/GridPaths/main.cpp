#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
int n;
ll dp[MaxN+5][MaxN+5];
string s[MaxN+5];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> s[i];
}

int Solution() {
    if (s[0][0] == '.')
        dp[0][0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if ((i == 0) && (j == 0))
                continue;
            if (s[i][j] == '*')
                continue;
            if ((i-1 >= 0) && (s[i-1][j] == '.'))
                dp[i][j] = (dp[i][j] + dp[i-1][j])%Mod;
            if ((j-1 >= 0) && (s[i][j-1] == '.'))
                dp[i][j] = (dp[i][j] + dp[i][j-1])%Mod;
        }
    }
    return dp[n-1][n-1];
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
