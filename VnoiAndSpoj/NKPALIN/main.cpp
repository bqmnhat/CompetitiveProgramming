#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000
using namespace std;
typedef pair<int, int> pii;
string s;
int n, dp[MaxN+5][MaxN+5];

//dp[i][j] = dp[i+1][j-1] + 2 or dp[i+1][j], dp[i][j-1]

void CalDp() {
    n = s.length();
    for (int i=n; i>=1; i--) {
        for (int j=i; j<=n; j++) {
            if (i == j) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i+1][j-1];
            if (s[i-1] == s[j-1])
                dp[i][j] = dp[i+1][j-1] + 2;
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
}

void Solve() {
    CalDp();
    int i = 1, j = n;
    vector<char> res;
    while (i < j) {
        if (s[i-1] == s[j-1]) {
            res.push_back(s[j-1]);
            i++;
            j--;
        }
        else if (dp[i][j] == dp[i+1][j-1]) {
            i++;
            j--;
        }
        else if (dp[i+1][j] > dp[i][j-1])
            i++;
        else
            j--;
    }
    for (char c: res)
        cout << c;
    if (i == j)
        cout << s[i-1];
    reverse(res.begin(), res.end());
    for (char c: res)
        cout << c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    Solve();
    return 0;
}
