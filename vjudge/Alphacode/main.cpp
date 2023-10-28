#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5005
using namespace std;
typedef long long ll;
ll dp[MaxN+1];
string s;

bool IsChar(char c1, char c2) {
    int a = c1 - '0', b = c2 - '0';
    return (((a*10 + b) >= 1) && ((a*10 + b) <= 26));
}

ll Solution() {
    int len = s.length();
    memset(dp, 0, sizeof(dp));
    dp[len] = 1;
    for (int i=len-1; i>=0; i--) {
        if (s[i] == '0')
            continue;
        dp[i] += dp[i+1];
        if ((i <= len-2) && (IsChar(s[i], s[i+1])))
            dp[i] += dp[i+2];
    }
    return dp[0];
}

void Solve() {
    while ((cin >> s) && (s != "0"))
        cout << Solution() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
