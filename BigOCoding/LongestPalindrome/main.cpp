#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T, ls, dp[1001][1001];
string s;

void InitDp() {
    for (int i=0; i<=ls; i++)
        for (int j=0; j<=ls; j++)
            dp[i][j] = 0;
}

int Solution() {
    string t = s;
    reverse(t.begin(), t.end());
    InitDp();
    for (int i=1; i<=ls; i++) {
        for (int j=1; j<=ls; j++) {
            if (s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[ls][ls];
}

void Solve() {
    for (int i=1; i<=T; i++) {
        cin >> s;
        ls = s.length();
        if ((ls == 1) && (s[0] = ' '))
            cout << "0\n";
        else
            cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    Solve();
    return 0;
}
